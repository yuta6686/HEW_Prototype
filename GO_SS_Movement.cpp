#include "GO_SS_Movement.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include "GO_SS_Target.h"
#include "GO_SS_Wall.h"
#include "GO_SS_Map.h"

#include <cmath>

void GO_SS_Movement::Update(void)
{

	/*	プライヤーの挙動	-> 切り替え(PlayerMove　index)
		PLAYERMOVE_LINEAR,
		PLAYERMOVE_CURVE,	
		PLAYERMOVE_PENDULUM,
	*/
	PlayerMoveSwitch(PLAYERMOVE_LINEAR);
	
	//当たり判定の更新処理
	m_ssCollision.CollisionUpdate();
	
	//奈落からの復活
	FromAbyss();
}


//-----------------------------------------------------------------------------------------
//	JumpMove_Liner()
//-----------------------------------------------------------------------------------------
//	直線的な動き
//	ターゲットまで直で向かう
//-----------------------------------------------------------------------------------------
void GO_SS_Movement::JumpMove_Liner()
{
	//糸を出したら
	if (!m_pShotString->IsClickTarget)return;
	//if (!m_pShotString->IsCollTarget)return;

	//重力リセット
	m_pPlayer->SetGravityDefault();

	//プレイヤーと糸の角度取得
	FLOAT angle = m_pShotString->GetAngle();

	//プレイヤーのY軸　動き　
	m_pPlayer->AddYPos(-sinf(angle) * 25.0f);

	//背景スクロール処理
	m_pBackGround->SubU(cosf(angle)/100.0f);


	m_pWall->AddX(-10.0f);

	m_pTarget->AddPosX(-10.0f);
}

//-----------------------------------------------------------------------------------------
//	JumpMove_Curve()
//-----------------------------------------------------------------------------------------
//	プロトタイプのときの動き
//-----------------------------------------------------------------------------------------
void GO_SS_Movement::JumpMove_Curve()
{
	//糸を出したら
	if (!m_pShotString->IsClickTarget)return;

	//カウンターが上限に達したら
	if (JumpCounter >= JumpCountMax) {
		//重力リセット
		m_pPlayer->SetGravityDefault();

		//ショットストリングのクリックフラグ下ろす
		m_pShotString->IsClickTarget = false;

		//ジャンプカウンターリセット
		JumpCounter = 0;
	}
	else {
		//背景スクロール処理
		m_pBackGround->SubU(cosf(m_pShotString->GetAngle()) / 100.0f);


		m_pWall->AddX(cosf(m_pShotString->GetAngle())*10.0f);

		FLOAT angle = m_pShotString->GetAngle() * (FLOAT)180.0f / (FLOAT)PI;

		//プライヤーの動き調整
		//		  90
		//				
		//	0			↑180,↓-180
		//				
		//		 -90
		//これの右か左かを判定
		if (angle >= 90 && angle < 180
			|| angle >= -180 && angle < -90) {

			m_pPlayer->WavePosPlus((float)(JumpCounter)*RADIAN);
		}
		else {
			m_pPlayer->WavePosMinus((float)(JumpCounter) * RADIAN );
		}
		

	
		//カウンター
		JumpCounter++;
	}

	//ジャンプ中の最初の1回だけ
	if (JumpCounter <= 1) {

		//ジャンプのフレーム数調整
		JumpCountMax = (int)(fabs(cosf(m_pShotString->GetAngle())* 60.0f));
	}
}

//-----------------------------------------------------------------------------------------
//	JumpMove_Pendulum()
//-----------------------------------------------------------------------------------------
//	振り子のような動き
//	下に動いてから、上に上がる
//-----------------------------------------------------------------------------------------
void GO_SS_Movement::JumpMove_Pendulum()
{
}

void GO_SS_Movement::PlayerMoveSwitch(PlayerMove index)
{
	//プライヤーの動きー＞切り替え可能
	switch (index)
	{
	case PLAYERMOVE_NONE:
		break;
	case PLAYERMOVE_LINEAR:
		JumpMove_Liner();
		break;
	case PLAYERMOVE_CURVE:
		JumpMove_Curve();
		break;
	case PLAYERMOVE_PENDULUM:
		JumpMove_Pendulum();
		break;
	case PLAYERMOVE_MAX:
		break;
	default:
		break;
	}
}

void GO_SS_Movement::FromAbyss()
{
	if (m_pPlayer->GetPos().y >= SCREEN_HEIGHT) {
		m_pPlayer->SetPosY(0.0f);
		m_pTarget->ResetOnce();
		m_pWall->ResetOnce();
		m_pMap->ResetOnce();
	}
}





