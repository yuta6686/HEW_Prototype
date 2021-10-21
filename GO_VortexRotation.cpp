#include "GO_VortexRotation.h"
#include "GO_Player.h"
#include "GO_Vortex.h"

void GO_VortexRotation::Update(void)
{
	//見ずらいけど、角度取ってセットしてるだけ。
	mp_vortex->SetVortexAngle(atan2((double)mp_player->GetPos().x - (double)mp_vortex->GetVortexPos().x,
		(double)mp_player->GetPos().y - (double)mp_vortex->GetVortexPos().y));
}


