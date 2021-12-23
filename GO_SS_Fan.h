#pragma once
#include "GameObject.h"

class GO_SS_Fan : public GameObject
{
public:
	// GameObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;
	virtual int GetGameScene(void) { return GAME_SCENE; }

	void LinkFanB(D3DXVECTOR2 pos);

	void SetFan(D3DXVECTOR2 pos);
	void SetCircle(VERTEX_CIRCLE* p) { m_pCircle = p; }

	FAN_VARTEX* GetFan(void) { return m_FanInfo; }

	void AddX(FLOAT x);

	void ResetOnce(void) {
		for (int i = 0; i < FANS_MAX; i++) {
			m_FanInfo[i].use = false;
		}
		once = true;
	}

	static const int FANS_MAX = 5;		//ä∑ãCêÓÇÃç≈ëÂêî

private:

	bool FCCollision(D3DXVECTOR2 pos1, D3DXVECTOR2 size1, D3DXVECTOR2 pos2, float size2);
	void DebugOut(void);


	const int GAME_SCENE = GAMESCENE_GAME_TEST;
	const int WIND_TEX_MAX = 60;
	const int WIND_HEIGHT_SPLIT = 12;
	const int WIND_WIDTH_SPLIT = 5;
	const float WIND_ADD_V = 0.083f;
	const float WIND_ADD_U = 0.2f;

	int m_FanATex;
	int m_FanBTex;
	int m_WindTex;

	FAN_VARTEX m_FanInfo[FANS_MAX];

	VERTEX_CIRCLE* m_pCircle;
	bool once;
};