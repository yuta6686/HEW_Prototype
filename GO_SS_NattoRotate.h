#pragma once
#include "GameObject.h"
#include "NRO_Natto.h"

class GO_SS_NattoRotate :
    public GameObject
{
public:
    GO_SS_NattoRotate();
    virtual ~GO_SS_NattoRotate();

    // GameObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override;

    void SetNatto(void);

    void SetPos(D3DXVECTOR2 pos);
private:


    static const int NATTO_ROTATE_OBJECT_MAX = 10;
    NattoRotateObject* m_pNattoRotateObjects[NATTO_ROTATE_OBJECT_MAX];

};

