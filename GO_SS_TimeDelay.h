#pragma once
#include "GameObject.h"
class GO_SS_TimeDelay :
    public GameObject
{
public:
    virtual void Initialize(void) override {}

    virtual void Finalize(void) override {}

    virtual void Update(void) override {}

    virtual void Draw(void) override {}

    virtual int GetGameScene(void) override { return GAMESCENE_GAME_TEST; }



    void SetTimeDelay(bool flag) { m_TimeDelayFlag = flag; }
    bool GetTimeDelayFlag(void) { return m_TimeDelayFlag; }

    FLOAT GetTimeDelay(void) { return m_TimeDelay; }




private:
    bool m_TimeDelayFlag = false;

    const FLOAT TIME_DELAY_VALUE = 0.3f;

    float m_TimeDelay = 1.0f;
};

