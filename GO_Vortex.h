#pragma once
#include "GameObject.h"


class GO_Vortex :
    public GameObject
{
public:
    // GameObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    void SetVortexAngle(float angle) { Vortex_Vertex.angle = angle; }

    D3DXVECTOR2 GetVortexPos(){return Vortex_Vertex.pos;}

private:
    char TEX_NAME[128] = "data/TEXTURE/Vortex.png";
    int Vortex_texture;

    VERTEX_A Vortex_Vertex;
};

