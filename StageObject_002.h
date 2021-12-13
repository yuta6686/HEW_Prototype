#pragma once
#include "StageObject_001.h"
class StageObject_002 :
    public StageObject_001
{
public:
    virtual HRESULT Init(void) override;
    virtual void    Draw(void) override;
    virtual void ClickUpdate(void) override;

private:
    char m_TextureName[64] = "data/TEXTURE/wall.png";
    int  m_TextureIndex;
};

