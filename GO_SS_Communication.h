//---------------------------------------------
//	�I�u�W�F�N�g�ԒʐM�������ł��	[GO_SS_Communication.h]	
//                          Author: Yanagisawa
//---------------------------------------------
// GameSceneTest�̃I�u�W�F�N�g�iGO_SS_Manager�ɂ���|�C���^�j��
// �����Ŏg���āA�l�������荇��
//  
// �������g�����̃I�u�W�F�N�g�̏�������K�v���Ȃ��B
//      
// �������������ׂĂ�m���Ă���
//
//---------------------------------------------
#include "GameObject.h"
#include "GO_SS_Collision.h"

class GO_SS_BackGround;
class GO_SS_Player;
class GO_SS_Wall;
class GO_SS_ShotString;
class GO_SS_Target;

enum PlayerMove {
    PLAYERMOVE_NONE,
    PLAYERMOVE_NOJUMP,
    PLAYERMOVE_YESJUMP,
    PLAYERMOVE_MAX,
};

class GO_SS_Communication :
    public GameObject
{
public:
    // GameObject ����Čp������܂���
    virtual void Initialize(void) override {};
    virtual void Finalize(void) override {};
    virtual void Update(void) override;
    virtual void Draw(void) override {};
    virtual int GetGameScene(void) override { return GAME_SCENE; }

    //�Z�b�^�[
    void SetBackGround(GO_SS_BackGround* p_BackGround) {
        m_pBackGround = p_BackGround;
        m_ssCollision.SetBackGround(p_BackGround);
    }
    void SetPlayer(GO_SS_Player* p_Player) { 
        m_pPlayer = p_Player; 
        m_ssCollision.SetPlayer(p_Player);
    }
    void SetWall(GO_SS_Wall* pWall) { 
        m_pWall = pWall; 
        m_ssCollision.SetWall(pWall);
    }
    void SetShotString(GO_SS_ShotString* p) { 
        m_pShotString = p; 
        m_ssCollision.SetShotString(p);
    }
    void SetTarget(GO_SS_Target* pTarget) {
        m_pTarget = pTarget; 
        m_ssCollision.SetTarget(pTarget);
    }
    
    
private:
    //�Q�[���V�[��
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    GO_SS_BackGround* m_pBackGround;
    GO_SS_Player* m_pPlayer;
    GO_SS_Wall* m_pWall;
    GO_SS_ShotString* m_pShotString;
    GO_SS_Target* m_pTarget;

    //�����o�ϐ�
    int JumpCounter = 0;
    int JumpCountMax = 60;

    GO_SS_Collision m_ssCollision;      //�����蔻����i���

    //�����o�֐�
    void SetShotStringPlayer();

    void JumpMoveBackGround_NoJump();
    void JumpMoveBackGround_YesJump();

    void PlayerMoveSwitch(PlayerMove index);

    void TergetUpdate();
};


