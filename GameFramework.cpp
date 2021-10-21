//---------------------------
//	[GameFramework.cpp]
//	Yuta Yanagisawa 
//---------------------------

#include "GameFramework.h"
#include "GameObject.h"
#include "GO_Player.h"
//#include "GO_Enemy.h"
//#include "GO_Collision.h"

GameFramework::GameFramework()
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		m_pGameObjects[i] = nullptr;
	}
	//mp_enemy = nullptr;
	mp_player = nullptr;
	//mp_collision = nullptr;

	Create();
}

GameFramework::~GameFramework()
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		// nullptr‚ðdelete‚µ‚Ä‚à‘åä•v
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

	//mp_collision->SetEnemy(mp_enemy);
	//mp_collision->SetPlayer(mp_player);
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
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		if (m_pGameObjects[i]) {
			m_pGameObjects[i]->Update();
		}
	}
}
void GameFramework::Draw(void)
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
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

void GameFramework::Create()
{
	//new
	{
		mp_player = new GO_Player;
	}

	//Register
	{
		Register(mp_player);
	}
	
}
