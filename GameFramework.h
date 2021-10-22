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
class GO_Vortex;
class GO_VortexRotation;

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
	GO_Vortex* mp_vortex;
	GO_VortexRotation* mp_VoRot;

	//GameScene
	GameScene m_GameScene;

	//nullptr代入ー＞newで動的生成ー＞Register登録をまとめてやる場所。
	//コンストラクタで使用
	void Create();

	//他のゲームフレームワークに干渉したい場合使用
	void SetGameObject();
};
