#include "GO_SS_Map.h"
#include "GO_SS_FileLoad.h"
#include "GO_SS_Wall.h"
#include "GO_SS_Target.h"

void GO_SS_Map::Initialize(void)
{
	m_pFileLoad->MapFileLoad(MapData);

	once = true;
}

void GO_SS_Map::Finalize(void)
{
}

void GO_SS_Map::Update(void)
{
	if (once == false)return;
	once = false;

	//ƒ}ƒbƒv•`‰æ
	for (int y = 0; y < STAGE_WALL_NUM_Y; y++)
	{
		for (int x = 0; x < STAGE_WALL_NUM_X; x++)
		{
			switch (MapData[y][x])
			{
			case WALL_NUM:
				m_pWall->SetWall(D3DXVECTOR2(WALL_WIDTH * x, WALL_HEIGHT * y), D3DXVECTOR2(WALL_WIDTH, WALL_HEIGHT));
				break;
			case TARGET_NUM:
				m_pTarget->SetTarget(D3DXVECTOR2(WALL_WIDTH * x, WALL_HEIGHT * y));
				break;
			}
		}
	}
}

void GO_SS_Map::Draw(void)
{
	
}