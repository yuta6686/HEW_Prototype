#include "GO_VortexRotation.h"
#include "GO_Player.h"
#include "GO_Vortex.h"

void GO_VortexRotation::Update(void)
{
	mp_vortex->SetVortexAngle(atan2(mp_player->GetPos().x - mp_vortex->GetVortexPos().x,
		mp_player->GetPos().y - mp_vortex->GetVortexPos().y));
}


