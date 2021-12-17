#include "GO_SS_Map.h"
#include "GO_SS_FileLoad.h"
#include "GO_SS_Wall.h"
#include "GO_SS_Target.h"
#include "GO_SS_Fan.h"
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

	//?}?b?v?`??
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

			case FAN_A_NUM:
				m_pFan->SetFan(D3DXVECTOR2(WALL_WIDTH * x, WALL_HEIGHT * y));
				break;

			case FAN_B_NUM:
				break;

			//case ZIPLINE_A_NUM:
			//	//ZIPLINE_A_NUM‚ª—ˆ‚½‚çB‚ğ’T‚µ‚És‚­
			//	if (SeekZipLineB(x, y))
			//	{
			//		m_pZipLine->SetZipLine(D3DXVECTOR2(WALL_WIDTH * x, WALL_HEIGHT * y));
			//	}
			//	break;
			}
		}
	}
}

void GO_SS_Map::Draw(void)
{
	
}
void GO_SS_Map::MoveMapObject(FLOAT x)
{
	m_pWall->AddX(x);
	m_pTarget->AddPosX(x);
	m_pFan->AddX(x);
}

void GO_SS_Map::ResetOnce(void)
{
	m_pTarget->ResetOnce();
	m_pWall->ResetOnce();
	m_pFan->ResetOnce();
	once = true;
}

//
////zipline‚ÌB‚ğ’T‚µ‚És‚­ŠÖ”
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