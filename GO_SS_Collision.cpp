#include "GO_SS_Collision.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include "GO_SS_Target.h"
#include "GO_SS_Wall.h"



void GO_SS_Collision::CollisionUpdate(void)
{
	//�v���C���[�ƕǂ̏Փˏ���
	if (CJ_PlayerWall() >= 0)m_pPlayer->IsColl = true;
	else m_pPlayer->IsColl = false;
}

// ----------------------------------------------------------------
//						�v���C���[�ƕ�
// ----------------------------------------------------------------
//	�ߒl�F	�������Ă�����A���̕ǂ̃C���f�b�N�X���B
//			�������Ă��Ȃ�������A-1��Ԃ�
// ----------------------------------------------------------------
int GO_SS_Collision::CJ_PlayerWall(void)
{
	for (int i = 0; i < m_pWall->GetWallNumMax(); i++) {
		VERTEX_WALL vwall = m_pWall->GetvWall(i);
		if (!vwall.use)continue;
		if (BBCollision(m_pPlayer->GetPos(), m_pPlayer->GetSize(), vwall.pos, vwall.size)) {
			return i;
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

	//X���̔���
	if (min1.x < max2.x && max1.x > min2.x)
	{
		//Y���̔���
		if (min1.y < max2.y && max1.y > min2.y)
		{
			//�S�Ă̏�����TRUE�Ȃ�q�b�g����
			return true;
		}
	}
	return false;
}
