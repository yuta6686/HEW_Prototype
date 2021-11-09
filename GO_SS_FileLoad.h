#pragma once
#include "GameObject.h"
#include <iostream>

class GO_SS_FileLoad :public GameObject
{
public:
	virtual void Initialize(void) override;

	virtual void Finalize(void) override;

	virtual void Update(void) override;

	virtual void Draw(void) override;

	void MapFileLoad(void);

	virtual int GetGameScene(void) override { return GAME_SCENE; }
private:
	static const int MAP_WIDTH_DIV = 16;	//��������
	static const int MAP_HEIGHT_DIV = 9;	//�c������
	static const int BLOCK_WIDTH = SCREEN_WIDTH / MAP_WIDTH_DIV;	//��1�u���b�N�̕�
	static const int BLOCK_HEIGHT = SCREEN_HEIGHT / MAP_HEIGHT_DIV;	//�c1�u���b�N�̕�

	const char* MapFileName = "data/MapData.csv";

	std::ifstream ifs;	//ファイルストリーム
	int MapData[MAP_HEIGHT_DIV][MAP_WIDTH_DIV];	//�}�b�v�f�[�^

	const int GAME_SCENE = GAMESCENE_GAME_TEST;
};