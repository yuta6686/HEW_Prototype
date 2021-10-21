#include "GO_VortexRotation.h"
#include "GO_Player.h"
#include "GO_Vortex.h"

void GO_VortexRotation::Update(void)
{
	mp_vortex->SetVortexAngle((double)atan2(mp_player->GetPos().x - (double)mp_vortex->GetVortexPos().x,
		(double)mp_player->GetPos().y - (double)mp_vortex->GetVortexPos().y));
}


