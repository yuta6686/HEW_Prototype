#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include "GO_SS_Target.h"
#include "GO_SS_Scramble.h"
#include "sound.h"

static int g_SoundIndex = 0;

void GO_SS_ShotString::Initialize(void)
{
	//���@�p�����[�^������
	{
		String_Texture = LoadTexture(TEX_NAME);

		String_Vertex.size.x = 0.0f;
		String_Vertex.size.y = 5.0f;
		String_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
		String_Vertex.angle = 0.0f;
		String_Vertex.use = false;
	}

	//�~�@�p�����[�^������
	{
		Circle_Texture = LoadTexture(CIRCLE_TEX_NAME);

		Circle_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
		Circle_Vertex.size = D3DXVECTOR2(100.0f,0.0f);
		Circle_Vertex.alpha = 1.0f;
	}

	m_DecreaseCircleValue = m_DECREASE_CIRCLE_DEFAULT;

	m_DecreaseCircleCounter = 0;

	m_IsNegi = false;
	

	m_AimFlag = false;

	IsInsideTarget = -1;

	m_AimTarget = -1;

	m_CircleColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}

void GO_SS_ShotString::Finalize(void)
{

}

void GO_SS_ShotString::Update(void)
{
	NegiEffects();

#ifdef _DEBUG	// �f�o�b�O�ł̎�����Angle��\������



	//sprintf(&GetDebugStr()[strlen(GetDebugStr())], "�����l�F%.2f", m_DecreaseCircleValue);

	//SetWindowText(GethWnd()[0], GetDebugStr());
#endif

	m_pScramble->SetPos(m_pPlayer->GetPos());

	if (IsMouseRightPressed()) {
		String_Vertex.use = true;
	}


	//	�^�[�Q�b�g�ł͂Ȃ��ꏊ���N���b�N
	NoTargetClick();

	//	�^�[�Q�b�g���N���b�N
	TargetClick();

	//	��TargetClick��艺�ɔz�u
	//	�G�C���ύX
	ChangeAim();

	//�|�W�V�������v���C���[�̃|�W�V�����ɂ���
	String_Vertex.pos = m_pPlayer->GetPos();
	Circle_Vertex.pos = m_pPlayer->GetPos();

	//	�v���C���[�ƃJ�[�\���̊p�x�擾
	String_Vertex.angle = GetAnglePlayerAndCursor();

	//--���̒����L�΂�--//
	//	����:�L�΂���	//
	//	max -> �^�[�Q�b�g�ƃv���C���[�̋���	//
	ExtendLengthOfString(100.0f);

	//�~�̃T�C�Y��ύX����
	ChangeSizeOfCircle();

	Circle_Vertex.alpha = Circle_Vertex.size.x / 1000.0f;
}

void GO_SS_ShotString::Draw(void)
{
	SetBlendState(BLEND_MODE_ADD);

	DrawSpriteColor(Circle_Texture, Circle_Vertex.pos.x, Circle_Vertex.pos.y,
		Circle_Vertex.size.x, Circle_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f,
		D3DXCOLOR(m_CircleColor.r, 1.0f, 1.0f, Circle_Vertex.alpha));

	SetBlendState(BLEND_MODE_ADD);


	if (String_Vertex.use) {
		DrawSpriteColorRotate(String_Texture, String_Vertex.pos.x, String_Vertex.pos.y,
			String_Vertex.size.x, String_Vertex.size.y,
			0.0f, 0.0f, 0.9f, 0.9f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), String_Vertex.angle);
	}
	

}

//	�~�̃T�C�Y��ύX����
void GO_SS_ShotString::ChangeSizeOfCircle()
{
	if (IsMouseRightPressed()) {
		Circle_Vertex.size.x += m_pScramble->GetPreviousDiff() / 10.0f;

		//Circle_Vertex.size.x -= Circle_Vertex.size.x / m_CircleSizeMax * m_TimeDelay;
	}
	else {
		if (Circle_Vertex.size.x <= m_CircleSizeMin) {
			Circle_Vertex.size.x = m_CircleSizeMin;
		}
		else {
			
		}



		Circle_Vertex.size.x -= m_DecreaseCircleValue * m_TimeDelay;
	}

	//	y��x�̃T�C�Y�����ɂ���
	Circle_Vertex.size.y = Circle_Vertex.size.x;
}

void GO_SS_ShotString::NegiEffects()
{
	if (!m_IsNegi) {
		m_DecreaseCircleValue = m_DECREASE_CIRCLE_DEFAULT;
		m_CircleColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		return;
	}

	

	if (m_DecreaseCircleCounter >= m_DECREASE_CIRCLE_COUNTER_MAX) 
	{
		m_DecreaseCircleCounter = 0;
		m_IsNegi = false;
	}
	else 
	{
		m_DecreaseCircleCounter++;
					
		//	�V���������l	  = �f�t�H���g�l			  * (		�J�E���^�[				�J�E���^�[�̍ő�l		)
		//	�J�E���^�[ / �ő�l = �J�E���^�[�̑����ɉ������A0�@�`�@1�܂ł̒l���擾�ł���B
		FLOAT value = ((FLOAT)m_DecreaseCircleCounter / (FLOAT)(m_DECREASE_CIRCLE_COUNTER_MAX*2.0f));
		m_DecreaseCircleValue = m_DECREASE_CIRCLE_DEFAULT * value;
		
		m_CircleColor = D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f);

		
	}
}

void GO_SS_ShotString::DebugOut(void)
{
#ifdef _DEBUG	// �f�o�b�O�ł̎�����Angle��\������
	wsprintf(GetDebugStr(), WINDOW_CAPTION);
	wsprintf(&GetDebugStr()[strlen(GetDebugStr())], " IsCollTarget:%d",
		0);

	SetWindowText(GethWnd()[0], GetDebugStr());
#endif
}

//�^�[�Q�b�g���N���b�N����
void GO_SS_ShotString::TargetClick(void)
{
	IsInsideTarget = TargetIsInRange();

	if (IsInsideTarget >= 0) {
		m_AimTarget = IsInsideTarget;

		m_AimFlag = true;

		if (m_pTarget->GetTarget()[IsInsideTarget].pos.x <= 0.0f || m_pTarget->GetTarget()[IsInsideTarget].pos.x >= SCREEN_WIDTH) {
			m_AimFlag = false;
			m_AimTarget = -1;
		}


	}
	else {
		m_AimFlag = false;		
	}

	if (m_AimTarget < 0 || m_pTarget->GetTarget()[m_AimTarget].pos.x <= 0.0f) {
		SetStringUse(false);
	}

	//	���T�C�Y���Z�b�g
	if (IsMouseLeftTriggered() && IsInsideTarget > -1) {
		String_Vertex.size.x = 0.0f;
		m_jumpCounter = 0;
		IsClickTarget = true;
	}

	if (IsMouseLeftPressed() && IsClickTarget){
		//	�T�C�h�ɂ������Ă����狭���I��
		if (m_pPlayer->IsColl && m_pPlayer->IsCollSide > -1) {
			m_jumpCounter += 120;
		}
		
		//	�I��
		if (m_jumpCounter >= 120) {
			IsClickTarget = false;

			m_LinerEnd = false;

			//m_IsPlayerMove = false;

			m_pScramble->SetNato(NRN_NATTO);
		}

		else {
			m_jumpCounter++;
			IsClickTarget = true;
			//m_AimFlag = true;

			Circle_Vertex.size.x -= Circle_Vertex.size.x / m_DecreaseJump;

			g_SoundIndex = LoadSound("data/BGM/se_natto.wav");

			//	�������[���O���[�o���ϐ��A�������[��0�`1�܂ł̐��l
			//�ŉ��ʂ��ݒ�ł��܂�
			SetVolume(g_SoundIndex, 0.5f);

			PlaySound(g_SoundIndex, 0);
		}
	}
	else 
	{
		IsClickTarget = false;
		m_AimFlag = false;
		m_LinerEnd = false;
		//m_IsPlayerMove = false;
	}
}

void GO_SS_ShotString::ChangeAim(void)
{
	if (m_AimFlag) {
		m_AimTarget = IsInsideTarget;		
	}
	AimPos = m_pTarget->GetTarget()[m_AimTarget].pos;
}

int GO_SS_ShotString::TargetIsInRange(void)
{	
	int index = -1;

	for (int i = 0; i < m_pTarget->GetTargetNumMax(); i++) {
		VERTEX_TARGET vt = m_pTarget->GetTarget()[i];
		if (!vt.use)continue;

		FLOAT x = powf(Circle_Vertex.pos.x - vt.pos.x, 2.0f);
		FLOAT y = powf(Circle_Vertex.pos.y - vt.pos.y, 2.0f);
		FLOAT dist = sqrtf(x + y);

		if (dist <= vt.size.x + Circle_Vertex.size.x - 550.0f) {
			index = i;
		}
	}

	return index;
}


void GO_SS_ShotString::ExtendLengthOfString(FLOAT amount)
{	
	//���̒������J�[�\���Ƃ̋����܂łɐ���
	if (GetDistance(String_Vertex.pos, AimPos) * 2.0f <= String_Vertex.size.x) {
		String_Vertex.size.x = GetDistance(String_Vertex.pos, AimPos) * 2.0f;
	}
	else {
		//���̒����L�΂�
		String_Vertex.size.x += amount * m_TimeDelay;
	}
}

//�^�[�Q�b�g�ł͂Ȃ��ꏊ���N���b�N
void GO_SS_ShotString::NoTargetClick(void)
{
	//�����ꂽ��
	if (IsMouseLeftTriggered()) {
		String_Vertex.size.x = 0.0f;
	}

}

FLOAT GO_SS_ShotString::GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2)
{
	return sqrtf(powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2));
}

FLOAT GO_SS_ShotString::GetAnglePlayerAndCursor()
{
	return atan2f(String_Vertex.pos.y - AimPos.y,
		String_Vertex.pos.x - AimPos.x);
}