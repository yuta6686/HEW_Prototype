#include "GO_SS_Manager.h"
#include "GO_SS_Player.h"
#include "GO_SS_Wall.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_Movement.h"
#include "GO_SS_Target.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Collision.h"
#include "GO_SS_FileLoad.h"
/*---------------------------------------------
				コンストラクタ
---------------------------------------------*/
GO_SS_Manager::GO_SS_Manager()
{
	for (int i = 0; i < GAMESCENE_GAME_TEST; i++) {
		m_ssGameObject[i] = nullptr;
	}

	Create();
}

/*---------------------------------------------
				クリエイト
-----------------------------------------------
	ポインタ初期化、生成、レジスター
---------------------------------------------*/
void GO_SS_Manager::Create()
{
	//null
	{
		mp_ssBackGround = nullptr;
		mp_ssPlayer = nullptr;
		mp_ssWall = nullptr;
		mp_ssMovement= nullptr;
		mp_ssTarget = nullptr;
		mp_ssShotString = nullptr;
		mp_ssFileLoad = nullptr;
	}

	//new
	{
		mp_ssBackGround = new GO_SS_BackGround;
		mp_ssPlayer = new GO_SS_Player;
		mp_ssWall = new GO_SS_Wall;
		mp_ssMovement = new GO_SS_Movement;

		mp_ssTarget = new GO_SS_Target;
		mp_ssShotString = new GO_SS_ShotString;
		mp_ssFileLoad = new GO_SS_FileLoad;
	}

	//Register
	{
		Register(mp_ssBackGround);
		Register(mp_ssPlayer);
		Register(mp_ssWall);
		Register(mp_ssMovement);
		Register(mp_ssTarget);
		Register(mp_ssShotString);
		Register(mp_ssFileLoad);
	}
}

/*---------------------------------------------
	SetGameObject()
-----------------------------------------------
	
---------------------------------------------*/
void GO_SS_Manager::SetGameObject()
{
	//mp_ssComunication
	{
		mp_ssMovement->SetBackGround(mp_ssBackGround);
		mp_ssMovement->SetPlayer(mp_ssPlayer);
		mp_ssMovement->SetShotString(mp_ssShotString);
		mp_ssMovement->SetWall(mp_ssWall);
		mp_ssMovement->SetTarget(mp_ssTarget);

		mp_ssShotString->SetPlayer(mp_ssPlayer);
		mp_ssShotString->SetTarget(mp_ssTarget);
	}

}
/*---------------------------------------------
*				デストラクタ
---------------------------------------------*/
GO_SS_Manager::~GO_SS_Manager()
{
	for (int i = 0; i < SS_GAMEOBJECT_MAX; i++) {
		// nullptrをdeleteしても大丈夫
		delete m_ssGameObject[i];
	}
}
/*---------------------------------------------
*				初期化処理
---------------------------------------------*/
void GO_SS_Manager::Initialize(void)
{
	for (int i = 0; i < SS_GAMEOBJECT_MAX; i++) {
		if (m_ssGameObject[i]) {
			m_ssGameObject[i]->Initialize();
		}
	}
	SetGameObject();
}
/*---------------------------------------------
*				終了処理
---------------------------------------------*/
void GO_SS_Manager::Finalize(void)
{
	for (int i = 0; i < SS_GAMEOBJECT_MAX; i++) {
		if (m_ssGameObject[i]) {
			m_ssGameObject[i]->Finalize();
		}
	}
}
/*---------------------------------------------
*				更新処理
---------------------------------------------*/
void GO_SS_Manager::Update(void)
{
	for (int i = 0; i < SS_GAMEOBJECT_MAX; i++) {
		if (!m_ssGameObject[i])continue;

		m_ssGameObject[i]->Update();
	}

	
}
/*---------------------------------------------
*				描画処理
---------------------------------------------*/
void GO_SS_Manager::Draw(void)
{
	for (int i = 0; i < SS_GAMEOBJECT_MAX; i++) {
		if (!m_ssGameObject[i])continue;
		m_ssGameObject[i]->Draw();

	}
}
/*---------------------------------------------
*				登録処理
---------------------------------------------*/
void GO_SS_Manager::Register(GameObject* pSSObject)
{
	for (int i = 0; i < SS_GAMEOBJECT_MAX; i++) {
		if (!m_ssGameObject[i]) {
			m_ssGameObject[i] = pSSObject;
			break;
		}
	}
}





