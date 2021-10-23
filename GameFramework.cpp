//---------------------------
//	[GameFramework.cpp]
//	Yuta Yanagisawa 
//---------------------------

#include "GameFramework.h"
#include "GameObject.h"
#include "GO_Player.h"
#include "GO_Scramble.h"
#include "GO_ScrambleRotation.h"
#include "GO_Throw.h"

GameFramework::GameFramework()
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		m_pGameObjects[i] = nullptr;
	}

	Create();
}

void GameFramework::Create()
{
	//null
	{
		mp_player = nullptr;
		mp_vortex = nullptr;
		mp_VoRot = nullptr;

		/*ここで新しいゲームオブジェクトのポインタを初期化する*/

		mp_Throw = nullptr;
	}


	//new
	{
		mp_player = new GO_Player;
		mp_vortex = new GO_Scramble;
		mp_VoRot = new GO_ScrambleRotation;

		/*ゲームオブジェクト動的生成*/

		mp_Throw = new GO_Throw;
	}

	//Register
	{
		Register(mp_vortex);
		Register(mp_player);
		Register(mp_VoRot);

		/*GameObjectクラスを継承してれば、登録できます。*/

		Register(mp_Throw);
	}

}

void GameFramework::SetGameObject()
{
	mp_VoRot->SetPlayer(mp_player);
	mp_VoRot->SetVortex(mp_vortex);
}


GameFramework::~GameFramework()
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		// nullptrをdeleteしても大丈夫
		delete m_pGameObjects[i];
	}
}

void GameFramework::Initialize(void)
{

	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		if (m_pGameObjects[i]) {
			m_pGameObjects[i]->Initialize();
		}
	}

	SetGameObject();
	
}
void GameFramework::Finalize(void)
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		if (m_pGameObjects[i]) {
			m_pGameObjects[i]->Finalize();
		}
	}
}
void GameFramework::Update(void)
{
	//GameScene.h参照してください
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		if (!m_pGameObjects[i])continue;
		if (m_pGameObjects[i]->GetGameScene() != m_GameScene)continue;
		
		m_pGameObjects[i]->Update();
		
	}
}
void GameFramework::Draw(void)
{
	//GameScene.h参照してください
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		if (!m_pGameObjects[i])continue;
		if (m_pGameObjects[i]->GetGameScene() != m_GameScene)continue;
			m_pGameObjects[i]->Draw();
		
	}
}

void GameFramework::Register(GameObject* pGameObject)
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		if (!m_pGameObjects[i]) {
			m_pGameObjects[i] = pGameObject;
			break;
		}
	}
}

