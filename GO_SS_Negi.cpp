#include "GO_SS_Negi.h"

void GO_SS_Negi::Initialize(void)
{
	m_TexIndex = LoadTexture(m_pTexName);


	for (int i = 0; i < NEGI_MAX; i++)
	{
		m_Negi[i].pos = D3DXVECTOR2(0.0f, 0.0f);
		m_Negi[i].size = D3DXVECTOR2(180.0f, 200.0f);
		m_Negi[i].use = false;
	}

	//	‰Šú
	for (int i = 0; i < 3; i++)
	{
		m_Negi[i].pos = D3DXVECTOR2(i*500.0f, 300.0f);
		m_Negi[i].use = true;
	}
}

void GO_SS_Negi::Finalize(void)
{
}

void GO_SS_Negi::Update(void)
{
}

void GO_SS_Negi::Draw(void)
{
	for (int i = 0; i < NEGI_MAX; i++) {
		if (m_Negi[i].use)
		{
			DrawSprite(m_TexIndex, m_Negi[i].pos.x, m_Negi[i].pos.y,
				m_Negi[i].size.x, m_Negi[i].size.y, 1.0f, 1.0f, 1.0f, 1.0f);
		}
	}
}

int GO_SS_Negi::GetGameScene(void)
{
    return 0;
}

void GO_SS_Negi::AddX(FLOAT x)
{
	for (int i = 0; i < NEGI_MAX; i++) {
		if (m_Negi[i].use)
		{
			m_Negi[i].pos.x += x;

		}
	}
}
