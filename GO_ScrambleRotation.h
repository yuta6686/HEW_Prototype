#pragma once
#include "GameObject.h"
class GO_Player;
class GO_Scramble;

class GO_ScrambleRotation :
    public GameObject
{
public:
    // GameObject を介して継承されました
    virtual void Initialize(void) override { /*変更なし*/ };
    virtual void Finalize(void) override { /*変更なし*/ };
    virtual void Update(void) override ;
    virtual void Draw(void) override { /*変更なし*/ };

    virtual int GetGameScene(void) override { return m_GameScene; }

    void SetPlayer(GO_Player* p_player) { mp_player = p_player; }
    void SetVortex(GO_Scramble* p_vortex) { mp_vortex = p_vortex; }

    
    

private:
    GO_Player* mp_player;
    GO_Scramble* mp_vortex;

    const int m_GameScene = GAMESCENE_SCRAMBLE;
};

