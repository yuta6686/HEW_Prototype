#include "GO_SS_Map.h"
#include "GO_SS_FileLoad.h"
#include "GO_SS_Wall.h"
#include "GO_SS_Target.h"
//#include "GO_SS_ZipLine.h"

//#define SEEK_ZIP_MAX  5

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

	//マップ描画
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
			case ZIPLINE_A_NUM:
				//ZIPLINE_A_NUMが来たらBを探しに行く
				//if (SeekZipLineB(x, y))
				{
					//m_pZipLine->SetZipLine(D3DXVECTOR2(WALL_WIDTH * x, WALL_HEIGHT * y));
				}
				break;
			}
		}
	}
}

void GO_SS_Map::Draw(void)
{
	
}
//
////ziplineのBを探しに行く関数
//bool GO_SS_Map::SeekZipLineB(int CurrentNumX, int CurrentNumY)
//{
//	int y = CurrentNumY - SEEK_ZIP_MAX;
//	if (y <= 0)	y = 0;
//
//	for (y = CurrentNumY - SEEK_ZIP_MAX; y < CurrentNumY + SEEK_ZIP_MAX; y++)
//	{
//		for (int x = CurrentNumX + 1; x < CurrentNumX + SEEK_ZIP_MAX; x++)
//		{
//			if (MapData[y][x] == ZIPLINE_B_NUM)
//			{
//				m_pZipLine->LinkZipLineB(D3DXVECTOR2(WALL_WIDTH * x, WALL_HEIGHT * y), x - CurrentNumX);
//				return true;
//			}
//		}
//	}
//	return false;
//}