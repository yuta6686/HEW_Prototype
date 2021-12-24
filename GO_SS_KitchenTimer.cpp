#include "GO_SS_KitchenTimer.h"
#include "Texture.h"
#include "sprite.h"
#include "game.h"
#include "main.h"
#include "input.h"
#include "fade.h"

void GO_SS_KitchenTimer::Initialize(void)
{
	KitchenTimer_Texture = LoadTexture(KTIMER_TEX_NAME);

	KitchenTimer_Vertex.pos = D3DXVECTOR2(800.0f, 800.0f);
	KitchenTimer_Vertex.size = D3DXVECTOR2(180.0f, 200.0f);

}

void GO_SS_KitchenTimer::Finalize(void)
{

}

void GO_SS_KitchenTimer::Update(void)
{
	
}

void GO_SS_KitchenTimer::Draw(void)
{
	if (KitchenTimer_Vertex.use) {
		DrawSprite(KitchenTimer_Texture, KitchenTimer_Vertex.pos.x, KitchenTimer_Vertex.pos.y,
			KitchenTimer_Vertex.size.x, KitchenTimer_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f);
	}
}

void GO_SS_KitchenTimer::AddX(FLOAT x)
{
	KitchenTimer_Vertex.pos.x += x;
}