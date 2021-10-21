#pragma once
#include "main.h"

struct VERTEX_T {
	D3DXVECTOR2		pos;	//位置ベクトル
	D3DXVECTOR2		vel;	//速度ベクトル
	D3DXCOLOR		color;	//頂点カラー
};

struct VERTEX_A :public VERTEX_T {
	D3DXVECTOR2 size;
	INT frame;
	FLOAT angle;
};