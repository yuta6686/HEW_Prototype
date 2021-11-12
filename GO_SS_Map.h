#pragma once
#include "GameObject.h"

class GO_SS_FileLoad;

class GO_SS_Map :public GameObject
{
public:
	// GameObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;

	void SetFileLoad(GO_SS_FileLoad* p) { m_pFileLoad = p; }

	virtual int GetGameScene(void) override { return GAME_SCENE; }

private:
	int GAME_SCENE = GAMESCENE_GAME_TEST;
	int* p_MapData;
	GO_SS_FileLoad* m_pFileLoad;
};