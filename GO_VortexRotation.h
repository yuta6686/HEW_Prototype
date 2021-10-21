#pragma once
#include "GameObject.h"
class GO_Player;
class GO_Vortex;

class GO_VortexRotation :
    public GameObject
{
public:
    // GameObject ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
    virtual void Initialize(void) override { /*•ÏX‚È‚µ*/ };
    virtual void Finalize(void) override { /*•ÏX‚È‚µ*/ };
    virtual void Update(void) override ;
    virtual void Draw(void) override { /*•ÏX‚È‚µ*/ };

    void SetPlayer(GO_Player* p_player) { mp_player = p_player; }
    void SetVortex(GO_Vortex* p_vortex) { mp_vortex = p_vortex; }

private:
    GO_Player* mp_player;
    GO_Vortex* mp_vortex;
};

