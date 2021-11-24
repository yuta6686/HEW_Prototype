#include "GO_SS_Effect_Wind.h"

void GO_SS_Effect_Wind::Initialize(void)
{
    Eff_Texture = LoadTexture(TEX_NAME);

    windEff.pos = D3DXVECTOR2(0.0f, 0.0f);
    windEff.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
    windEff.use = false;
    windEff.alpha = 0.0f;
    windEff.u = 0.0f;
}

void GO_SS_Effect_Wind::Finalize(void)
{
}

void GO_SS_Effect_Wind::Update(void)
{   if (windEff.alpha >= 5.0f) {
        windEff.alpha = 0.0f;
        windEff.use = false;
    }
    else
    {
        windEff.alpha += 0.03f;
        windEff.u += 0.03f;
    }
 
}

void GO_SS_Effect_Wind::Draw(void)
{
    if (windEff.use == false)return;

    //DrawSpriteLeftTopColor(Eff_Texture, windEff.pos.x, windEff.pos.y, windEff.size.x, windEff.size.y,
        //windEff.u, 1.0f, 1.0f, 1.0f, D3DXCOLOR(0.0f, windEff.alpha/5.0f, windEff.alpha / 5.0f, windEff.alpha));
}

