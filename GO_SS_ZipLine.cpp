#include "GO_SS_ZipLine.h"

void GO_SS_ZipLine::Initialize(void)
{
	poleTex = LoadTexture("data/TEXTURE/Pole.png");

    for (int i = 0; i < ZIPLINE_MAX; i++)
    {
        ziplineInfo[i].pos = D3DXVECTOR2(0.0f, 0.0f);
        ziplineInfo[i].size = D3DXVECTOR2(0.0f, 0.0f);
        ziplineInfo[i].use = false;
    }
}

void GO_SS_ZipLine::Finalize(void)
{
}

void GO_SS_ZipLine::Update(void)
{
}

void GO_SS_ZipLine::Draw(void)
{
    for (int i = 0; i < ZIPLINE_MAX; i++)
    {
        if (ziplineInfo[i].use)
        {
            DrawSpriteLeftTop(poleTex, ziplineInfo[i].pos.x , ziplineInfo[i].pos.y, 
                WALL_WIDTH / 3, WALL_HEIGHT * POLE_WALL_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f);
        }
    }
}

void GO_SS_ZipLine::SetZipLine(D3DXVECTOR2 pos)
{
    for (int i = 0; i < ZIPLINE_MAX; i++)
    {
        if (ziplineInfo[i].use) 
            continue;

        ziplineInfo[i].pos = pos;
        ziplineInfo[i].use = true;
        break;
    }
}

void GO_SS_ZipLine::AddX(FLOAT x)
{
    for (int i = 0; i < ZIPLINE_MAX; i++) {
        if (!ziplineInfo[i].use)continue;
        ziplineInfo[i].pos.x += x;
    }
}
