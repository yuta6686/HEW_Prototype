#include "GO_SS_Karashi.h"

void GO_SS_Karashi::Initialize(void)
{
	m_TexIndex = LoadTexture(m_pTexName);


	for (int i = 0; i < KARASHI_MAX; i++)
	{
		m_Karashi[i].pos = D3DXVECTOR2(0.0f, 0.0f);
		m_Karashi[i].size = D3DXVECTOR2(180.0f, 200.0f);
		m_Karashi[i].use = false;
	}

	m_Circle.Initialize();
	m_Circle_001.Initialize();
}

void GO_SS_Karashi::Finalize(void)
{
	m_Circle.Finalize();
	m_Circle_001.Finalize();
}

void GO_SS_Karashi::Update(void)
{
	m_Circle.Update();
	m_Circle_001.Update();
}

void GO_SS_Karashi::Draw(void)
{
	for (int i = 0; i < KARASHI_MAX; i++) {
		if (m_Karashi[i].use)
		{
			DrawSpriteLeftTop(m_TexIndex, m_Karashi[i].pos.x, m_Karashi[i].pos.y,
				m_Karashi[i].size.x, m_Karashi[i].size.y, 1.0f, 1.0f, 1.0f, 1.0f);
		}
	}

	m_Circle.Draw();
	m_Circle_001.Draw();
}

int GO_SS_Karashi::GetGameScene(void)
{
    return 0;
}

void GO_SS_Karashi::AddX(FLOAT x)
{
	for (int i = 0; i < KARASHI_MAX; i++) {
		if (m_Karashi[i].use)
		{
			m_Karashi[i].pos.x += x;

		}
	}
}

void GO_SS_Karashi::SetKarashi(D3DXVECTOR2 pos)
{
	for (int i = 0; i < KARASHI_MAX; i++)
	{
		if (m_Karashi[i].use)
			continue;

		m_Karashi[i].pos = pos;
		m_Karashi[i].use = true;
		break;
	}
}
