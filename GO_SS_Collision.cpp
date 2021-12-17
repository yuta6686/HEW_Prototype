#include "GO_SS_Collision.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include "GO_SS_Target.h"
#include "GO_SS_Wall.h"
#include "GO_SS_Goal.h"
#include "game.h"
#include "main.h"
#include "input.h"
#include "fade.h"



void GO_SS_Collision::CollisionUpdate(void)
{
	playerPos = m_pPlayer->GetPos();
	playerSize = m_pPlayer->GetSize();

	m_pPlayer->IsCollSide = CJ_PWSide();

	Goal_Vertex = m_pGoal->GetGoal();

	//プレイヤーと壁の衝突処理
	if (CJ_PlayerWall() >= 0)m_pPlayer->IsColl = true;
	else m_pPlayer->IsColl = false;

	CJ_GoalPlayer();

	//DebugOut();

}

// ----------------------------------------------------------------
//						プレイヤーと壁
// ----------------------------------------------------------------
//	戻値：	あたっていたら、その壁のインデックスを。
//			あたっていなかったら、-1を返す
// ----------------------------------------------------------------
int GO_SS_Collision::CJ_PlayerWall(void)
{
	for (int i = 0; i < m_pWall->GetWallNumMax(); i++) {
		VERTEX_WALL vwall = m_pWall->GetvWall(i);
		if (!vwall.use)continue;
		if (BBCollision_LeftTop2(m_pPlayer->GetPos(), m_pPlayer->GetSize(), vwall.pos, vwall.size)) {
			return i;
		}
	}
	return -1;
}

//プレイヤーの横と壁
//戻り値 -1:当たってない　1:左 2:右
int GO_SS_Collision::CJ_PWSide(void)
{
	for (int i = 0; i < m_pWall->GetWallNumMax(); i++) 
	{
		VERTEX_WALL vwall = m_pWall->GetvWall(i);
		if (!vwall.use)continue;
		//左
		if (BBCollision_LeftTop2(D3DXVECTOR2(playerPos.x, playerPos.y * 0.8f), D3DXVECTOR2(playerSize.x, playerSize.y), vwall.pos, vwall.size))
		{
			return 1;
		}
		//右
		if (BBCollision_LeftTop2(D3DXVECTOR2(playerPos.x + playerSize.x * 0.5f, playerPos.y * 0.8f), D3DXVECTOR2(playerSize.x * 0.1f, playerSize.y), vwall.pos, vwall.size))
		{
			return 2;
		}
	}
	return -1;
}

bool GO_SS_Collision::BBCollision(D3DXVECTOR2 pos1, D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2)
{
	D3DXVECTOR2 min1, max1;
	D3DXVECTOR2 min2, max2;

	min1.x = pos1.x - size1.x / 2;
	min1.y = pos1.y - size1.y / 2;
	max1.x = pos1.x + size1.x / 2;
	max1.y = pos1.y + size1.y / 2;

	min2.x = pos2.x - size2.x / 2;
	min2.y = pos2.y - size2.y / 2;
	max2.x = pos2.x + size2.x / 2;
	max2.y = pos2.y + size2.y / 2;

	//X軸の判定
	if (min1.x < max2.x && max1.x > min2.x)
	{
		//Y軸の判定
		if (min1.y < max2.y && max1.y > min2.y)
		{
			//全ての条件がTRUEならヒット判定
			return true;
		}
	}
	return false;
}

bool GO_SS_Collision::BBCollision_LeftTop2(D3DXVECTOR2 pos1, D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2)
{
	D3DXVECTOR2 min1, max1;
	D3DXVECTOR2 min2, max2;

	min1.x = pos1.x - size1.x / 2;
	min1.y = pos1.y - size1.y / 2;
	max1.x = pos1.x + size1.x / 2;
	max1.y = pos1.y + size1.y / 2;

	min2.x = pos2.x;
	min2.y = pos2.y;
	max2.x = pos2.x + size2.x;
	max2.y = pos2.y + size2.y;

	//X軸の判定
	if (min1.x < max2.x && max1.x > min2.x)
	{
		//Y軸の判定
		if (min1.y < max2.y && max1.y > min2.y)
		{
			//全ての条件がTRUEならヒット判定
			return true;
		}
	}
	return false;
}

void GO_SS_Collision::DebugOut(void)
{
#ifdef _DEBUG	// デバッグ版の時だけAngleを表示する
	wsprintf(GetDebugStr(), WINDOW_CAPTION);
	wsprintf(&GetDebugStr()[strlen(GetDebugStr())], " IsCollSide:%d",
		m_pPlayer->IsCollSide);

	SetWindowText(GethWnd()[0], GetDebugStr());
#endif
}

void GO_SS_Collision::CJ_GoalPlayer(void)
{
	if (BBCollision_LeftTop2(m_pPlayer->GetPos(), m_pPlayer->GetSize(), Goal_Vertex.pos, Goal_Vertex.size))
	{
		SceneTransition(SCENE_RESULT);
	}
}