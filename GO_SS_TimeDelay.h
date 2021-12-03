#pragma once
#include "GameObject.h"
class GO_SS_TimeDelay :
    public GameObject
{
public:
    virtual void Initialize(void) override {};

    virtual void Finalize(void) override {};

    virtual void Update(void) override {};

    virtual void Draw(void) override {};

    virtual int GetGameScene(void) override {};



    void SetTimeDelay(bool flag) { m_TimeDelayFlag = flag; }

    FLOAT GetTimeDelay(void) { return m_TimeDelay; }

    void TimeDelayManagement(void) {
        if (m_TimeDelayFlag) m_TimeDelay = TIME_DELAY_VALUE;
        else m_TimeDelay = 1.0f;
    }


private:
    bool m_TimeDelayFlag = false;

    const FLOAT TIME_DELAY_VALUE = 0.3f;

    float m_TimeDelay = 1.0f;
};

