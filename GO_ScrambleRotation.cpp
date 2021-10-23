#include "GO_ScrambleRotation.h"
#include "GO_Player.h"
#include "GO_Scramble.h"

void GO_ScrambleRotation::Update(void){

	//見ずらいけど、角度取ってセットしてるだけ。
	mp_vortex->SetScrambleAngle(atan2((double)mp_player->GetPos().x - (double)mp_vortex->GetScramblePos().x,
		(double)mp_player->GetPos().y - (double)mp_vortex->GetScramblePos().y));
}




