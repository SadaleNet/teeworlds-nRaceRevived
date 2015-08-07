/* copyright (c) 2008 rajh and gregwar. Score stuff */

#ifndef SCORE_H_RACE
#define SCORE_H_RACE
#include <engine/shared/protocol.h>
class IGameController;

class PlayerScore
{
public:
	char m_Name[MAX_NAME_LENGTH];
	float m_Score, m_Diff;
	int m_PosX, m_PosY;
	char m_Ip[256];
	float m_CpTime[95];

	PlayerScore(const char *name, float score, const char *ip, float cp_time[95], int pos_x, int pos_y, float diff);

	bool operator==(const PlayerScore& other) { return (this->m_Score == other.m_Score); }
	bool operator<(const PlayerScore& other) { return (this->m_Score < other.m_Score); }
};

class Score
{
	IGameController* m_GameController;
public:
	Score(IGameController* gameController);
	
	void Save();
	void Load();
	PlayerScore *SearchScore(int id, bool score_ip, int *position);
	PlayerScore *SearchName(const char *name, int *position, bool match_case);
	void ParsePlayer(int id, float score, float cp_time[95], int x, int y, float diff);
	void InitPlayer(int id);
	void Top5Draw(int id, int debut);

	void WlistParsePlayer(int id, int x, int y, int diff);
};

#endif
