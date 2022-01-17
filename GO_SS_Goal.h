#pragma once

#include "GameObject.h"

class GO_SS_Player;

class GO_SS_Goal :
	public GameObject
{
public:

	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;

	virtual int GetGameScene(void) override { return GAME_SCENE; }

	VERTEX_T GetGoal() { return Goal_Vertex; }
	void SetGoalPos(D3DXVECTOR2 pos);

	void AddX(FLOAT x);
private:

	int Goal_Texture;

	char GOAL_TEX_NAME[128] = "data/TEXTURE/”[“¤.png";

	const int GAME_SCENE = GAMESCENE_GAME_TEST;

	VERTEX_T Goal_Vertex;
};

