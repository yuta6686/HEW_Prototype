#pragma once
#include "GameObject.h"
class GO_Natto :
    public GameObject
{
public:
    // GameObject を介して継承されました
    virtual void Initialize(void) override;
    virtual void Finalize(void) override;
    virtual void Update(void) override;
    virtual void Draw(void) override;
    virtual int GetGameScene(void) override { return GAME_SCENE; }
private:
    int Natto_Texture;
    char TEX_NAME[128] = "data/TEXTURE/納豆.png";
    const int GAME_SCENE = GAMESCENE_SCRAMBLE;
   
};

