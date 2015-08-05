/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include <base/vmath.h>
#include <vector>
#include <stdlib.h>

class CCollision
{
public:
	enum
	{
		COLID_DEATH=2,
		COLID_WATER_BEGIN=4,
		COLID_WATER=COLID_WATER_BEGIN,
		COLID_WATER_UP,
		COLID_WATER_DOWN,
		COLID_WATER_LEFT,
		COLID_WATER_RIGHT,
		COLID_WATER_END=COLID_WATER_RIGHT,
		COLID_BOOSTDOWN=27,
		COLID_BOOSTV,
		COLID_BOOSTLEFT,
		COLID_BOOSTRIGHT,
		COLID_BOOSTH,
		COLID_BOOSTUP,
		COLID_RACE_START=33,
		COLID_RACE_END,
		COLID_TELEPORT_BEGIN=35,
		COLID_TELEPORT_END=190,
	};
private:
	class CTile *m_pTiles;
	int* m_TileId;
	int m_Width;
	int m_Height;
	std::vector<vec2> m_teleportDest[(COLID_TELEPORT_END-COLID_TELEPORT_BEGIN+1)/2];
	class CLayers *m_pLayers;

	bool IsTileSolid(int x, int y);
	int GetTile(int x, int y);
	int GetTileId(int x, int y);

public:
	enum
	{
		COLFLAG_SOLID=1,
		COLFLAG_DEATH=2,
		COLFLAG_NOHOOK=4,
	};
	CCollision();
	void Init(class CLayers *pLayers);
	bool CheckPoint(float x, float y) { return IsTileSolid(round(x), round(y)); }
	bool CheckPoint(vec2 Pos) { return CheckPoint(Pos.x, Pos.y); }
	int GetCollisionAt(float x, float y) { return GetTile(round(x), round(y)); }
	int GetCollisionIdAt(float x, float y) { return GetTileId(round(x), round(y)); }
	vec2 GetTeleportDestination(int teleportId) { return m_teleportDest[teleportId].empty() ? vec2(0,0) : m_teleportDest[teleportId][rand()%m_teleportDest[teleportId].size()]; }
	bool IsCheckpoint(int teleportId) { return m_teleportDest[teleportId].empty(); }
	int GetWidth() { return m_Width; };
	int GetHeight() { return m_Height; };
	int IntersectLine(vec2 Pos0, vec2 Pos1, vec2 *pOutCollision, vec2 *pOutBeforeCollision);
	void MovePoint(vec2 *pInoutPos, vec2 *pInoutVel, float Elasticity, int *pBounces);
	void MoveBox(vec2 *pInoutPos, vec2 *pInoutVel, vec2 Size, float Elasticity);
	bool TestBox(vec2 Pos, vec2 Size);
};

#endif
