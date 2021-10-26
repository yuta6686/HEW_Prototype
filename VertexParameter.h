//---------------------------
//	[VertexParameter.h]
//	Yuta Yanagisawa 
//---------------------------

//ここでパラメータ？の整理してください。。。

#pragma once
#include "main.h"

struct VERTEX_T {
	D3DXVECTOR2		pos;	//位置ベクトル
	D3DXVECTOR2		vel;	//速度ベクトル
	D3DXCOLOR		color;	//頂点カラー
	D3DXVECTOR2 size;
};

struct VERTEX_A :public VERTEX_T {
	INT frame;
	FLOAT angle;
};

//基本この下から選ぶ　無かったらNOMALを継承して作る
struct VERTEX_NOMAL {
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
};




//alpha & use & animation
struct VERTEX_ALPHA_ANIMATION_USE :public VERTEX_NOMAL {
	bool use;
	FLOAT alpha;

	FLOAT u;
	FLOAT v;
	int counter;
};