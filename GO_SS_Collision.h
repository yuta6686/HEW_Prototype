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
    //�Z�b�^�[
    void SetBackGround(GO_SS_BackGround* p_BackGround) { m_pBackGround = p_BackGround; }
    void SetPlayer(GO_SS_Player* p_Player) { m_pPlayer = p_Player; }
    void SetWall(GO_SS_Wall* pWall) { m_pWall = pWall; }
    void SetShotString(GO_SS_ShotString* p) { m_pShotString = p; }
    void SetTarget(GO_SS_Target* pTarget) { m_pTarget = pTarget; }

    //�����蔻��̏������܂Ƃ߂�
    void CollisionUpdate(void);

private:
    //�|�C���^�ϐ�
    GO_SS_BackGround* m_pBackGround;
    GO_SS_Player* m_pPlayer;
    GO_SS_Wall* m_pWall;
    GO_SS_ShotString* m_pShotString;
    GO_SS_Target* m_pTarget;
 
//�����蔻��         CollisionJudge_ -> CJ_
    //�v���C���[�ƕ�
    int CJ_PlayerWall(void);


//�����蔻��e���v���[�g
    bool BBCollision(D3DXVECTOR2 pos1,D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2);
};

