/*==============================================================================

   �V�[���Ǘ� [scene.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/

#include "scene.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include "gameOver.h"
#include "fade.h"
#include "SelectStage.h"
#include "Tutorial.h"
#include "credit.h"



/*------------------------------------------------------------------------------
   �萔��`
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   �\���̐錾
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   �v���g�^�C�v�錾
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   �O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static SCENE g_SceneIndex = SCENE_NONE;
static SCENE g_SceneNextIndex = g_SceneIndex;

static SelectStage g_sStage;
static STAGE_NUM g_StageNum;

static Tutorial g_Tutorial;
/*------------------------------------------------------------------------------
   �������֐�
------------------------------------------------------------------------------*/
void InitScene(SCENE index)
{
	g_SceneIndex = g_SceneNextIndex = index;

	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		InitTitle();
		break;

	case SCENE_CREDIT:
		InitCredit();
		break;

	case SCENE_SELECT_STAGE:
		g_sStage.Init();
		break;

	case SCENE_TUTORIAL:
		g_Tutorial.Init();
		break;

	case SCENE_GAME:
		InitGame();
		break;

	case SCENE_RESULT:
		InitResult();
		break;

	case SCENE_GAMEOVER:
		InitGameOver();
		break;
	}
}

/*------------------------------------------------------------------------------
   �I������������֐�
------------------------------------------------------------------------------*/
void UninitScene(void)
{
	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		UninitTitle();
		break;

	case SCENE_CREDIT:
		UninitCredit();
		break;

	case SCENE_SELECT_STAGE:
		g_sStage.Uninit();
		break;

	case SCENE_TUTORIAL:
		g_Tutorial.Uninit();
		break;

	case SCENE_GAME:
		UninitGame();
		break;

	case SCENE_RESULT:
		UninitResult();
		break;

	case SCENE_GAMEOVER:
		UninitGameOver();
		break;
	}
}

/*------------------------------------------------------------------------------
   �X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateScene(void)
{
	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		UpdateTitle();
		break;

	case SCENE_CREDIT:
		UpdateCredit();
		break;

	case SCENE_SELECT_STAGE:
		g_sStage.Update();
		break;

	case SCENE_TUTORIAL:
		g_Tutorial.Update();
		break;

	case SCENE_GAME:
		UpdateGame();
		break;

	case SCENE_RESULT:
		UpdateResult();
		break;

	case SCENE_GAMEOVER:
		UpdateGameOver();
		break;
	}

	UpdateFade();
}

/*------------------------------------------------------------------------------
   �`�揈��������֐�
------------------------------------------------------------------------------*/
void DrawScene(void)
{
	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		DrawTitle();
		break;

	case SCENE_CREDIT:
		DrawCredit();
		break;

	case SCENE_SELECT_STAGE:
		g_sStage.Draw();
		break;

	case SCENE_TUTORIAL:
		g_Tutorial.Draw();
		break;

	case SCENE_GAME:
		DrawGame();
		break;

	case SCENE_RESULT:
		DrawResult();
		break;

	case SCENE_GAMEOVER:
		DrawGameOver();
		break;
	}

	DrawFade();
}

/*------------------------------------------------------------------------------
   �V�[���J�ڂ�v������֐�
------------------------------------------------------------------------------*/
void SetScene(SCENE index)
{
	//�J�ڐ�V�[����ݒ肷��
	g_SceneNextIndex = index;
}

/*------------------------------------------------------------------------------
   �J�ڂ�v��������ꍇ�ɃV�[����؂�ւ���֐�
------------------------------------------------------------------------------*/
void CheckScene(void)
{
	//���݂̃V�[���ƑJ�ڐ�V�[��������Ă�����
	if (g_SceneIndex != g_SceneNextIndex)
	{
		//���݂̃V�[�����I��������
		UninitScene();

		//�J�ڐ�V�[���̏������������s��
		InitScene(g_SceneNextIndex);
	}
}

int GetStageNum(void) {
	return g_StageNum;
}

void SetStageNum(int sn) {
	g_StageNum = (STAGE_NUM)sn;
}

void AddStageNum(void) {
	switch (g_StageNum)
	{
	case STAGE_NUM_NONE:
		g_StageNum = STAGE_NUM_001;
		break;
	case STAGE_NUM_001:
		g_StageNum = STAGE_NUM_002;
		break;
	case STAGE_NUM_002:
		g_StageNum = STAGE_NUM_003;
		break;
	case STAGE_NUM_003:
		g_StageNum = STAGE_NUM_001;
		break;
	case STAGE_NUM_MAX:
		g_StageNum = STAGE_NUM_001;
		break;
	default:
		g_StageNum = STAGE_NUM_001;
		break;
	}
}