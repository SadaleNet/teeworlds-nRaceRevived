/* copyright (c) 2007 magnus auvinen, see licence.txt for more info */

#ifndef GAME_SERVER_ENTITY_LIGHT_H
#define GAME_SERVER_ENTITY_LIGHT_H

#include <game/server/entity.h>

class CHARACTER;

class CLight : public CEntity
{
	vec2 m_From;
	vec2 m_To;
	int m_ID2;

public:
	
	bool m_Visible;
	bool m_KeepPoints;
	int m_Width;
	CLight(CGameWorld *pGameWorld, vec2 From, vec2 To);
	
	virtual void Reset();
	virtual void Tick();
	virtual void Snap(int snapping_client);
};

#endif
