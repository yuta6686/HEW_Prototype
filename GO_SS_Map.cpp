#include "GO_SS_Map.h"
#include "GO_SS_FileLoad.h"
#include "GO_SS_Wall.h"

void GO_SS_Map::Initialize(void)
{
	p_MapData = m_pFileLoad->MapFileLoad();

}

void GO_SS_Map::Finalize(void)
{
}

void GO_SS_Map::Update(void)
{

}

void GO_SS_Map::Draw(void)
{
	//•Ç•`‰æ
	for (int y = 0; y < WALL_NUM_Y; y++)
	{
		for (int x = 0; x < WALL_NUM_X; x++)
		{
			m_pWall->SetWall(D3DXVECTOR2(WALL_WIDTH * x, WALL_HEIGHT * y));
		}
	}
}