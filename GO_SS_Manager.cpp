#include "GO_SS_Manager.h"
#include "GO_SS_Player.h"
#include "GO_SS_Wall.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_Movement.h"
#include "GO_SS_Target.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Collision.h"
#include "GO_SS_FileLoad.h"
#include "GO_SS_Map.h"
#include "GO_SS_Effect_Wind.h"
#include "GO_SS_Scramble.h"
#include "GO_SS_Timer.h"
/*---------------------------------------------
				?R???X?g???N?^
---------------------------------------------*/
GO_SS_Manager::GO_SS_Manager()
{
	for (int i = 0; i < GAMESCENE_GAME_TEST; i++) {
		m_ssGameObject[i] = nullptr;
	}

	Create();
}

/*---------------------------------------------
				?N???G?C?g
-----------------------------------------------
	?|?C???^???????A?????A???W?X?^?[
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
		mp_ssMap = nullptr;
		mp_ssEffWind = nullptr;
		mp_ssScramble = nullptr;
		mp_ssTimer = nullptr;
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
		mp_ssMap = new GO_SS_Map;
		mp_ssEffWind = new GO_SS_Effect_Wind;
		mp_ssScramble = new GO_SS_Scramble;
		mp_ssTimer = new GO_SS_Timer;
	}

	//Register
	{
		Register(mp_ssBackGround);
		Register(mp_ssTimer);
		Register(mp_ssScramble);
		Register(mp_ssPlayer);
		Register(mp_ssWall);
		Register(mp_ssMovement);
		Register(mp_ssTarget);
		Register(mp_ssShotString);
		Register(mp_ssFileLoad);
		Register(mp_ssMap);
		Register(mp_ssEffWind);
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
		mp_ssMovement->SetMap(mp_ssMap);
		mp_ssMovement->SetEffWind(mp_ssEffWind);

		mp_ssShotString->SetPlayer(mp_ssPlayer);
		mp_ssShotString->SetTarget(mp_ssTarget);

		mp_ssMap->SetFileLoad(mp_ssFileLoad);
		mp_ssMap->SetWall(mp_ssWall);
		mp_ssMap->SetTarget(mp_ssTarget);

		mp_ssScramble->SetPlayer(mp_ssPlayer);
	}
}
/*---------------------------------------------
*				?f?X?g???N?^
---------------------------------------------*/
GO_SS_Manager::~GO_SS_Manager()
{
	for (int i = 0; i < SS_GAMEOBJECT_MAX; i++) {
		// nullptr??delete???????v
		delete m_ssGameObject[i];
	}
}
/*---------------------------------------------
*				??????????
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
*				?I??????
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
*				?X?V????
---------------------------------------------*/
void GO_SS_Manager::Update(void)
{
	for (int i = 0; i < SS_GAMEOBJECT_MAX; i++) {
		if (!m_ssGameObject[i])continue;

		m_ssGameObject[i]->Update();
	}

	
}
/*---------------------------------------------
*				?`????
---------------------------------------------*/
void GO_SS_Manager::Draw(void)
{
	for (int i = 0; i < SS_GAMEOBJECT_MAX; i++) {
		if (!m_ssGameObject[i])continue;
		m_ssGameObject[i]->Draw();

	}
}
/*---------------------------------------------
*				?o?^????
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





