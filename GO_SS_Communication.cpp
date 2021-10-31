
#include "GO_SS_Communication.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include <cmath>

void GO_SS_Communication::Update(void)
{
	//ShotStringにプレイヤーのポジション登録
	SetShotStringPlayer(); 

	/*	プライヤーの挙動	-> 切り替え(index)
	
		PLAYERMOVE_NOJUMP
		PLAYERMOVE_YESJUMP
	*/
	PlayerMove index = PLAYERMOVE_YESJUMP;


	PlayerMoveSwitch(index);
	
}

void GO_SS_Communication::SetShotStringPlayer()
{
	m_pShotString->SetPos(m_pPlayer->GetPos());
}

//-----------------------------------------------------------------------------------------
//	JumpMoveBackGround_Pat1()
//-----------------------------------------------------------------------------------------
//	アングルのcosθ分、背景を動かす
//	なんフレーム？		ー＞120くらい	ー＞Angleによって変わる
//	どのタイミング？	ー＞ジャンプ(space key )が押されたら
//	必要なものは？		ー＞ジャンプしたときのフラグ、フレームを測る変数(int)
//							angle
//	どう動かす？		ー＞ジャンプフラグが上がって数フレーム間、AddU(cosf(angle));
//-----------------------------------------------------------------------------------------
void GO_SS_Communication::JumpMoveBackGround_NoJump()
{
	//糸を出したら
	if (!m_pShotString->IsClick)return;

	//カウンターが上限に達したら
	if (JumpCounter >= JumpCountMax) {

		//ショットストリングのクリックフラグ下ろす
		m_pShotString->IsClick = false;

		//ジャンプフラグリセット
		JumpCounter = 0;
	}
	else {

		//背景スクロール処理
		m_pBackGround->AddU(cosf(m_pShotString->GetAngle()) / 100.0f);

		//カウンターインクリメント
		JumpCounter++;
	}

	//ジャンプ中の最初の1回だけ
	if (JumpCounter <= 1) {
		//カウンター上限調整
		JumpCountMax = (int)(cosf(cosf(m_pShotString->GetAngle())) * 60.0f);
	}

}

//クリックしたら動く
void GO_SS_Communication::JumpMoveBackGround_YesJump()
{
	//糸を出したら
	if (!m_pShotString->IsClick)return;

	//カウンターが上限に達したら
	if (JumpCounter >= JumpCountMax) {
		//重力リセット
		m_pPlayer->SetGravityDefault();

		//ショットストリングのクリックフラグ下ろす
		m_pShotString->IsClick = false;

		//ジャンプカウンターリセット
		JumpCounter = 0;
	}
	else {
		//背景スクロール処理
		m_pBackGround->SubU(cosf(m_pShotString->GetAngle()) / 100.0f);

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

void GO_SS_Communication::PlayerMoveSwitch(PlayerMove index)
{
	//プライヤーの動きー＞切り替え可能
	switch (index)
	{
	case PLAYERMOVE_NONE:
		break;
	case PLAYERMOVE_NOJUMP:
		JumpMoveBackGround_NoJump();
		break;
	case PLAYERMOVE_YESJUMP:
		JumpMoveBackGround_YesJump();
		break;
	case PLAYERMOVE_MAX:
		break;
	default:
		break;
	}
}

