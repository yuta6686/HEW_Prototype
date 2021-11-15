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
	playerPos = D3DXVECTOR2(0.0f, 0.0f);
	Vortex_Vertex.vel = D3DXVECTOR2(0.0f, 0.0f);
	Vortex_Vertex.color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f);
	Vortex_Vertex.frame = 0;
	Vortex_Vertex.angle = 0.0f;
	Vortex_Vertex.size = D3DXVECTOR2(500.0f, 500.0f);

	Scramble_texture = LoadTexture(TEX_NAME);

	scrambleflag = false;
}

void GO_SS_Scramble::Finalize(void)
{
}

void GO_SS_Scramble::Update(void)
{
	playerPos = m_pPlayer->GetPos();
	/*if (Vortex_Vertex.angle >= 360.0f) {
		Vortex_Vertex.angle = 0.0f;
	}
	else {
		Vortex_Vertex.angle += 1.0f;
	}*/

	


	if (IsMouseRightPressed()) {

		scrambleflag = true;
	}
	else
	{
		scrambleflag = false;
	}
}

void GO_SS_Scramble::Draw(void)
{
	if (scrambleflag) {
		DrawSpriteColorRotate(Scramble_texture, playerPos.x, playerPos.y,
			Vortex_Vertex.size.x, Vortex_Vertex.size.y,
			0.0f, 0.0f, 1.0f, 1.0f, Vortex_Vertex.color, Vortex_Vertex.angle);
	}
}
