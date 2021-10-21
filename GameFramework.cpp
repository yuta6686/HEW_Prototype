//---------------------------
//	[GameFramework.cpp]
//	Yuta Yanagisawa 
//---------------------------

#include "GameFramework.h"
#include "GameObject.h"
#include "GO_Player.h"
#include "GO_Vortex.h"
#include "GO_VortexRotation.h"

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
	}


	//new
	{
		mp_player = new GO_Player;
		mp_vortex = new GO_Vortex;
		mp_VoRot = new GO_VortexRotation;
	}

	//Register
	{
		Register(mp_vortex);
		Register(mp_player);
		Register(mp_VoRot);
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
		// nullptrÇdeleteÇµÇƒÇ‡ëÂè‰ïv
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
	//GameScene.héQè∆ÇµÇƒÇ≠ÇæÇ≥Ç¢
	for (int i = m_GameScene.GameSceneSelect[m_GameScene.m_GameScene][0]; 
		i < m_GameScene.GameSceneSelect[m_GameScene.m_GameScene][1]; i++) {
		if (m_pGameObjects[i]) {
			m_pGameObjects[i]->Update();
		}
	}
}
void GameFramework::Draw(void)
{
	//GameScene.héQè∆ÇµÇƒÇ≠ÇæÇ≥Ç¢
	for (int i = m_GameScene.GameSceneSelect[m_GameScene.m_GameScene][0];
		i < m_GameScene.GameSceneSelect[m_GameScene.m_GameScene][1]; i++) {
		if (m_pGameObjects[i]) {
			m_pGameObjects[i]->Draw();
		}
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

