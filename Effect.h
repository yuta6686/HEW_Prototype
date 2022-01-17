#pragma once
#include "GameObject.h"
class Effect :public GameObject
{
public:
	virtual void Initialize(void) =0;

	virtual void Finalize(void) =0;

	virtual void Update(void) =0;

	virtual void Draw(void) =0;

	virtual int GetGameScene(void) {
		return GAMESCENE_GAME_TEST;
	}

	virtual void SetEffect(void) {
		m_Vertex.use = true;
	}

	virtual void SetEffect(D3DXVECTOR2 pos) {
		m_Vertex.use = true;
		m_Vertex.pos = pos;
	}

	bool GetUse() { return m_Vertex.use; }

private:

protected:
	VERTEX_ALL_EFFECT m_Vertex;

	int m_TexIndex;
	//char m_TexName[64];

	static const int m_Xnum = 5;
	static const int m_Ynum = 6;

	const float m_Width = (1.0f / m_Xnum);
	const float m_Height = (1.0f / m_Ynum);
};

