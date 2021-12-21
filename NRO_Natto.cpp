#include "NRO_Natto.h"

void NRO_Natto::Initialize(void)
{
}

void NRO_Natto::Finalize(void)
{
}

void NRO_Natto::Update(void)
{
}

void NRO_Natto::Draw(void)
{
    DrawSprite(GetTexIndex(), SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 3*2, 
        100.0f, 100.0f,
        1.0f, 1.0f, 1.0f, 1.0f);
}

int NRO_Natto::GetGameScene(void)
{
    return 0;
}
