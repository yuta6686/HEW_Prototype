#pragma once
#include "GameObject.h"
#include <iostream>
#include <fstream>
#include <sstream>

class GO_SS_FileLoad :public GameObject
{
public:
	virtual void Initialize(void) override;

	virtual void Finalize(void) override;

	virtual void Update(void) override;

	virtual void Draw(void) override;

	int* MapFileLoad(void);

	virtual int GetGameScene(void) override { return GAME_SCENE; }
private:
	static const int MAP_WIDTH_DIV = 16;	//マップの横分割数
	static const int MAP_HEIGHT_DIV = 9;	//マップの縦分割数
	static const int BLOCK_WIDTH = SCREEN_WIDTH / MAP_WIDTH_DIV;	//1ブロックの横
	static const int BLOCK_HEIGHT = SCREEN_HEIGHT / MAP_HEIGHT_DIV;	//1ブロックの縦

	int MapData[MAP_HEIGHT_DIV][MAP_WIDTH_DIV];	//まっぷでーた

	const int GAME_SCENE = GAMESCENE_GAME_TEST;
};