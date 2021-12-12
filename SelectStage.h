//=============================================================================
//
// ステージ選択画面処理 [SelectStage.h]
// Author :	yuta yanagisawa 
//
//=============================================================================
#pragma once



#include "StageObectFactory.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************




//*****************************************************************************
// クラス
//*****************************************************************************

class StageObject;

class SelectStage {
public:
	SelectStage();
	~SelectStage();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Create(void);

	void Click(void);
	void MouseOver(void);

private:
	static const int STAGE_OBJECT_MAX = 3;

	StageObject* m_pStageObjects[STAGE_OBJECT_MAX];

	StageObectFactory m_SOF;
};