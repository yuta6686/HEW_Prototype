#include "Spotlight.h"
#include "Texture.h"
#include "sprite.h"

void Spotlight::Init()
{
	m_TexIndex = LoadTexture(m_TexName);
}

void Spotlight::Draw(D3DXVECTOR2 pos)
{
	if (!m_Illuminate)return;

	SetBlendState(BLEND_MODE_ADD);

	DrawSpriteColor(m_TexIndex, pos.x, pos.y, SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 * 2,
		1.0f, 1.0f, 1.0f, 1.0f, (D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)));

	SetBlendState(BLEND_MODE_ALPHABLEND);
}
