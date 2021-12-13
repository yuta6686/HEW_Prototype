#pragma once
#include "StageObject.h"
class StageObject_001 :
    public StageObject
{
public:
    StageObject_001() {};  

    // StageObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
    virtual HRESULT Init(void) override;

    virtual void Uninit(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual bool IsClick(void) override;

    virtual void ClickUpdate(void) override;

    virtual bool IsMouseOver(void) override;

    virtual void MouseOverUpdate(void) override;

protected:
    D3DXVECTOR2 m_MousePos;

private:
    char m_TextureName[64] = "data/TEXTURE/wall.png";
    int  m_TextureIndex;

    // StageObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
    virtual STAGE_NUM ReturnStageNum(void) override { return STAGE_NUM_001; }
};

