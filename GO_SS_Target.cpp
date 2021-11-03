#include "GO_SS_Target.h"
//’N‚©‚±‚±‚Åì‚Á‚Ä

void GO_SS_Target::Initialize(void)
{
	Target_Texture = LoadTexture(TEX_NAME);
    for (int i = 0; i < TARGET_NUM_MAX; i++) {
        Target_Vertex[i].pos = D3DXVECTOR2(00.0f, 00.0f);
        Target_Vertex[i].size = D3DXVECTOR2(50.0f, 50.0f);
        Target_Vertex[i].use = false;
    }

    once = true;
}

void GO_SS_Target::Finalize(void)
{

}

void GO_SS_Target::Update(void)
{

}

void GO_SS_Target::Draw(void)
{
    for (int i = 0; i < TARGET_NUM_MAX; i++) {
        if (!Target_Vertex[i].use)continue;
        DrawSprite(Target_Texture, Target_Vertex[i].pos.x, Target_Vertex[i].pos.y,
            Target_Vertex[i].size.x, Target_Vertex[i].size.y, 1.0f, 1.0f, 1.0f, 1.0f);

    }

}

void GO_SS_Target::SETTarget()
{
    for (int i = 0; i < TARGET_NUM_MAX; i++) {
        if (Target_Vertex[i].use) continue;
        Target_Vertex[i].use = true;
        break;
    }
    
}

void GO_SS_Target::SetTarget(D3DXVECTOR2 pos)
{
    for (int i = 0; i < TARGET_NUM_MAX; i++) {
        if (Target_Vertex[i].use) continue;
        Target_Vertex[i].pos = pos;
        Target_Vertex[i].use = true;
        break;
    }

}

void GO_SS_Target::SetTarget(D3DXVECTOR2 pos, D3DXVECTOR2 size)
{
    for (int i = 0; i < TARGET_NUM_MAX; i++) {
        if (Target_Vertex[i].use) continue;
        Target_Vertex[i].pos = pos;
        Target_Vertex[i].size = size;
        Target_Vertex[i].use = true;
    }

}

void GO_SS_Target::SetTargetOnce()
{
    if (once) {
        once = false;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 16; j++) {
                SetTarget(D3DXVECTOR2(TARGET_WIDTH * j, TARGET_HEIGHT * i), D3DXVECTOR2(TARGET_WIDTH, TARGET_HEIGHT));
            }
        }
    }

}

