#pragma once
#include "StageObject.h"
class StageObjectArrowKey :
    public StageObject
{
public:
    // StageObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
    virtual HRESULT Init(void) override { return E_NOTIMPL; }
    virtual void Uninit(void) override {}
    virtual void Update(void) override;
    virtual void Draw(void) override;

    virtual bool IsClick(void) override { return false; }
    virtual void ClickUpdate(void) override {}

    virtual bool IsMouseOver(void) override { return false; }
    virtual void MouseOverUpdate(void) override {}

    virtual STAGE_NUM ReturnStageNum(void) override;

    virtual int GetStageNumSelect(void) { return m_StageNumSelect; }

private:
    virtual int IsArrowKeyTriggerd(void);
    virtual void ArrowKeyUpdate(void);

    virtual bool IsEnterTriggerd(void);
    virtual void EnterUpdate(void);

    virtual void SetStageNumSelect(STAGE_NUM stageNum) { m_StageNumSelect = stageNum; }
    virtual void StageNumAdd(void) { m_StageNumSelect++; }
    virtual void StageNumSub(void) { m_StageNumSelect--; }

    int m_ArrowKey = ARROW_KEY_NONE;
    int m_StageNumSelect = STAGE_NUM_NONE;
};

