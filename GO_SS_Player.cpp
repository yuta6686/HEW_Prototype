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
	OkJump = true;
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

	if (IsColl) {
		OkJump = true;
	}

	//キーボード・マウスからの入力をもらってプレイヤーの動きを処理する
	InputPlayerMove();

	

	//プレイヤーのジャンプの動き
	PlayerJumpMove();

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

	if (GetKeyboardTrigger(DIK_SPACE) && OkJump) {
		IsJump = true;
		OkJump = false;
	}
}

//プレイヤーの重力処理
void GO_SS_Player::PlayerGravity(void)
{
	if (IsColl && m_Gravity >= 5.0f)return;

	m_Gravity += GRAVITY_ACCELERATION * m_TimeDelay;
	Player_Vertex.pos.y += m_Gravity * m_TimeDelay;
}

void GO_SS_Player::PlayerJumpMove(void)
{
	if (!IsJump)return;
	m_Gravity = DEFAULT_GRAVITY * m_Jump;
	IsJump = false;
}

