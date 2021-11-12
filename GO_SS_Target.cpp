#include "GO_SS_Target.h"
//’N‚©‚±‚±‚Åì‚Á‚Ä

void GO_SS_Target::Initialize(void)
{
	Target_Texture = LoadTexture(TEX_NAME);

    for (int i = 0; i < TARGET_NUM_MAX; i++) {
        Target_Vertex[i].pos = D3DXVECTOR2(00.0f, 00.0f);
        Target_Vertex[i].size = D3DXVECTOR2(TARGET_WIDTH, TARGET_HEIGHT);
        Target_Vertex[i].use = false;
    }

    Target_Eff = LoadTexture(TE_TEX_NAME);

    once = true;
}

void GO_SS_Target::Finalize(void)
{

}

void GO_SS_Target::Update(void)
{
    SetTargetOnce();
}

void GO_SS_Target::Draw(void)
{
    for (int i = 0; i < TARGET_NUM_MAX; i++) {

        if (!Target_Vertex[i].use)continue;

        DrawSprite(Target_Texture, Target_Vertex[i].pos.x, Target_Vertex[i].pos.y,
            Target_Vertex[i].size.x, Target_Vertex[i].size.y, 1.0f, 1.0f, 1.0f, 1.0f);

        DrawSprite(Target_Eff, Target_Vertex[i].pos.x, Target_Vertex[i].pos.y + 10.0f,
            Target_Vertex[i].size.x, Target_Vertex[i].size.y, 1.0f, 1.0f, 1.0f, 1.0f);
    }

}

void GO_SS_Target::SetTarget()
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
        break;
    }

}

void GO_SS_Target::SetTargetOnce()
{
    if (once) {
        once = false;
        SetTarget(D3DXVECTOR2(1000.0f, 300.0f));

    }

}

void GO_SS_Target::AddPosX(FLOAT x)
{
    for (int i = 0; i < TARGET_NUM_MAX; i++) {
        if (!Target_Vertex[i].use)continue;
        Target_Vertex[i].pos.x += x;
    }
}

