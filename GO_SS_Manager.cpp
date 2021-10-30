#include "GO_SS_Manager.h"
#include "GO_SS_Player.h"
#include "GO_SS_Wall.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_PseudoMove.h"
#include "GO_SS_Target.h"
#include "GO_SS_ShotString.h"

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
		mp_ssPseudoMove= nullptr;
		mp_ssTarget = nullptr;
		mp_ssShotString = nullptr;
	}

	//new
	{
		mp_ssBackGround = new GO_SS_BackGround;
		mp_ssPlayer = new GO_SS_Player;
		mp_ssWall = new GO_SS_Wall;
		mp_ssPseudoMove = new GO_SS_PseudoMove;

		mp_ssTarget = new GO_SS_Target;
		mp_ssShotString = new GO_SS_ShotString;
	}

	//Register
	{
		Register(mp_ssBackGround);
		Register(mp_ssPlayer);
		Register(mp_ssWall);
		Register(mp_ssPseudoMove);
		Register(mp_ssTarget);
		Register(mp_ssShotString);
	}
}

/*---------------------------------------------
	SetGameObject()
-----------------------------------------------
	ディスパッチシステムを使うので使用するかわからない。
---------------------------------------------*/
void GO_SS_Manager::SetGameObject()
{
	mp_ssPseudoMove->SetBackGround(mp_ssBackGround);
	mp_ssPseudoMove->SetPlayer(mp_ssPlayer);
	mp_ssPseudoMove->SetWall(mp_ssWall);

	mp_ssShotString->SetPlayer(mp_ssPlayer);
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





