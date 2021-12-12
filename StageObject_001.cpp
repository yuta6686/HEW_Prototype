#include "StageObject_001.h"

HRESULT StageObject_001::Init(void)
{
    m_TextureIndex = LoadTexture(m_TextureName);

    m_Vertex.pos = D3DXVECTOR2(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2);
    m_Vertex.size = D3DXVECTOR2(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2);
    m_Vertex.alpha = 1.0f;
    m_Vertex.use = true;
    return E_NOTIMPL;
}

void StageObject_001::Uninit(void)
{
}

void StageObject_001::Update(void)
{
}

void StageObject_001::Draw(void)
{
    DrawSpriteColor(m_TextureIndex, m_Vertex.pos.x, m_Vertex.pos.y,
        m_Vertex.size.x, m_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f,
        D3DXCOLOR(1.0f, 1.0f, 1.0f, m_Vertex.alpha));
}

bool StageObject_001::IsClick(void)
{
    return false;
}

void StageObject_001::ClickUpdate(void)
{
}

bool StageObject_001::IsMouseOver(void)
{
    return false;
}

void StageObject_001::MouseOverUpdate(void)
{
}
