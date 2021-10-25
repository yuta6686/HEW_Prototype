#include "GO_Timer.h"

void GO_Timer::Initialize(void)
{
	Number_Texture = LoadTexture(TEX_NAME);
}

void GO_Timer::Finalize(void)
{
}

void GO_Timer::Update(void)
{
	m_counter++;

}

void GO_Timer::Draw(void)
{
	static int cnt;
	cnt = m_counter % 10;
	//4Œ…–Ú	
	DrawSprite(Number_Texture, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 75, 75, 0.25f*cnt, 0.25f * cnt, 0.25f, 0.25f);
}