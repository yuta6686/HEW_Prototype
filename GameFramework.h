#pragma once
//---------------------------
//	[GameFramework.h]
//	Yuta Yanagisawa 
//---------------------------
#include "GameScene.h"

//------前方宣言
class GameObject;
class Enemy;
class GO_Player;
class Collision;
class GO_Scramble;
class GO_ScrambleRotation;
class GO_Throw;

//クラス　ゲームフレームワーク
class GameFramework {
public:
	GameFramework();
	~GameFramework();

	void Initialize(void);
	void Finalize(void);
	void Update(void);
	void Draw(void);

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

	//GameScene
	int m_GameScene = GAMESCENE_BUNGEE_JUMP;

	//nullptr代入ー＞newで動的生成ー＞Register登録をまとめてやる場所。
	//コンストラクタで使用
	void Create();

	//他のゲームフレームワークに干渉したい場合使用
	void SetGameObject();
};
