#pragma once
#include "GameObject.h"

struct VERTEX_T {
	D3DXVECTOR2		pos;	//位置ベクトル
	D3DXVECTOR2		vel;	//速度ベクトル
	D3DXCOLOR		color;	//頂点カラー
};

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

	//パラメータ情報 -> VertexInf.h
	VERTEX_T Player_Vertex;
};

