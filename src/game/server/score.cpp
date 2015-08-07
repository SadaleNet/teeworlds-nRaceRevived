/* copyright (c) 2008 rajh and gregwar. Score stuff */

#include "score.h"
#include "gamecontext.h"
#include <string.h>
#include <sstream>
#include <fstream>
#include <list>
#include <game/server/entity.h>
#include <game/server/gamecontroller.h>
#include <engine/shared/config.h>
#include <engine/shared/protocol.h>

static LOCK score_lock = 0;

PlayerScore::PlayerScore(const char *name, float score, const char *ip, float cp_time[95], int pos_x, int pos_y, float diff)
{
	str_copy(this->m_Name, name, sizeof(this->m_Name));
	this->m_Score = score;
	str_copy(this->m_Ip, ip, sizeof(this->m_Ip));

	for(int i = 0; i < 95; i++)
		this->m_CpTime[i] = cp_time[i];

	this->m_PosX = pos_x;
	this->m_PosY = pos_y;
	this->m_Diff = diff;
}

std::list<PlayerScore> top;

Score::Score(IGameController* gameController){
	m_GameController = gameController;
	if(score_lock == 0)
		score_lock = lock_create();
	Load();
}

std::string save_file()
{
	std::ostringstream oss;
	oss << g_Config.m_SvMap << "_record.nxt";
	return oss.str();
}

static void save_score_thread(void *)
{
	lock_wait(score_lock);
	std::fstream f;
	f.open(save_file().c_str(), std::ios::out);
	if(!f.fail())
	{
		int t = 0;
		for(std::list<PlayerScore>::iterator i = top.begin(); i != top.end(); i++)
		{
			f << i->m_Name << std::endl << i->m_Score << std::endl  << i->m_Ip << std::endl << i->m_PosX << std::endl << i->m_PosY << std::endl << i->m_Diff << std::endl;
			if(g_Config.m_SvCheckpointSave)
			{
				for(int c = 0; c < 78; c++)
					f << i->m_CpTime[c+17] << " ";
				f << std::endl;
			}
			t++;
			if(t%50 == 0)
				thread_sleep(1);
		}
	}
	f.close();
	lock_release(score_lock);
}

void Score::Save()
{
	void *save_thread = thread_create(save_score_thread, 0);
#if defined(CONF_FAMILY_UNIX)
	pthread_detach((pthread_t)save_thread);
#endif
}

void Score::Load()
{
	lock_wait(score_lock);
	std::fstream f;
	f.open(save_file().c_str(), std::ios::in);
	top.clear();
	while (!f.eof() && !f.fail())
	{
		std::string tmpname, tmpscore, tmpip, tmpx, tmpy, tmpdiff, tmpcpline;
		std::getline(f, tmpname);
		if(!f.eof() && tmpname != "")
		{
			std::getline(f, tmpscore);
			std::getline(f, tmpip);
			std::getline(f, tmpx);
			std::getline(f, tmpy);
			std::getline(f, tmpdiff);

			float tmpcptime[95] = {0};
			if(g_Config.m_SvCheckpointSave)
			{
				std::getline(f, tmpcpline);
				if(tmpcpline.length() < 156)
					continue;

				char *time = strtok((char*)tmpcpline.c_str(), " ");
				int i = 0;
				while(time != NULL && i < 78)
				{
					tmpcptime[i+17] = atof(time);
					time = strtok(NULL, " ");
					i++;
				}
			}
			top.push_back(*new PlayerScore(tmpname.c_str(), atof(tmpscore.c_str()), tmpip.c_str(), tmpcptime, atoi(tmpx.c_str()), atoi(tmpy.c_str()), atof(tmpdiff.c_str())));
		}
	}
	f.close();
	lock_release(score_lock);
}

PlayerScore *Score::SearchScore(int id, bool score_ip, int *position)
{
	char ip[256];
	m_GameController->Server()->GetClientAddr(id, ip, sizeof(ip));
	
	int pos = 1;
	for(std::list<PlayerScore>::iterator i = top.begin(); i != top.end(); i++)
	{
		if(!strcmp(i->m_Ip, ip) && g_Config.m_SvScoreIp && score_ip)
		{
			if(position)
				*position = pos;
			return & (*i);
		}
		if(i->m_Score != -1)
			pos++;
	}
	
	return SearchName(m_GameController->Server()->ClientName(id), position, 0);
}

PlayerScore *Score::SearchName(const char *name, int *position, bool nocase)
{
	PlayerScore *player = 0;
	int pos = 1;
	int found = 0;
	for (std::list<PlayerScore>::iterator i = top.begin(); i != top.end(); i++)
	{
		if(str_find_nocase(i->m_Name, name))
		{
			if(position)
				*position = pos;
			if(nocase)
			{
				found++;
				player = & (*i);
			}
			if(!strcmp(i->m_Name, name))
				return & (*i);
		}
		if(i->m_Score != -1)
			pos++;
	}
	if(found > 1)
	{
		if(position)
			*position = -1;
		return 0;
	}
	return player;
}

void Score::ParsePlayer(int id, float score, float cp_time[95], int x, int y, float diff)
{
	const char *name = m_GameController->Server()->ClientName(id);
	char ip[256];
	m_GameController->Server()->GetClientAddr(id, ip, sizeof(ip));
	
	lock_wait(score_lock);
	PlayerScore *player = SearchScore(id, 1, 0);
	if(player)
	{
		for(int c = 0; c < 95; c++)
		{
			if(player->m_CpTime[c] == 0 || player->m_Score > score)
				player->m_CpTime[c] = cp_time[c];
		}
		if(player->m_Score > score || player->m_Score == -1)
		{
			player->m_Score = score;
			str_copy(player->m_Name, name, sizeof(player->m_Name));
		}
	}
	else
		top.push_back(*new PlayerScore(name, score, ip, cp_time, x, y, diff));
	
	top.sort();
	lock_release(score_lock);
	Save();
}

void Score::WlistParsePlayer(int id, int x, int y, int diff)
{
	float empty_cp[95] = {0};
	const char *name = m_GameController->Server()->ClientName(id);
	char ip[256];
	m_GameController->Server()->GetClientAddr(id, ip, sizeof(ip));
	
	lock_wait(score_lock);
	PlayerScore *player = SearchScore(id, 1, 0);
	if(player)
	{
		player->m_PosX = x;
		player->m_PosY = y;
		player->m_Diff = diff;
	}
	else
		top.push_back(*new PlayerScore(name, -1, ip, empty_cp, x, y, diff));

	top.sort();
	lock_release(score_lock);
	Save();
}

void Score::InitPlayer(int id)
{
	char ip[256];
	m_GameController->Server()->GetClientAddr(id, ip, sizeof(ip));
	PlayerScore *player = SearchScore(id, 0, 0);
	if(player)
	{
		lock_wait(score_lock);
		str_copy(player->m_Ip, ip, sizeof(player->m_Ip));
		lock_release(score_lock);
		Save();
	}
}

void Score::Top5Draw(int id, int debut)
{
	int pos = 1;
	char buf[512];
	m_GameController->GameServer()->SendChatTarget(id, "----------- Top 5 -----------");
	for (std::list<PlayerScore>::iterator i = top.begin(); i != top.end() && pos <= 5+debut; i++)
	{
		if(i->m_Score < 0)
			continue;

		if(pos >= debut)
		{
			std::ostringstream oss;
			oss << pos << ". " << i->m_Name << " Time: ";

			if ((int)(i->m_Score)/60 != 0)
				oss << (int)(i->m_Score)/60 << " minute(s) ";
			if (i->m_Score-((int)i->m_Score/60)*60 != 0)
				oss << i->m_Score-((int)i->m_Score/60)*60 <<" second(s)";

			m_GameController->GameServer()->SendChatTarget(id, oss.str().c_str());
		}
		pos++;
	}
	m_GameController->GameServer()->SendChatTarget(id, "-----------------------------");
}
