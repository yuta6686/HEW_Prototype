#pragma once
#include "GameObject.h"

class GO_SS_BackGround;
class GO_SS_Player;
class GO_SS_Goal;
class GO_SS_Wall;
class GO_SS_ShotString;
class GO_SS_Target;
class GO_SS_ZipLine;

class GO_SS_Collision
{
public:
    //?Z?b?^?[
    void SetBackGround(GO_SS_BackGround* p_BackGround) { m_pBackGround = p_BackGround; }
    void SetPlayer(GO_SS_Player* p_Player) { m_pPlayer = p_Player; }
    void SetGoal(GO_SS_Goal* p_Goal) { m_pGoal = p_Goal; }
    void SetWall(GO_SS_Wall* pWall) { m_pWall = pWall; }
    void SetShotString(GO_SS_ShotString* p) { m_pShotString = p; }
    void SetTarget(GO_SS_Target* pTarget) { m_pTarget = pTarget; }
    void SetZipLine(GO_SS_ZipLine* p) { m_pZipLine = p; }

    //??????????????????
    void CollisionUpdate(void);

private:
    //メンバ変数
    D3DXVECTOR2 playerPos;
    D3DXVECTOR2 playerSize;

    VERTEX_T Goal_Vertex;

    
    //?|?C???^???
    GO_SS_BackGround* m_pBackGround;
    GO_SS_Player* m_pPlayer;
    GO_SS_Goal* m_pGoal;
    GO_SS_Wall* m_pWall;
    GO_SS_ShotString* m_pShotString;
    GO_SS_Target* m_pTarget;
    GO_SS_ZipLine* m_pZipLine;
 
//????????         CollisionJudge_ -> CJ_

//?v???C???[???
    int CJ_PlayerWall(void);
    int CJ_PWSide(void);
     

//????????e???v???[?g
    bool BBCollision(D3DXVECTOR2 pos1,D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2);

//3????~????????????LeftTop                                              ??                ??
    bool BBCollision_LeftTop2(D3DXVECTOR2 pos1, D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2);

    void DebugOut(void);
    void CJ_GoalPlayer(void);
};

