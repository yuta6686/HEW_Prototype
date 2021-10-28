#pragma once
#include "GameObject.h"

class GO_SS_Player :
    public GameObject
{
public:
    // GO_ShootString ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    // GO_ShootString ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
    virtual int GetGameScene(void) override { return GAME_SCENE; }


private:
    //ƒQ[ƒ€ƒV[ƒ“
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

protected:

};

