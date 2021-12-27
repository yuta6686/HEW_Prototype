#pragma once
#include "GameObject.h"


class GO_SS_KitchenTimer :
    public GameObject
{
public:

	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;

	virtual int GetGameScene(void) override { return GAME_SCENE; }

	VERTEX_T GetKitchenTimer() { return KitchenTimer_Vertex; }

	void SetUse(bool flag) { KitchenTimer_Vertex.use = flag; }

	void AddX(FLOAT x);
private:

	int KitchenTimer_Texture;

	char KTIMER_TEX_NAME[128] = "data/TEXTURE/”[“¤.png";

	const int GAME_SCENE = GAMESCENE_GAME_TEST;

	VERTEX_T KitchenTimer_Vertex;
};
