#include "GO_SS_BackGround.h"

void GO_SS_BackGround::Initialize(void)
{
	BackGround_Texture = LoadTexture(TEX_NAME);

	BackGround_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
	BackGround_Vertex.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	BackGround_Vertex.u = 0.5f;

	CmpTexture = LoadTexture(CMP_TEX_NAME);
}

void GO_SS_BackGround::Finalize(void)
{
}

void GO_SS_BackGround::Update(void)
{
	if (GetKeyboardPress(DIK_D)) {
		AddU();
	}

	if (GetKeyboardPress(DIK_A)) {
		SubU();
	}

	
}

void GO_SS_BackGround::Draw(void)
{
	DrawSpriteLeftTop(BackGround_Texture, BackGround_Vertex.pos.x, BackGround_Vertex.pos.y,
		BackGround_Vertex.size.x, BackGround_Vertex.size.y,
		BackGround_Vertex.u, 1.0f, 0.5f, 1.0f);

	DrawSpriteLeftTopColor(CmpTexture,0.0f,0.0f, SCREEN_WIDTH, SCREEN_HEIGHT,
		1.0f, 1.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
}

