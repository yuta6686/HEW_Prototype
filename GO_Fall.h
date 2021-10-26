//----------------------------------------------------------------------------
//  プレイヤーが落ちる処理　[GO_Fall.h]
//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------

#pragma once
#include "GameObject.h"
class GO_Fall :
    public GameObject
{
public:
    // GameObject を介して継承されました
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) { return GAMESCENE_FALL; }

private:

    int nowTexture = 0;

    int Texture_Fall = 0;
    char TEX_NAME_FALL[64] = "data/TEXTURE/fall.png";

    int Texture_Walk = 0;
    char TEX_NAME_WALK[64] = "data/TEXTURE/walk.png";

    const int GAME_SCENE = GAMESCENE_FALL;

    VERTEX_ANIMATION_USE Fall_Vertex;
};

