//---------------------------
//Vortex　＝　うずまき
//---------------------------
//	[GameFramework.cpp]
//	Yuta Yanagisawa 
//---------------------------
//	納豆混ぜるシーン（主に描画）
//

#include "GO_SS_Scramble.h"
#include "Texture.h"
#include "sprite.h"
#include "GO_SS_Player.h"


void GO_SS_Scramble::Initialize(void)
{
	Vortex_Vertex.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
	Vortex_Vertex.angle = 0.0f;
	Vortex_Vertex.size = D3DXVECTOR2(500.0f, 500.0f);

	Scramble_texture = LoadTexture(TEX_NAME);

	Vortex_Vertex.use = false;


	m_PrePos = D3DXVECTOR2(0.0f, 0.0f);
	m_CurPos = D3DXVECTOR2(0.0f, 0.0f);
}

void GO_SS_Scramble::Finalize(void)
{
}

void GO_SS_Scramble::Update(void)
{
	if (IsMouseRightPressed()) {

		Vortex_Vertex.use = true;
	}
	else
	{
		Vortex_Vertex.use = false;
	}

	FLOAT pDiff = GetPreviousDiff() / 20.0f;

	

	if (Vortex_Vertex.use) {
		if (pDiff <= 5.0f && m_Diff <= 0.5f) {
			m_Diff = pDiff;
		}
		else if (m_Diff >= 0.5f) {
			m_Diff *= 0.99f;
			Vortex_Vertex.angle += m_Diff;
		}
		else {
			Vortex_Vertex.angle += pDiff;
		}

		
	}
	else {
		if (Vortex_Vertex.angle <= 1.0f) {
			Vortex_Vertex.use = false;
			Vortex_Vertex.angle = 0.0f;
		}
		else {
			Vortex_Vertex.use = true;
			Vortex_Vertex.angle *= 0.93f;
		}
		
	}
}

void GO_SS_Scramble::LastUpdate(void)
{
	m_PrePos.x = GetMousePosX();
	m_PrePos.y = GetMousePosY();
}

void GO_SS_Scramble::Draw(void)
{
	if (Vortex_Vertex.use) {
		DrawSpriteColorRotate(Scramble_texture, Vortex_Vertex.pos.x, Vortex_Vertex.pos.y,
			Vortex_Vertex.size.x, Vortex_Vertex.size.y,
			0.0f, 0.0f, 1.0f, 1.0f, Vortex_Vertex.color, Vortex_Vertex.angle);
	}
}

FLOAT GO_SS_Scramble::GetPreviousDiff(void)
{
	FLOAT dist = 0.0f;

	if (Vortex_Vertex.use) {
		dist = sqrtf(powf((GetMousePosX() - m_PrePos.x), 2) + powf((GetMousePosY() - m_PrePos.y), 2));
	}

	return dist;
}