#pragma once
#include "GameObject.h"
class Effect :
    public GameObject
{
public:
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override;

private:


  

};

