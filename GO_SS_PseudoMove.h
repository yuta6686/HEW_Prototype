#include "GameObject.h"
class GO_SS_BackGround;
class GO_SS_Player;

class GO_SS_PseudoMove :
    public GameObject
{
public:
    // GameObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
    virtual void Initialize(void) override {};
    virtual void Finalize(void) override {};
    virtual void Update(void) override;
    virtual void Draw(void) override {};
    virtual int GetGameScene(void) override { return GAME_SCENE; }

    void SetBackGround(GO_SS_BackGround* p_BackGround) { mp_BackGround = p_BackGround; }
    void SetPlayer(GO_SS_Player* p_Player) { mp_Player = p_Player; }
private:
    //ÉQÅ[ÉÄÉVÅ[Éì
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    GO_SS_BackGround* mp_BackGround;
    GO_SS_Player* mp_Player;
};
