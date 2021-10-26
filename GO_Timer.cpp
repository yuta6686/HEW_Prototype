#include "GO_Timer.h"

void GO_Timer::Initialize(void)
{
	Number_Texture = LoadTexture(TEX_NAME);

	Timer_Vertex.alpha = 1.0f;
	Timer_Vertex.counter = 0;
	Timer_Vertex.pos = D3DXVECTOR2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	Timer_Vertex.size = D3DXVECTOR2(75, 75);
	Timer_Vertex.u = 0.0f;
	Timer_Vertex.v = 0.0f;
	Timer_Vertex.use = true;
}

void GO_Timer::Finalize(void)
{
}

void GO_Timer::Update(void)
{
	if (Timer_Vertex.use == false)return;

	//ÇPïbÇΩÇ¡ÇΩÇÁ
	if (Timer_Vertex.counter >= 600) {

		//î[ì§Ç‹Ç∫Ç‹Ç∫èIóπ
		Timer_Vertex.counter = 0;
		Timer_Vertex.use = false;
	}
	else {
		Timer_Vertex.counter++;
	}

	int cnt = 0;
	cnt = ((600 - Timer_Vertex.counter) / 60);

	Timer_Vertex.alpha = ((600 - Timer_Vertex.counter) % 60)/10;
	
	Timer_Vertex.u = NUMBER_WIDTH * (cnt % NUMBER_X);
	Timer_Vertex.v = NUMBER_HEIGHT * (cnt / NUMBER_Y);
}

void GO_Timer::Draw(void)
{
	if (Timer_Vertex.use == false)return;

	DrawSpriteColor(Number_Texture, SCREEN_WIDTH/2, SCREEN_HEIGHT/2,
		Timer_Vertex.size.x, Timer_Vertex.size.y,
		Timer_Vertex.u, Timer_Vertex.v, NUMBER_WIDTH, NUMBER_HEIGHT,
		D3DXCOLOR(1.0f,1.0f,1.0f, Timer_Vertex.alpha));

}
