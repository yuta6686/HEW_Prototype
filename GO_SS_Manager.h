#pragma once
#include "GameObject.h"
class GO_ShootString;
class GO_SS_Player;
class GO_SS_Wall;

class GO_SS_Manager :
    public GameObject
{
public:
    GO_SS_Manager();
    ~GO_SS_Manager();

    // GameObject を介して継承されました
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override { return GAME_SCENE; }

    void Register(GameObject* pSSObject);

private:
    //ゲームシーン
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    static const int SS_GAMEOBJECT_MAX = 50;

    GameObject* m_ssGameObject[SS_GAMEOBJECT_MAX];
    GO_SS_Player* mp_ssPlayer;
    GO_SS_Wall* mp_ssWall;

    //nullptr代入ー＞newで動的生成ー＞Register登録をまとめてやる場所。
    //コンストラクタで使用
    void Create();

    //他のゲームフレームワークに干渉したい場合使用
    void SetGameObject();
};

