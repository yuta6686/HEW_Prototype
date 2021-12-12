#include "SelectStage.h"
#include "StageObject.h"
#include "StageObject_001.h"
#include "input.h"


SelectStage::SelectStage()
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		m_pStageObjects[i] = nullptr;
	}

	Create();
}

SelectStage::~SelectStage()
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		delete m_pStageObjects[i];
	}
}

HRESULT SelectStage::Init(void)
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;
		m_pStageObjects[i]->Init();
	}
	return E_NOTIMPL;
}

void SelectStage::Uninit(void)
{
	
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;
		Click();
		m_pStageObjects[i]->Uninit();
	}
}

void SelectStage::Update(void)
{
	Click();

	MouseOver();

	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;
		m_pStageObjects[i]->Update();

	}

	//ÉVÅ[ÉìëJà⁄
	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_GAME);
	}
}

void SelectStage::Draw(void)
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;
		m_pStageObjects[i]->Draw();
	}
}

void SelectStage::Create(void)
{
	m_pStageObjects[0] = new StageObject_001();
}

void SelectStage::Click()
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;
		if (m_pStageObjects[i]->IsClick()) {

			m_pStageObjects[i]->ClickUpdate();
		}
	}
}

void SelectStage::MouseOver(void)
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;
		if (m_pStageObjects[i]->IsMouseOver()) {
			m_pStageObjects[i]->MouseOverUpdate();
		}
	}
}
