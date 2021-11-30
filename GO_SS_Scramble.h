#pragma once
#include "GameObject.h"

class GO_SS_Player;

struct VERTEX_SCRAMBLE :VERTEX_NOMAL {
    bool use;

    FLOAT angle;

    D3DXCOLOR color;
};

class GO_SS_Scramble :
    public GameObject
{
public:
    // GameObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override { return m_GameScene; }

    void SetScrambleAngle(float angle) { Vortex_Vertex.angle = angle; }

    D3DXVECTOR2 GetScramblePos(){return Vortex_Vertex.pos;}

    void SetPos(D3DXVECTOR2 pos) { Vortex_Vertex.pos = pos; }

    FLOAT GetPreviousDiff(void);

private:
    char TEX_NAME[128] = "data/TEXTURE/natto.png";

    int Scramble_texture;

    const int m_GameScene = GAMESCENE_GAME_TEST;

    VERTEX_SCRAMBLE Vortex_Vertex;


    D3DXVECTOR2 m_PrePos;
    D3DXVECTOR2 m_CurPos;
    
   

};

