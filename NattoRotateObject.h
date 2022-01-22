#pragma once
#include "GameObject.h"
class NattoRotateObject :
    public GameObject
{
protected:
    static const int NATTO_MAX = 50;
    static const int FIRST_NATTO = 10;

    const FLOAT ANGLE_MIN = 0.0f;
    const FLOAT ANGLE_MAX = 0.1f;

public:    
    NattoRotateObject(char* texName){
        m_TexIndex = LoadTexture(texName);
    }

    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override { return GAMESCENE_GAME_TEST; }

    virtual int GetTexIndex(void) { return m_TexIndex; }

    void SetPos(D3DXVECTOR2 pos) { m_PlayerPos = pos; }
    void SetNatto(void);
protected:
    int m_TexIndex;

    

    VERTEX_NATTO m_Vertex[NATTO_MAX];

    D3DXVECTOR2 m_PlayerPos = D3DXVECTOR2(0.0f, 0.0f);

//  ÉÅÉìÉoä÷êî
    void Rotation(int index);

    FLOAT frand();
    FLOAT frand_r();
};

