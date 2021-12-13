#pragma once
#include "GO_SS_TimeDelay.h"

class GO_SS_Player :
    public GO_SS_TimeDelay
{
public:
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override { return GAME_SCENE; }

    //?????o???

    D3DXVECTOR2 GetPos() { return Player_Vertex.pos; }
    D3DXVECTOR2 GetSize() { return  Player_Vertex.size; }
    
    void SetPosY(FLOAT y) { Player_Vertex.pos.y = y; }
    

    void SetGravityDefault(void) { m_Gravity = DEFAULT_GRAVITY; }
    void SetGravitysoft(FLOAT f) { m_Gravity -= f; }
    void SetGravity(FLOAT f) { m_Gravity = f; }

    void WavePosPlus(FLOAT angle);
    void WavePosMinus(FLOAT angle);

    void AddXPos(FLOAT x) { Player_Vertex.pos.x += x; }
    void AddYPos(FLOAT y) { Player_Vertex.pos.y += y; }

    bool IsJump;
    bool OkJump;
    bool IsColl;

    //not:-1 left:1 right:2 
    int IsCollSide;


    FLOAT m_TimeDelay = 1.0f;

    
private:
    //GameScene
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    //Texture
    int Player_Texture;
    char TEX_NAME[64] = "data/TEXTURE/fall1.png";

    //Action
    FLOAT m_Gravity;
    FLOAT m_Jump = -12.5f;
    const FLOAT GRAVITY_ACCELERATION = 0.3f;
    const FLOAT DEFAULT_GRAVITY = 1.0f;
    const FLOAT JUMP_DELAY = 12.0f;

    //Vertex Parameter
    VERTEX_PLAYER Player_Vertex;

//?????o???

    //?v???C???[???????????????Gameover??
    void SceneToGameOver(void);

    //?L?[?{?[?h?E?}?E?X??????????????v???C???[??????????????
    void InputPlayerMove(void);

    //?v???C???[??d?????
    void PlayerGravity(void);

    void PlayerJumpMove(void);
    

};

