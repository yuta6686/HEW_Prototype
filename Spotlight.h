#pragma once
#include "main.h"
class Spotlight
{
public:
	void Init();
	void Draw(D3DXVECTOR2 pos);

	void SetIlluminate(bool flag) { m_Illuminate = flag; }
private:
	int m_TexIndex;
	char m_TexName[64] = "data/TEXTURE/W’†ü3.png";

	bool m_Illuminate;
};

