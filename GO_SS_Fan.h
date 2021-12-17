#pragma once
#include "GameObject.h"

struct FAN_VARTEX :public VERTEX_NOMAL
{
	bool use;
	bool isWork;
};

class GO_SS_Fan : public GameObject
{
public:
	// GameObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;
	virtual int GetGameScene(void) { return GAME_SCENE; }

	void SetFan(D3DXVECTOR2 pos);
	void SetCircle(VERTEX_CIRCLE* p) { m_pCircle = p; }

	void AddX(FLOAT x);

	void ResetOnce(void) {
		for (int i = 0; i < FANS_MAX; i++) {
			m_FanInfo[i].use = false;
		}
		once = true;
	}


private:

	bool FCCollision(D3DXVECTOR2 pos1, float size1, D3DXVECTOR2 pos2, float size2);
	void DebugOut(void);


	const int GAME_SCENE = GAMESCENE_GAME_TEST;

	int m_FanATex;
	int m_FanBTex;

	static const int FANS_MAX = 5;		//ä∑ãCêÓÇÃç≈ëÂêî

	FAN_VARTEX m_FanInfo[FANS_MAX];

	VERTEX_CIRCLE* m_pCircle;
	bool once;
};