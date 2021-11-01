#pragma once
#include "GameObject.h"

struct VERTEX_TARGET : public VERTEX_NOMAL {
    //自由に追加して使って
    //bool use 
};

class GO_SS_Target :
    public GameObject
{
public:
    // GameObject を介して継承されました
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override { return GAME_SCENE; }


private:
    //ゲームシーン
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    //テクスチャ用変数


    //
    static const int TARGET_NUM_MAX = 50;
    VERTEX_TARGET Target_Vertex[TARGET_NUM_MAX];
};

