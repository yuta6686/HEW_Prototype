#pragma once
#include "GameScene.h"

class GameObject;
class Enemy;
class GO_Player;
class Collision;
class GO_Scramble;
class GO_ScrambleRotation;
class GO_Throw;
class GO_Timer;

class GS_Scramble :public GameScene
{
public:
	// GameScene を介して継承されました
	virtual void Initialize(void) override;

	virtual void Finalize(void) override;

	virtual void Update(void) override;

	virtual void Draw(void) override;

	//m_pGameObjects[]にGameObjectを詰め込む
	void Register(GameObject* pGameObject);

private:
	static const int GAME_OBJECT_MAX = 100;

	//GameObjectのポインタ
	GameObject* m_pGameObjects[GAME_OBJECT_MAX];

	GO_Player* mp_player;
	GO_Scramble* mp_vortex;
	GO_ScrambleRotation* mp_VoRot;
	GO_Throw* mp_Throw;
	GO_Timer* mp_Timer;

	//GameScene
	int m_GameScene = GAMESCENE_SCRAMBLE;

	//nullptr代入ー＞newで動的生成ー＞Register登録をまとめてやる場所。
	//コンストラクタで使用
	void Create();

	//他のゲームフレームワークに干渉したい場合使用
	void SetGameObject();
};

