#include "GS_Scramble.h"
#include "GameFramework.h"
#include "GameObject.h"
#include "GO_Player.h"
#include "GO_Scramble.h"
#include "GO_ScrambleRotation.h"
#include "GO_Throw.h"
#include "GO_Timer.h"

void GS_Scramble::Initialize(void)
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		m_pGameObjects[i] = nullptr;
	}

	Create();
}

void GS_Scramble::Finalize(void)
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		if (m_pGameObjects[i]) {
			m_pGameObjects[i]->Finalize();
		}
	}
}

void GS_Scramble::Update(void)
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		if (!m_pGameObjects[i])continue;
		if (m_pGameObjects[i]->GetGameScene() != m_GameScene)continue;

		m_pGameObjects[i]->Update();

	}
}

void GS_Scramble::Draw(void)
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		if (!m_pGameObjects[i])continue;
		if (m_pGameObjects[i]->GetGameScene() != m_GameScene)continue;
		m_pGameObjects[i]->Draw();

	}
}

void GS_Scramble::Register(GameObject* pGameObject)
{
	for (int i = 0; i < GAME_OBJECT_MAX; i++) {
		if (!m_pGameObjects[i]) {
			m_pGameObjects[i] = pGameObject;
			break;
		}
	}
}

void GS_Scramble::Create()
{//null
	{
		mp_player = nullptr;
		mp_vortex = nullptr;
		mp_VoRot = nullptr;

		/*ここで新しいゲームオブジェクトのポインタを初期化する*/

		mp_Throw = nullptr;
		mp_Timer = nullptr;
	}


	//new
	{
		mp_player = new GO_Player;
		mp_vortex = new GO_Scramble;
		mp_VoRot = new GO_ScrambleRotation;

		/*ゲームオブジェクト動的生成*/

		mp_Throw = new GO_Throw;
		mp_Timer = new GO_Timer;
	}

	//Register
	{
		Register(mp_vortex);
		Register(mp_player);
		Register(mp_VoRot);

		/*GameObjectクラスを継承してれば、登録できます。*/

		Register(mp_Throw);
		Register(mp_Timer);
	}

}

void GS_Scramble::SetGameObject()
{
	mp_VoRot->SetPlayer(mp_player);
	mp_VoRot->SetVortex(mp_vortex);
}
