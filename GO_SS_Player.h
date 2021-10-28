#pragma once
#include "GameObject.h"

class GO_SS_Player :
    public GameObject
{
public:
    // GO_ShootString を介して継承されました
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    // GO_ShootString を介して継承されました
    virtual int GetGameScene(void) override { return GAME_SCENE; }


private:
    //ゲームシーン
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

protected:

};

