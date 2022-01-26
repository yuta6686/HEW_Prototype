#include "GO_SS_Timer.h"
#include "GO_SS_Wall.h"
#include "fade.h"
#include <cmath>
#include "GO_SS_Collision.h"
#include "GO_SS_KitchenTimer.h"
#include "GO_SS_Player.h"

void GO_SS_Timer::Initialize(void)
{
	//�e�N�X�`�����[�h----------------
	Number_Texture = LoadTexture(TEX_NAME);
	m_TexIndex_Minority = LoadTexture(TEX_NAME_MINORITY);
	m_TexIndex_Point = LoadTexture(TEX_NAME_POINT);

	//-------------������-------------
	//�P����
	{
		Timer_Vertex.alpha = 1.0f;
		Timer_Vertex.counter = 0;
		Timer_Vertex.pos = D3DXVECTOR2(SCREEN_WIDTH *6.5/8, SCREEN_HEIGHT / 10);
		Timer_Vertex.size = D3DXVECTOR2(75, 75);
		Timer_Vertex.u = 0.0f;
		Timer_Vertex.v = 0.0f;
		Timer_Vertex.use = true;
	}

	//�����_��1��
	{
		Timer_Second.pos = D3DXVECTOR2(Timer_Vertex.pos.x + 100.0f, SCREEN_HEIGHT / 10);
		Timer_Second.size = D3DXVECTOR2(75, 75);
		Timer_Second.u = 0.0f;
		Timer_Second.v = 0.0f;
	}

	//�����_��2��
	{
		Timer_Third.pos = D3DXVECTOR2(Timer_Vertex.pos.x + 200.0f, SCREEN_HEIGHT / 10);
		Timer_Third.size = D3DXVECTOR2(75, 75);
		Timer_Third.u = 0.0f;
		Timer_Third.v = 0.0f;
	}


	{
		Timer_TenDigits.pos = D3DXVECTOR2(Timer_Vertex.pos.x - 100.0f, SCREEN_HEIGHT / 10);
		Timer_TenDigits.size = D3DXVECTOR2(75, 75);
		Timer_TenDigits.u = 0.0f;
		Timer_TenDigits.v = 0.0f;
	}

	//	�����_
	{
		Timer_Point.size = D3DXVECTOR2(Timer_Vertex.size.x * 3 / 4, Timer_Vertex.size.y * 3 / 4);
		Timer_Point.pos.x = Timer_Vertex.pos.x + (Timer_Vertex.size.x * 1 / 2);
		Timer_Point.pos.y = Timer_Vertex.pos.y + (Timer_Vertex.size.x * 1 / 3);
	}

	m_Eff.Initialize();
	m_AddTime.Initialize();
	m_Circle.Initialize();
	m_Circle_001.Initialize();
}

void GO_SS_Timer::Finalize(void)
{
	m_Eff.Finalize();
	m_AddTime.Finalize();
	m_Circle.Finalize();
	m_Circle_001.Finalize();
}

void GO_SS_Timer::Update(void)
{
	

	//�P����
	FirstNum();

	//�����_��1��
	SecondNum();

	//�����_��2��
	ThirdNum();

	//	10����
	TenDigits();


	SceneToGameOver();

	m_Eff.Update();

	m_AddTime.Update();

	m_Circle.Update();

	m_Circle_001.Update();

#ifdef _DEBUG	// �f�o�b�O�ł̎�����Angle��\������



	//sprintf(&GetDebugStr()[strlen(GetDebugStr())], "TimerVertexCounter�F %d", Timer_Vertex.counter);

	//SetWindowText(GethWnd()[0], GetDebugStr());
#endif
}

void GO_SS_Timer::Draw(void)
{
	if (Timer_Vertex.use == false)return;

	//�P����
	DrawSpriteColor(Number_Texture, Timer_Vertex.pos.x, Timer_Vertex.pos.y,
		Timer_Vertex.size.x, Timer_Vertex.size.y,
		Timer_Vertex.u, Timer_Vertex.v, NUMBER_WIDTH, NUMBER_HEIGHT,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, Timer_Vertex.alpha));

	//�����_��1��
	DrawSpriteColor(m_TexIndex_Minority, Timer_Second.pos.x, Timer_Second.pos.y,
		Timer_Second.size.x, Timer_Second.size.y,
		Timer_Second.u, Timer_Second.v, NUMBER_WIDTH, NUMBER_HEIGHT,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, Timer_Vertex.alpha));

	//�����_��2��
	DrawSpriteColor(m_TexIndex_Minority, Timer_Third.pos.x, Timer_Third.pos.y,
		Timer_Third.size.x, Timer_Third.size.y,
		Timer_Third.u, Timer_Third.v, NUMBER_WIDTH, NUMBER_HEIGHT,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, Timer_Vertex.alpha));

	//10����
	DrawSpriteColor(Number_Texture, Timer_TenDigits.pos.x, Timer_TenDigits.pos.y,
		Timer_TenDigits.size.x, Timer_TenDigits.size.y,
		Timer_TenDigits.u, Timer_TenDigits.v, NUMBER_WIDTH, NUMBER_HEIGHT,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, Timer_Vertex.alpha));

	//	�����_
	DrawSpriteColor(m_TexIndex_Point,
		Timer_Point.pos.x,Timer_Point.pos.y,
		Timer_Point.size.x,Timer_Point.size.y, 1.0f, 1.0f, 1.0f, 1.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, Timer_Vertex.alpha));

	m_Eff.Draw();
	m_AddTime.Draw();
	m_Circle.Draw();
	m_Circle_001.Draw();
}

void GO_SS_Timer::FirstNum(void)
{
	if (Timer_Vertex.use == false)return;

	//�P�b��������
	if (Timer_Vertex.counter >= TIMER_LIMIT) 
	{
		Timer_Vertex.counter = 0;
		Timer_Vertex.use = false;

		SceneTransition(SCENE_GAMEOVER);
	}
	else {
		Timer_Vertex.counter++;
	}




	

	//---------------------------------------------
	//	uv�l�̐ݒ�
	//	1 �b = 60 �t���[���@�[���@10�b = 600�t���[��
	//---------------------------------------------

	int cnt = (((TIMER_LIMIT - Timer_Vertex.counter)%600) / 60);

	//���l�ς��u�ԓ_��
	Timer_Vertex.alpha = ((TIMER_LIMIT - Timer_Vertex.counter) % 60) / 10;

	//�����̃A�j���[�V����UV�ݒ�
	Timer_Vertex.u = NUMBER_WIDTH * (cnt % NUMBER_X);
	Timer_Vertex.v = NUMBER_HEIGHT * (cnt / NUMBER_Y);
}

void GO_SS_Timer::SecondNum(void)
{
	//---------------------------------------------
	// 	   cnt	�ɂ���
	//---------------------------------------------
	//	0.1�b	=	�悭�킩��Ȃ��B
	//	�Ȃ�A1�b�̏�����10�{�̑����ł��΂悭��
	//---------------------------------------------
	int cnt = ((TIMER_LIMIT - Timer_Vertex.counter) / 6) % 10;


	Timer_Second.u = NUMBER_WIDTH * (cnt % NUMBER_X);
	Timer_Second.v = NUMBER_HEIGHT * (cnt / NUMBER_Y);
}

void GO_SS_Timer::ThirdNum(void)
{
	//---------------------------------------------
	// 	   cnt	�ɂ���
	//---------------------------------------------
	//	0.01�b	=	�悭�킩��Ȃ��B
	//	�Ȃ�A0.1�b�̏�����10�{�̑����ł��΂悭��
	//---------------------------------------------
	int cnt = (int)((TIMER_LIMIT - Timer_Vertex.counter) / (6.0f / 10.0f)) % 10;

	Timer_Third.u = NUMBER_WIDTH * (cnt % NUMBER_X);
	Timer_Third.v = NUMBER_HEIGHT * (cnt / NUMBER_Y);
}

void GO_SS_Timer::TenDigits(void)
{
	int cnt = (((TIMER_LIMIT - Timer_Vertex.counter) % 6000) / 600);

	//���l�ς��u�ԓ_��

	//�����̃A�j���[�V����UV�ݒ�
	Timer_TenDigits.u = NUMBER_WIDTH * (cnt % NUMBER_X);
	Timer_TenDigits.v = NUMBER_HEIGHT * (cnt / NUMBER_Y);
}

//�^�C�}�[��0�ɂȂ�����Gameover��
void GO_SS_Timer::SceneToGameOver(void)
{
}