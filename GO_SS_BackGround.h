#pragma once
#include "GameObject.h"
class GO_SS_BackGround :
    public GameObject
{
public:
    // GameObject ����Čp������܂���
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override {  return GAME_SCENE;  }

    void AddU(FLOAT add) { 
        BackGround_Vertex.u += add * 2.0f / 3.0f; 
        m_uBack             += add / 10.0f;
        m_xNoneLoop         -= add * 500.0f;
        m_uBG               += add / 2.0f;
    }
    void SubU(FLOAT sub) { 
        BackGround_Vertex.u -= sub * 2.0f / 3.0f;
        m_uBack             -= sub / 10.0f;
        m_xNoneLoop         += sub * 500.0f;
        m_uBG               -= sub / 2.0f;
    }

private:
    //�e�N�X�`���p�ϐ�

//  TexName
    //  ��
    char* MORNING_BG =          "data/TEXTURE/morning003.png";
    char* MORNING_NONELOOP =    "data/TEXTURE/morning002.png";
    char* MORNING_BUILDING =    "data/TEXTURE/morning001.png";

    //  ��
    char* NOON_BG =         "data/TEXTURE/noon003.png";
    char* NOON_NONELOOP =   "data/TEXTURE/noon002.png";
    char* NOON_BUILDING =   "data/TEXTURE/noon001.png";

    //  ��
    char* NIGHT_BG =                "data/TEXTURE/night004.png";
    char* NIGHT_NONELOOP =          "data/TEXTURE/night003.png";
    char* NIGHT_BUILDING_FRONT =    "data/TEXTURE/night001.png";
    char* NIGHT_BUILDING_BACK =     "data/TEXTURE/night002.png";

//  �C���f�b�N�X
    //  ��
    int m_morning_BG;               //  -> 003
    int m_morning_NoneLoop;         //  -> 002
    int m_morning_Building_Front;   //  -> 001

    //  ��
    int m_noon_BG;              //  -> 003
    int m_noon_NoneLoop;        //  -> 002
    int m_noon_Building_Front;  //  -> 001

    //  ��
    int m_night_BG;             //  -> 004
    int m_night_NoneLoop;       //  -> 003
    int m_night_Building_Front; //  -> 002
    int m_night_Building_Back;  //  -> 001

//  �g�p����e�N�X�`���̓���ւ�

    //  �w�i
    int m_nowTex_BG;
    
    //  ���[�v�����̂��
    int m_nowTex_NoneLoop;

    //  �O�̌���
    int m_nowTex_Building_Front;

    //  ���̌���
    int m_nowTex_Building_Back;

    int CmpTexture;
    char CMP_TEX_NAME[128] = "data/TEXTURE/cmp1.png";

    //�Q�[���V�[���p�ϐ�
    const int GAME_SCENE = GAMESCENE_BUNGEE_JUMP;

    //���_���W
    VERTEX_BACKGROUND BackGround_Vertex;

    //  UV��U���

    /*Front��BackGround_Vertex.u���g�p*/
    FLOAT m_uBG;    
    FLOAT m_uBack;
    FLOAT m_xNoneLoop;

    const FLOAT UV_SCROLL = 0.001f;
};

