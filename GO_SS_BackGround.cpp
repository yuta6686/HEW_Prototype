#include "GO_SS_BackGround.h"
#include "scene.h"
#include "StageObject.h"

void GO_SS_BackGround::Initialize(void)
{
	BackGround_Texture = LoadTexture(TEX_NAME);

	BackGround_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
	BackGround_Vertex.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	BackGround_Vertex.u = 0.5f;

	m_morning = LoadTexture(TEX_NAME_MORNING);
	m_noon = LoadTexture(TEX_NAME_NOON);
	m_night = LoadTexture(TEX_NAME_NIGHT);

	m_nowTex = m_morning;

	CmpTexture = LoadTexture(CMP_TEX_NAME);
}

void GO_SS_BackGround::Finalize(void)
{
}

void GO_SS_BackGround::Update(void)
{

	switch (GetStageNum())
	{
	case STAGE_NUM_NONE:
		break;
	case STAGE_NUM_001:
		m_nowTex = m_morning;
		break;
	case STAGE_NUM_002:
		m_nowTex = m_noon;
		break;
	case STAGE_NUM_003:
		m_nowTex = m_night;
		break;
	case STAGE_NUM_MAX:
		break;
	default:
		break;
	}
}

void GO_SS_BackGround::Draw(void)
{
	DrawSpriteLeftTopColor(m_nowTex, BackGround_Vertex.pos.x, BackGround_Vertex.pos.y,
		BackGround_Vertex.size.x, BackGround_Vertex.size.y,
		BackGround_Vertex.u, 1.0f, 0.5f, 1.0f,D3DXCOLOR(1.0f,1.0f,1.0f,0.75f));

	/*DrawSpriteLeftTopColor(CmpTexture,0.0f,0.0f, SCREEN_WIDTH, SCREEN_HEIGHT,
		1.0f, 1.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));*/
}

