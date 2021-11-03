#include "GO_SS_Player.h"
#include "GO_SS_Wall.h"
#include "fade.h"
#include <cmath>
/*---------------------------------------------
*				初期化処理
---------------------------------------------*/
void GO_SS_Player::Initialize(void)
{
	Player_Texture = LoadTexture(TEX_NAME);

	Player_Vertex.pos = D3DXVECTOR2(SCREEN_WIDTH / 4, 100.0f);
	Player_Vertex.size = D3DXVECTOR2(200.0f, 200.0f);
	Player_Vertex.delay = 1.0f;

	m_Gravity = DEFAULT_GRAVITY;
	IsJump = false;
	IsColl = false;
}
/*---------------------------------------------
*				終了処理
---------------------------------------------*/
void GO_SS_Player::Finalize(void)
{

}
/*---------------------------------------------
*				更新処理
---------------------------------------------*/
void GO_SS_Player::Update(void)
{
	//プライヤーが画面下に落ちたらGameoverへ
	SceneToGameOver();

	//キーボード・マウスからの入力をもらってプレイヤーの動きを処理する
	InputPlayerMove();

	//プレイヤーの重力処理
	PlayerGravity();

	
}
/*---------------------------------------------
*				描画処理
---------------------------------------------*/
void GO_SS_Player::Draw(void)
{
	DrawSprite(Player_Texture, Player_Vertex.pos.x, Player_Vertex.pos.y,
		Player_Vertex.size.x, Player_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f);
}



//	クリックしたときのプレイヤーの挙動
//	カーソルがプレイヤーより右のときの処理
void GO_SS_Player::WavePosPlus(FLOAT angle)
{
	FLOAT posx = Player_Vertex.pos.x;
	FLOAT posy = Player_Vertex.pos.y;
	FLOAT centerx = (SCREEN_WIDTH / 4.0f - posx);

	Player_Vertex.pos.y -= (posy / 5.0f) * sinf(angle);
	Player_Vertex.pos.x += (centerx / 10.0f) * cosf(angle);
}

//	クリックしたときのプレイヤーの挙動
//	カーソルがプレイヤーより左のときの処理
void GO_SS_Player::WavePosMinus(FLOAT angle)
{
	FLOAT posx = Player_Vertex.pos.x;
	FLOAT posy =  Player_Vertex.pos.y;
	FLOAT centerx = (SCREEN_WIDTH / 4.0f - posx);

	Player_Vertex.pos.y -= (posy / 5.0f) * sinf(angle);
	Player_Vertex.pos.x -= (centerx / 10.0f) * cosf(angle);
}

//プライヤーが画面下に落ちたらGameoverへ
void GO_SS_Player::SceneToGameOver(void)
{
	//プライヤーが画面したにいる、フェード処理中ではないとき
	if (GetPos().y >= SCREEN_HEIGHT && GetFadeState() == FADE_NONE) {

		//GAMEOVERへ移行する
		SceneTransition(SCENE_GAMEOVER);
	}
}

//キーボード・マウスからの入力をもらってプレイヤーの動きを処理する
void GO_SS_Player::InputPlayerMove(void)
{

	if (GetKeyboardTrigger(DIK_SPACE) && Player_Vertex.pos.y >= SCREEN_HEIGHT / 4) {
		IsJump = true;
		m_Gravity = DEFAULT_GRAVITY * m_Jump;
		Player_Vertex.pos.y += m_Gravity;
	}

	if (GetKeyboardPress(DIK_A)) {
		Player_Vertex.pos.x -= 4.0f;
	}

	if (GetKeyboardPress(DIK_D)) {
		Player_Vertex.pos.x += 4.0f;
	}
}

//プレイヤーの重力処理
void GO_SS_Player::PlayerGravity(void)
{
	if (IsColl)return;
	m_Gravity += GRAVITY_ACCELERATION;
	Player_Vertex.pos.y += m_Gravity;
}







