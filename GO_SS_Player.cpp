#include "GO_SS_Player.h"
#include "GO_SS_Wall.h"
#include <cmath>
/*---------------------------------------------
*				èâä˙âªèàóù
---------------------------------------------*/
void GO_SS_Player::Initialize(void)
{
	Player_Texture = LoadTexture(TEX_NAME);

	Player_Vertex.pos = D3DXVECTOR2(SCREEN_WIDTH / 4, -100.0f);
	Player_Vertex.size = D3DXVECTOR2(200.0f, 200.0f);
	Player_Vertex.delay = 1.0f;

	m_Gravity = DEFAULT_GRAVITY;
	IsJump = false;
}
/*---------------------------------------------
*				èIóπèàóù
---------------------------------------------*/
void GO_SS_Player::Finalize(void)
{

}
/*---------------------------------------------
*				çXêVèàóù
---------------------------------------------*/
void GO_SS_Player::Update(void)
{
	
	if (GetKeyboardTrigger(DIK_SPACE) && Player_Vertex.pos.y >= SCREEN_HEIGHT / 4) {
		IsJump = true;
		m_Gravity = DEFAULT_GRAVITY * m_Jump;
	}
	
	if (GetKeyboardPress(DIK_A)) {
		Player_Vertex.pos.x -= 4.0f;
	}

	if (GetKeyboardPress(DIK_D)) {
		Player_Vertex.pos.x += 4.0f;
	}

	m_Gravity += GRAVITY_ACCELERATION;
	Player_Vertex.pos.y += m_Gravity;
}
/*---------------------------------------------
*				ï`âÊèàóù
---------------------------------------------*/
void GO_SS_Player::Draw(void)
{
	DrawSprite(Player_Texture, Player_Vertex.pos.x, Player_Vertex.pos.y,
		Player_Vertex.size.x, Player_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f);
}

void GO_SS_Player::WavePos(FLOAT angle)
{
	FLOAT posx = Player_Vertex.pos.x;
	FLOAT posy = Player_Vertex.pos.y;
	FLOAT centerx = (SCREEN_WIDTH / 2.0f - posx);

	Player_Vertex.pos.y -= (posy / 7.0f) * (sinf(angle));
	Player_Vertex.pos.x += (centerx / 7.0f) * cosf(angle);
}





