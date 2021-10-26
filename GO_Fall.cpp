#include "GO_Fall.h"

void GO_Fall::Initialize(void)
{
	//Textureì«Ç›çûÇ›
	Texture_Fall = LoadTexture(TEX_NAME_FALL);
	Texture_Walk = LoadTexture(TEX_NAME_WALK);

	nowTexture = Texture_Walk;

	//Fall_Vertexèâä˙âª
	Fall_Vertex.pos = D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4);
	Fall_Vertex.size = D3DXVECTOR2(200.0f, 200.0f);
	Fall_Vertex.counter = 0;
	Fall_Vertex.use = true;
}

void GO_Fall::Finalize(void)
{

}

void GO_Fall::Update(void)
{

}

void GO_Fall::Draw(void)
{
	DrawSprite(nowTexture, Fall_Vertex.pos.x, Fall_Vertex.pos.y,
		Fall_Vertex.size.x, Fall_Vertex.size.y, 1.0f,1.0f, 1.0f, 1.0f);
}

