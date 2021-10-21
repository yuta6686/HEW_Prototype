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