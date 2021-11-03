
#include "GO_SS_Communication.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include "GO_SS_Target.h"
#include <cmath>

void GO_SS_Communication::Update(void)
{
	//ShotString�Ƀv���C���[�̃|�W�V�����o�^
	SetShotStringPlayer(); 

	/*	�v���C���[�̋���	-> �؂�ւ�(index)
	
		PLAYERMOVE_NOJUMP
		PLAYERMOVE_YESJUMP
	*/
	PlayerMoveSwitch(PLAYERMOVE_YESJUMP);
	
	//�^�[�Q�b�g�̍X�V�����@
	TergetUpdate();

	//�����蔻��̍X�V����
	m_ssCollision.CollisionUpdate();
	
}




void GO_SS_Communication::SetShotStringPlayer()
{
	m_pShotString->SetPos(m_pPlayer->GetPos());
}

//-----------------------------------------------------------------------------------------
//	JumpMoveBackGround_Pat1()
//-----------------------------------------------------------------------------------------
//	�A���O����cos�ƕ��A�w�i�𓮂���
//	�Ȃ�t���[���H		�[��120���炢	�[��Angle�ɂ���ĕς��
//	�ǂ̃^�C�~���O�H	�[���W�����v(space key )�������ꂽ��
//	�K�v�Ȃ��̂́H		�[���W�����v�����Ƃ��̃t���O�A�t���[���𑪂�ϐ�(int)
//							angle
//	�ǂ��������H		�[���W�����v�t���O���オ���Đ��t���[���ԁAAddU(cosf(angle));
//-----------------------------------------------------------------------------------------
void GO_SS_Communication::JumpMoveBackGround_NoJump()
{
	//�����o������
	if (!m_pShotString->IsClick)return;

	//�J�E���^�[������ɒB������
	if (JumpCounter >= JumpCountMax) {

		//�V���b�g�X�g�����O�̃N���b�N�t���O���낷
		m_pShotString->IsClick = false;

		//�W�����v�t���O���Z�b�g
		JumpCounter = 0;
	}
	else {

		//�w�i�X�N���[������
		m_pBackGround->AddU(cosf(m_pShotString->GetAngle()) / 100.0f);

		//�J�E���^�[�C���N�������g
		JumpCounter++;
	}

	//�W�����v���̍ŏ���1�񂾂�
	if (JumpCounter <= 1) {
		//�J�E���^�[�������
		JumpCountMax = (int)(cosf(cosf(m_pShotString->GetAngle())) * 60.0f);
	}

}

//�N���b�N�����瓮��
void GO_SS_Communication::JumpMoveBackGround_YesJump()
{
	//�����o������
	if (!m_pShotString->IsClick)return;

	//�J�E���^�[������ɒB������
	if (JumpCounter >= JumpCountMax) {
		//�d�̓��Z�b�g
		m_pPlayer->SetGravityDefault();

		//�V���b�g�X�g�����O�̃N���b�N�t���O���낷
		m_pShotString->IsClick = false;

		//�W�����v�J�E���^�[���Z�b�g
		JumpCounter = 0;
	}
	else {
		//�w�i�X�N���[������
		m_pBackGround->SubU(cosf(m_pShotString->GetAngle()) / 100.0f);

		FLOAT angle = m_pShotString->GetAngle() * (FLOAT)180.0f / (FLOAT)PI;

		//�v���C���[�̓�������
		//		  90
		//				
		//	0			��180,��-180
		//				
		//		 -90
		//����̉E�������𔻒�
		if (angle >= 90 && angle < 180
			|| angle >= -180 && angle < -90) {

			m_pPlayer->WavePosPlus((float)(JumpCounter)*RADIAN);
		}
		else {
			m_pPlayer->WavePosMinus((float)(JumpCounter) * RADIAN );
		}
		

	
		//�J�E���^�[
		JumpCounter++;
	}

	//�W�����v���̍ŏ���1�񂾂�
	if (JumpCounter <= 1) {

		//�W�����v�̃t���[��������
		JumpCountMax = (int)(fabs(cosf(m_pShotString->GetAngle())* 60.0f));
	}
}

void GO_SS_Communication::PlayerMoveSwitch(PlayerMove index)
{
	//�v���C���[�̓����[���؂�ւ��\
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

//
void GO_SS_Communication::TergetUpdate()
{
	/* �����ꏊ */
	m_pPlayer->GetPos();
}

