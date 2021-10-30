
#include "GO_SS_Communication.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"


void GO_SS_Communication::Update(void)
{
	SetShotStringPlayer();
}

void GO_SS_Communication::SetShotStringPlayer()
{
	m_pShotString->SetPos(m_pPlayer->GetPos());
}

