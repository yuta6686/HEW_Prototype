#pragma once
#include "GameObject.h"

class GO_SS_FileLoad;
class GO_SS_Wall;

class GO_SS_Map :public GameObject
{
public:
	// GameObject を介して継承されました
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;

	void SetFileLoad(GO_SS_FileLoad* p) { m_pFileLoad = p; }
	void SetWall(GO_SS_Wall* p) { m_pWall = p; }

	virtual int GetGameScene(void) override { return GAME_SCENE; }

private:
	int GAME_SCENE = GAMESCENE_GAME_TEST;	
	int* p_MapData;
	GO_SS_FileLoad* m_pFileLoad;	//FileLoadポインタ
	GO_SS_Wall* m_pWall;			//Wallポインタ

	//定数
	const int WALL_NUM = 1;	//壁の番号

	const int WALL_NUM_X = 16;
	const int WALL_NUM_Y = 9;

	const float WALL_WIDTH = SCREEN_WIDTH / (float)WALL_NUM_X;
	const float WALL_HEIGHT = SCREEN_HEIGHT / (float)WALL_NUM_Y;

};