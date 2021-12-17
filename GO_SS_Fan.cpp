#include "GO_SS_Fan.h"

void GO_SS_Fan::Initialize(void)
{
	m_FanATex = LoadTexture("data/TEXTURE/納豆.png");
	//m_FanBTex = LoadTexture();

	once = true;

	for (int i = 0; i < FANS_MAX; i++)
	{
		m_FanInfo[i].pos = D3DXVECTOR2(0.0f, 0.0f);
		m_FanInfo[i].size = D3DXVECTOR2(0.0f, 0.0f);
		m_FanInfo[i].use = false;
		m_FanInfo[i].isWork = false;
	}
}

void GO_SS_Fan::Finalize(void)
{
}

void GO_SS_Fan::Update(void)
{
	for (int i = 0; i < FANS_MAX; i++)
	{
		if (FCCollision(m_FanInfo[i].pos, m_FanInfo[i].size.x, m_pCircle->pos, m_pCircle->size.x))
		{
			m_FanInfo[i].isWork = true;
		}
		else
		{
			m_FanInfo[i].isWork = false;
		}
	}
	
	DebugOut();
}

void GO_SS_Fan::Draw(void)
{
	for (int i = 0; i < FANS_MAX; i++)
	{
		if (m_FanInfo[i].use)
		{
			DrawSpriteLeftTop(m_FanATex, m_FanInfo[i].pos.x, m_FanInfo[i].pos.y,
				m_FanInfo[i].size.x, m_FanInfo[i].size.y, 0.0f, 0.0f, 1.0f, 1.0f);
		}
	}
}

void GO_SS_Fan::SetFan(D3DXVECTOR2 pos)
{
	for (int i = 0; i < FANS_MAX; i++)
	{
		if (m_FanInfo[i].use)
			continue;

		m_FanInfo[i].pos = pos;
		m_FanInfo[i].size = D3DXVECTOR2(WALL_WIDTH, WALL_HEIGHT);
		m_FanInfo[i].use = true;
		break;
	}
}

void GO_SS_Fan::AddX(FLOAT x)
{
	for (int i = 0; i < FANS_MAX; i++)
	{
		if (!m_FanInfo[i].use)continue;
		m_FanInfo[i].pos.x += x;
	}
}

bool GO_SS_Fan::FCCollision(D3DXVECTOR2 pos1,float size1,D3DXVECTOR2 pos2,float size2)
{
	D3DXVECTOR2 vDistance = pos1 - pos2;
	
	float len;
	
	len = D3DXVec2LengthSq(&vDistance);

	float size = (size1 + size2) * (size1 + size2);

	if (len < size)
	{
		return true;
	}

	return false;
}

void GO_SS_Fan::DebugOut(void)
{
#ifdef _DEBUG	// デバッグ版の時だけAngleを表示する
	wsprintf(GetDebugStr(), WINDOW_CAPTION);
	wsprintf(&GetDebugStr()[strlen(GetDebugStr())], " isWork:%d",
		m_FanInfo[0].isWork);

	SetWindowText(GethWnd()[0], GetDebugStr());
#endif
}
