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

	D3DXVECTOR2 GetPos() { return Goal_Vertex.pos; }
	D3DXVECTOR2 GetSize() { return Goal_Vertex.size; }

private:

	int Goal_Texture;

	char GOAL_TEX_NAME[128] = "data/TEXTURE/”[“¤.png";

	const int GAME_SCENE = GAMESCENE_GAME_TEST;

	VERTEX_T Goal_Vertex;
};

