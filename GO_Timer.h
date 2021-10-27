#pragma once

#include"GameObject.h"

class GO_Timer:public GameObject
{
public:
	// GameObject ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;
	virtual int GetGameScene(void) override { return GAME_SCENE; };

	GO_Timer(){}

	bool GetTimerUse(void) { return Timer_Vertex.use; }
	void SetTimerUse(bool flag) { Timer_Vertex.use = flag; }

private:
	char TEX_NAME[128] = "data/TEXTURE/number2.png";
	int Number_Texture;
	const int GAME_SCENE = GAMESCENE_SCRAMBLE;

	const int NUMBER_X = 4;
	const int NUMBER_Y = 4;
	const float NUMBER_WIDTH = 1.0f / (float)NUMBER_X;
	const float NUMBER_HEIGHT = 1.0f / (float)NUMBER_Y;

	VERTEX_ALPHA_ANIMATION_USE Timer_Vertex;
	VERTEX_ALPHA_ANIMATION_USE Timer_Second;

	
};

