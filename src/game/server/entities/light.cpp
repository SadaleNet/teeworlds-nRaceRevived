/* copyright (c) 2007 magnus auvinen, see licence.txt for more info */
#include <engine/shared/config.h>
#include <game/generated/protocol.h>
#include <game/server/gamecontext.h>
#include "light.h"

CLight::CLight(CGameWorld *pGameWorld, vec2 From, vec2 To, int Team)
: CEntity(pGameWorld, CGameWorld::ENTTYPE_INVALID)
{
	this->m_From = From;
	this->m_To = To;
	this->m_Visible = true;
	this->m_Team = Team;
	m_KeepPoints = false;
	this->m_ID2 = Server()->SnapNewID();
	GameWorld()->InsertEntity(this);
}

	
void CLight::Reset()
{
	GameServer()->m_World.DestroyEntity(this);
}

void CLight::Tick()
{
	return;

}

void CLight::Snap(int SnappingClient)
{
	if(!this->m_Visible && !m_KeepPoints)
		return;

	CNetObj_Laser *pObj = static_cast<CNetObj_Laser *>(Server()->SnapNewItem(NETOBJTYPE_LASER, m_ID, sizeof(CNetObj_Laser)));
	pObj->m_X = (int)m_From.x;
	pObj->m_Y = (int)m_From.y;	
	pObj->m_FromX = (int)m_To.x;
	pObj->m_FromY = (int)m_To.y;
	if(this->m_Team == -1)
		pObj->m_StartTick = Server()->Tick()-2;
	else if (GameServer()->m_apPlayers[SnappingClient]->GetTeam() == this->m_Team)
		pObj->m_StartTick = Server()->Tick()-4;
	else
		pObj->m_StartTick = Server()->Tick();
	CNetObj_Laser *pObj2 = static_cast<CNetObj_Laser *>(Server()->SnapNewItem(NETOBJTYPE_LASER, m_ID2, sizeof(CNetObj_Laser)));
	pObj2->m_X = pObj->m_FromX;
	pObj2->m_Y = pObj->m_FromY;
	pObj2->m_FromX= pObj->m_X;
	pObj2->m_FromY = pObj->m_Y;
	pObj2->m_StartTick = pObj->m_StartTick;
	
	if(!m_Visible) {
		pObj->m_X = pObj->m_FromX;
		pObj->m_Y = pObj->m_FromY;
		pObj2->m_X = pObj2->m_FromX;
		pObj2->m_Y = pObj2->m_FromY;
	}
}
