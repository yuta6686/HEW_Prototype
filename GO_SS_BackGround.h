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


    void AddU(void) { BackGround_Vertex.u += UV_SCROLL; }   //加算   u + UV_SCROLL
    void SubU(void) { BackGround_Vertex.u -= UV_SCROLL; }   //減算   u - UV_SCROLL

private:
    //テクスチャ用変数
    int BackGround_Texture;
    char TEX_NAME[128] = "data/TEXTURE/mati.png";

    //ゲームシーン用変数
    const int GAME_SCENE = GAMESCENE_BUNGEE_JUMP;

    //頂点座標
    VERTEX_BACKGROUND BackGround_Vertex;

    const FLOAT UV_SCROLL = 0.001f;
};

