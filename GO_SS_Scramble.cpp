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



GO_SS_Scramble::~GO_SS_Scramble()
{
	delete m_Natto;
}

void GO_SS_Scramble::Initialize(void)
{
	Vortex_Vertex.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.01f);
	Vortex_Vertex.angle = 0.0f;
	Vortex_Vertex.size = D3DXVECTOR2(500.0f, 500.0f);

	Scramble_texture = LoadTexture(TEX_NAME);

	Vortex_Vertex.use = false;


	m_PrePos = D3DXVECTOR2(0.0f, 0.0f);
	m_CurPos = D3DXVECTOR2(0.0f, 0.0f);

	m_Natto = new GO_SS_NattoRotate();

	m_Natto->Initialize();
}

void GO_SS_Scramble::Finalize(void)
{
	m_Natto->Finalize();
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

		//	angle	慣性
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

		//α値	慣性
		if (Vortex_Vertex.color.a >= 1.0f) {
			Vortex_Vertex.color.a = 1.0f;
		}
		else {
			Vortex_Vertex.color.a *= 1.1f;
		}
		
	}
	else {

		//angle	慣性
		if (Vortex_Vertex.angle <= 1.0f) {
			
			Vortex_Vertex.angle = 0.0f;
		}
		else {
			Vortex_Vertex.use = true;
			Vortex_Vertex.angle *= 0.93f;
		}

		//α値	慣性
		if (Vortex_Vertex.color.a <= 0.1f) {
			Vortex_Vertex.use = false;
			Vortex_Vertex.color.a = 0.1f;
		}
		else {
			Vortex_Vertex.color.a *= 0.95f;
		}
		
	}

	//	納豆の処理
	m_Natto->SetPos(Vortex_Vertex.pos);
	m_Natto->Update();
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

	m_Natto->Draw();
}

FLOAT GO_SS_Scramble::GetPreviousDiff(void)
{
	FLOAT dist = 0.0f;

	if (Vortex_Vertex.use) {
		dist = sqrtf(powf((GetMousePosX() - m_PrePos.x), 2) + powf((GetMousePosY() - m_PrePos.y), 2));
	}

	return dist;
}