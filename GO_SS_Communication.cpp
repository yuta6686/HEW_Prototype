
#include "GO_SS_Communication.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"


void GO_SS_Communication::Update(void)
{
	SetShotStringPlayer(); 
	JumpMoveBackGround();
}

void GO_SS_Communication::SetShotStringPlayer()
{
	m_pShotString->SetPos(m_pPlayer->GetPos());
}

//	アングルのcosθ分、背景を動かす
//	なんフレーム？		ー＞120くらい
//	どのタイミング？	ー＞ジャンプ(space key )が押されたら
//	必要なものは？		ー＞ジャンプしたときのフラグ、フレームを測る変数(int)
//							angle
//	どう動かす？		ー＞ジャンプフラグが上がって数フレーム間、AddU(cosf(angle));
void GO_SS_Communication::JumpMoveBackGround()
{
	if (!m_pPlayer->IsJump)return;

	if (JumpCounter >= JumpCountMax) {
		m_pPlayer->IsJump = false;
		JumpCounter = 0;
	}
	else {
		m_pBackGround->AddU(cosf(m_pShotString->GetAngle()) / 100.0f);
		JumpCounter++;
	}

	if (JumpCounter <= 1) {
		JumpCountMax = (int)(cosf(cosf(m_pShotString->GetAngle())) * 60.0f);
	}

}

