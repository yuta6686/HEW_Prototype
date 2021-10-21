#pragma once
//---------------------------
//	[GO_Player.h]
//	Yuta Yanagisawa 
//---------------------------
#include "GameObject.h"



class GO_Player :public GameObject
{
public:
	// GameObject を介して継承されました
	virtual void Initialize(void) override;

	virtual void Finalize(void) override;

	virtual void Update(void) override;

	virtual void Draw(void) override;

private:
	//テクスチャのインデックス
	int Player_Texture;

	//テクスチャの名前
	char PLAYER_TEX_NAME[128] = "data/TEXTURE/player.png";

	VERTEX_T Player_Vertex;
};

