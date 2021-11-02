#pragma once
#include "GameObject.h"
class GO_SS_Wall :
    public GameObject
{
public:

    // GO_ShootString を介して継承されました
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override;


    void SetWall();
    void SetWall(D3DXVECTOR2 pos);
    void SetWall(D3DXVECTOR2 pos, D3DXVECTOR2 size);

    void SetWallOnce();
private:
    //テクスチャ用変数
    int Wall_Texture;
    char TEX_NAME[128] = "data/TEXTURE/wall.png";

    //ゲームシーン
    const int GAME_SCENE = GAMESCENE_GAME_TEST;
    
    //定数定義
    static const int WALL_NUM_MAX = 100;
    const float WALL_WIDTH = SCREEN_WIDTH / 16.0f;
    const float WALL_HEIGHT = SCREEN_HEIGHT / 9.0f;


    //頂点情報
    VERTEX_WALL m_vWall[WALL_NUM_MAX];

    bool once;
};

