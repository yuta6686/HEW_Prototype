#include "SelectStage.h"
#include "StageObject.h"
#include "Effect.h"

#include "input.h"


SelectStage::SelectStage()
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		m_pStageObjects[i] = nullptr;
	}

	for (int i = 0; i < EFFECT_MAX; i++) {
		m_effect[i] = nullptr;
	}

	Create();
}

SelectStage::~SelectStage()
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		delete m_pStageObjects[i];
	}

	for (int i = 0; i < EFFECT_MAX; i++) {
		m_effect[i] = nullptr;
	}
}

HRESULT SelectStage::Init(void)
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;
		m_pStageObjects[i]->Init();
	}

	for (int i = 0; i < EFFECT_MAX; i++) {
		if (m_effect[i] == nullptr)continue;
		m_effect[i]->Initialize();
	}

	m_Spotlight.Init();

	return E_NOTIMPL;
}

void SelectStage::Uninit(void)
{
	
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;
		m_pStageObjects[i]->Uninit();
	}

	for (int i = 0; i < EFFECT_MAX; i++) {
		if (m_effect[i] == nullptr)continue;
		m_effect[i]->Finalize();
	}
}

void SelectStage::Update(void)
{
	Click();

	MouseOver();

	m_SO_ArrowKey.Update();

	IlluminateUpdate();

	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;
		m_pStageObjects[i]->Update();

	}

	for (int i = 0; i < EFFECT_MAX; i++) {
		if (m_effect[i] == nullptr)continue;
		m_effect[i]->Update();

	}

	
}

void SelectStage::Draw(void)
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;
		m_pStageObjects[i]->Draw();
	}

	SetBlendState(BLEND_MODE_ADD);

	for (int i = 0; i < EFFECT_MAX; i++) {
		if (m_effect[i] == nullptr)continue;
		m_effect[i]->Draw();
	}

	m_Spotlight.Draw();

	SetBlendState(BLEND_MODE_ALPHABLEND);
}

void SelectStage::Create(void)
{
	m_pStageObjects[0] = m_SO_Factory.Create_001();
	m_pStageObjects[1] = m_SO_Factory.Create_002();
	m_pStageObjects[2] = m_SO_Factory.Create_003();

	m_effect[0] = m_EF.Create();
}

void SelectStage::Click()
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {

		if (m_pStageObjects[i] == nullptr)continue;

		m_pStageObjects[i]->ClickUpdate();
	}

	if (IsMouseLeftTriggered()) {
		m_effect[0]->SetEffect();
	}
}

void SelectStage::MouseOver(void)
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;

		m_pStageObjects[i]->MouseOverUpdate();
	}
}

void SelectStage::IlluminateUpdate(void)
{
	for (int i = 0; i < STAGE_OBJECT_MAX; i++) {
		if (m_pStageObjects[i] == nullptr)continue;

		if (m_pStageObjects[i]->ReturnStageNum() == m_SO_ArrowKey.GetStageNumSelect()) {
			m_Spotlight.SetIlluminate(true, m_pStageObjects[i]->GetPos());
		}
	}
}
