#pragma once
#include "GameObject.h"

class GO_SS_Player :
    public GameObject
{
public:
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override { return GAME_SCENE; }

    //ÉÅÉìÉoä÷êî

    D3DXVECTOR2 GetPos() { return Player_Vertex.pos; }

    void SetGravityDefault(void) { m_Gravity = DEFAULT_GRAVITY; }

    void WavePosPlus(FLOAT angle);
    void WavePosMinus(FLOAT angle);

    bool IsJump;

private:
    //GameScene
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    //Texture
    int Player_Texture;
    char TEX_NAME[64] = "data/TEXTURE/fall1.png";

    //Action
    FLOAT m_Gravity;
    FLOAT m_Jump = -15.0f;
    const FLOAT GRAVITY_ACCELERATION = 0.3f;
    const FLOAT DEFAULT_GRAVITY = 1.0f;

    //Vertex Parameter
    VERTEX_PLAYER Player_Vertex;
protected:

};

