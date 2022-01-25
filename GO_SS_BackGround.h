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

    void AddU(FLOAT add) { BackGround_Vertex.u += add; }
    void SubU(FLOAT sub) { BackGround_Vertex.u -= sub; }

private:
    void AddU(void) { BackGround_Vertex.u += UV_SCROLL; }
    void SubU(void) { BackGround_Vertex.u -= UV_SCROLL; }

    //テクスチャ用変数
    int BackGround_Texture;
    char TEX_NAME[128] = "data/TEXTURE/mati.png";

    char* TEX_NAME_MORNING = "data/TEXTURE/morning.png";
    char* TEX_NAME_NOON = "data/TEXTURE/noon.png";
    char* TEX_NAME_NIGHT = "data/TEXTURE/night.png";

    int m_morning;
    int m_noon;
    int m_night;

    int m_nowTex;

    int CmpTexture;
    char CMP_TEX_NAME[128] = "data/TEXTURE/cmp1.png";

    //ゲームシーン用変数
    const int GAME_SCENE = GAMESCENE_BUNGEE_JUMP;

    //頂点座標
    VERTEX_BACKGROUND BackGround_Vertex;

    const FLOAT UV_SCROLL = 0.001f;
};

