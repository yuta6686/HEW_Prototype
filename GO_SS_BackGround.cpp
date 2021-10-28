#include "GO_SS_BackGround.h"

void GO_SS_BackGround::Initialize(void)
{
	BackGround_Texture = LoadTexture(TEX_NAME);

	BackGround_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
	BackGround_Vertex.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void GO_SS_BackGround::Finalize(void)
{
}

void GO_SS_BackGround::Update(void)
{
}

void GO_SS_BackGround::Draw(void)
{
	DrawSpriteLeftTop(BackGround_Texture, BackGround_Vertex.pos.x, BackGround_Vertex.pos.y,
		BackGround_Vertex.size.x, BackGround_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f);
}

