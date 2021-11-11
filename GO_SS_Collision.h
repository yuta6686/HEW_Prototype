#pragma once
#include "GameObject.h"

class GO_SS_BackGround;
class GO_SS_Player;
class GO_SS_Wall;
class GO_SS_ShotString;
class GO_SS_Target;

class GO_SS_Collision
{
public:
    //セッター
    void SetBackGround(GO_SS_BackGround* p_BackGround) { m_pBackGround = p_BackGround; }
    void SetPlayer(GO_SS_Player* p_Player) { m_pPlayer = p_Player; }
    void SetWall(GO_SS_Wall* pWall) { m_pWall = pWall; }
    void SetShotString(GO_SS_ShotString* p) { m_pShotString = p; }
    void SetTarget(GO_SS_Target* pTarget) { m_pTarget = pTarget; }

    //当たり判定の処理をまとめる
    void CollisionUpdate(void);

private:
    //ポインタ変数
    GO_SS_BackGround* m_pBackGround;
    GO_SS_Player* m_pPlayer;
    GO_SS_Wall* m_pWall;
    GO_SS_ShotString* m_pShotString;
    GO_SS_Target* m_pTarget;
 
//当たり判定         CollisionJudge_ -> CJ_

//プレイヤーと壁
    int CJ_PlayerWall(void);

//当たり判定テンプレート
    bool BBCollision(D3DXVECTOR2 pos1,D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2);

//3つ目以降の引数に入るのがLeftTop                                              ↓                ↓
    bool BBCollision_LeftTop2(D3DXVECTOR2 pos1, D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2);


};

