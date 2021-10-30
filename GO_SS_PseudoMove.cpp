
#include "GO_SS_PseudoMove.h"
#include "GO_SS_BackGround.h"

void GO_SS_PseudoMove::Update(void)
{
	
	if (GetKeyboardPress(DIK_D)) {
		m_pBackGround->AddU();
	}

	if (GetKeyboardPress(DIK_A)) {
		m_pBackGround->SubU();
	}
}

