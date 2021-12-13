//=============================================================================
//
// タイトル画面処理 [title.cpp]
// Author : 
//
//=============================================================================
#include "title.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "GO_SS_Player.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static int				g_TextureNo[5] = { 0,0,0,0,0 };	// テクスチャ情報
static VERTEX_TITLE_PLAYER g_Player;

int i = 0;

static const FLOAT GRAVITY_ACCELERATION = 0.3f;

static FLOAT m_Jump = -10.75f;
static FLOAT g_gravity = 1.0f;


//=============================================================================
// 初期化処理
//=============================================================================
HRESULT InitTitle(void)
{
	TO_Init();

	//テクスチャ生成
	g_TextureNo[0] = LoadTexture("data/TEXTURE/title.png");
	g_TextureNo[1] = LoadTexture("data/TEXTURE/mati1.png");//ビル群
	g_TextureNo[2] = LoadTexture("data/TEXTURE/target.png");//フック
	g_TextureNo[3] = LoadTexture("data/TEXTURE/jump2.png");//
	g_TextureNo[4] = LoadTexture("data/TEXTURE/title.png");

	g_Player.angle = 0.0f;
	g_Player.frame = 0;
	g_Player.pos = D3DXVECTOR2(-80.0f, SCREEN_HEIGHT/7.5f);
	g_Player.size = D3DXVECTOR2(0.0f, 0.0F);
	g_Player.u = 0.0f;
	g_Player.v = 0.0f;
	g_Player.use = true;

	g_gravity *= m_Jump;

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitTitle(void)
{
	TO_Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateTitle(void)
{
	//アニメーションのフレーム処理
	if (g_Player.frame >= PLAYER_X_NUM * PLAYER_Y_NUM)
	{
		g_Player.frame = 0;
	}
	else {
		if (i == 20) {
			g_Player.frame++;
			i = 0;
		}
		else
			i++;
	}
	if (g_Player.use) {
		g_Player.u = g_Player.frame % PLAYER_X_NUM * PLAYER_WIDTH;
		g_Player.v = g_Player.frame / PLAYER_Y_NUM * PLAYER_HEIGHT;
	}


	TO_Update();

	//シーン遷移
	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_SELECT_STAGE);
	}


	//プレイヤーのx方向の動き
	if (g_Player.pos.x >= SCREEN_WIDTH/ 2.0f + 200.0f) {
		g_Player.pos.x = SCREEN_WIDTH / 2.0f + 200.0f;
	}
	else {
		g_Player.pos.x += 11.0f;
	}
	
	//プレイヤーy方向の動き
	if (g_Player.pos.y >= SCREEN_HEIGHT / 2.0f + 75.0f) {
		g_Player.pos.y = SCREEN_HEIGHT / 2.0f + 75.0f;


	}
	else {
		g_gravity += GRAVITY_ACCELERATION;
		g_Player.pos.y += g_gravity;
	}
	
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawTitle(void)
{
	TO_Draw();

	// １枚のポリゴンの頂点とテクスチャ座標を設定
	DrawSprite(g_TextureNo[1], SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.75,
		SCREEN_WIDTH, 749.6727f,
		0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(g_TextureNo[2], SCREEN_WIDTH * 0.7, 0.0f,
		400, 400,
		0.0f, 0.0f, 0.8f, 1.0f);

	//プレイヤー
	DrawSpriteLeftTop(g_TextureNo[3], g_Player.pos.x, g_Player.pos.y,
		186, 223,
		g_Player.u, g_Player.v, PLAYER_WIDTH, PLAYER_HEIGHT);


}


