#pragma once
#include "StageObject_001.h"
class StageObject_003 :
    public StageObject_001
{
public:
    virtual HRESULT Init(void) override;
    virtual void    Draw(void) override;
    virtual void ClickUpdate(void) override;
    virtual STAGE_NUM ReturnStageNum(void) override { return STAGE_NUM_003; }

private:
    char m_TextureName[64] = "data/TEXTURE/wall.png";
    int  m_TextureIndex;
};

