#pragma once
//---------------------------
//	[GameFramework.h]
//	Yuta Yanagisawa 
//---------------------------
#include "GameScene.h"
#include <memory>

//------前方宣言
class GameObject;
class Enemy;
class GO_Player;
class Collision;
class GO_Scramble;
class GO_ScrambleRotation;
class GO_Throw;
class GO_Timer;

//クラス　ゲームフレームワーク
class GameFramework {
public:
	GameFramework();
	~GameFramework();

	void Initialize(void);
	void Finalize(void);
	void Update(void);
	void Draw(void);

private:
	std::unique_ptr<GameScene> nowScene;
};
