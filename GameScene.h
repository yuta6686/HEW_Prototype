#pragma once
//---------------------------
//	[GameScene.h]
//	Yuta Yanagisawa 
//---------------------------

//ゲーム内でのシーン遷移を管理します。


enum GAMESCENE{
    GAMESCENE_NONE,
    GAMESCENE_SCRAMBLE,       //納豆混ぜるシーン
    GAMESCENE_BUNGEE_JUMP,  //バンジージャンプのシーン
    GAMESCENE_MAX
};

class GameScene
{
public:
    virtual void Initialize(void) = 0;
    virtual void Finalize(void) = 0;
    virtual void Update(void) = 0;
    virtual void Draw(void) = 0;
};

