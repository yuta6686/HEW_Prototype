#include "GO_SS_NattoRotate.h"


void GO_SS_NattoRotate::Initialize(void)
{
    m_TexIndex = LoadTexture(m_TexName);

    for (int i = 0; i < NATTO_MAX; i++) {
        m_Vertex[i].pos = D3DXVECTOR2(SCREEN_WIDTH / 4 * frand(), 100.0f*frand());
        m_Vertex[i].size = D3DXVECTOR2(50.0, 40.0f*frand_r()+20.0f);
        m_Vertex[i].angle = 0.1f;
        m_Vertex[i].rot = frand_r();
        m_Vertex[i].alpha = 1.0f;
        m_Vertex[i].radius = frand() * 100.0f + 50.0f;
        m_Vertex[i].use = false;
    }

    //  ‰Šúó‘Ô‚Ì”[“¤•Û—L”
    for (int i = 0; i < FIRST_NATTO; i++) {
        SetNatto();
    }
}

void GO_SS_NattoRotate::Finalize(void)
{
}

void GO_SS_NattoRotate::Update(void)
{
    for (int i = 0; i < NATTO_MAX; i++) {
        if (!m_Vertex[i].use)continue;

       
        m_Vertex[i].angle += m_Vertex[i].rot;
        
        //  ‰ñ“]ˆ—
        Rotation(i);

    }
}

void GO_SS_NattoRotate::Rotation(int index)
{
    float hw, hh;
    hw = m_PlayerPos.x - m_Vertex[index].pos.x;
    hh = m_PlayerPos.y - m_Vertex[index].pos.y;
    
    float BaseAngle = atan2f(hh,hw);		// ’†S“_‚©‚ç’¸“_‚É‘Î‚·‚éŠp“x

    float x = m_PlayerPos.x - cosf(BaseAngle + m_Vertex[index].rot) * m_Vertex[index].radius;
    float y = m_PlayerPos.y - sinf(BaseAngle + m_Vertex[index].rot) * m_Vertex[index].radius;

    m_Vertex[index].pos = D3DXVECTOR2(x, y);
}

FLOAT GO_SS_NattoRotate::frand()
{
    return (FLOAT)rand() / (FLOAT)RAND_MAX;
}

FLOAT GO_SS_NattoRotate::frand_r()
{
    return ANGLE_MIN + (FLOAT)(rand()) / (FLOAT)(RAND_MAX / (ANGLE_MAX - ANGLE_MIN));
}

void GO_SS_NattoRotate::Draw(void)
{
    for (int i = 0; i < NATTO_MAX; i++) {
        if (!m_Vertex[i].use)continue;
        DrawSpriteColorRotate(m_TexIndex, m_Vertex[i].pos.x, m_Vertex[i].pos.y,
            m_Vertex[i].size.x, m_Vertex[i].size.y, 1.0f, 1.0f, 1.0f, 1.0f,
            D3DXCOLOR(1.0f, 1.0f, 1.0f, m_Vertex[i].alpha),
            m_Vertex[i].angle);
    }
}

int GO_SS_NattoRotate::GetGameScene(void)
{
    return GAMESCENE_GAME_TEST;
}

void GO_SS_NattoRotate::SetNatto(void)
{
    for (int i = 0; i < NATTO_MAX; i++) {
        if (m_Vertex[i].use)continue;
        m_Vertex[i].use = true;
        break;
    }
}

