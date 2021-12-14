#pragma once
#include "main.h"
class Spotlight
{
public:
	void Init();
	void Draw();

	void SetIlluminate(bool flag ,D3DXVECTOR2 pos) { 
		m_Illuminate = flag; 
		m_pos = pos;
	}
private:
	int m_TexIndex;
	char m_TexName[64] = "data/TEXTURE/W’†ü3.png";

	bool m_Illuminate;
	D3DXVECTOR2 m_pos;
};

