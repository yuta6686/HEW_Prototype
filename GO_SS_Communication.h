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
class GO_SS_BackGround;
class GO_SS_Player;
class GO_SS_Wall;
class GO_SS_ShotString;

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
    void SetBackGround(GO_SS_BackGround* p_BackGround) { m_pBackGround = p_BackGround; }
    void SetPlayer(GO_SS_Player* p_Player) { m_pPlayer = p_Player; }
    void SetWall(GO_SS_Wall* pWall) { m_pWall = pWall; }
    void SetShotString(GO_SS_ShotString* p) { m_pShotString = p; }

    
    
private:
    //�Q�[���V�[��
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    GO_SS_BackGround* m_pBackGround;
    GO_SS_Player* m_pPlayer;
    GO_SS_Wall* m_pWall;
    GO_SS_ShotString* m_pShotString;

    //�����o�ϐ�
    int JumpCounter = 0;
    int JumpCountMax = 30;

    //�����o�֐�
    void SetShotStringPlayer();

    void JumpMoveBackGround_Pat1();
    void JumpMoveBackGround_Pat2();
};
