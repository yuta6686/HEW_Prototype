#pragma once
#include "GameObject.h"
class GO_SS_BackGround :
    public GameObject
{
public:


    // GameObject を介して継承されました
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override {  return GAME_SCENE;  }

private:
    //テクスチャ用変数
    int BackGround_Texture;
    char TEX_NAME[128] = "data/TEXTURE/mati.png";

    //ゲームシーン用変数
    const int GAME_SCENE = GAMESCENE_BUNGEE_JUMP;

    VERTEX_BACKGROUND BackGround_Vertex;

    const FLOAT UC_SCROLL = 0.001f;
};

