#pragma once
#include "GameObject.h"
class GO_SS_Wall :
    public GameObject
{
public:

    // GO_ShootString ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override;


    

};

