#pragma once
#include "main.h"
#include "renderer.h"
#include "scene.h"
#include "fade.h"
#include "Texture.h"
#include "sprite.h"
#include "input.h"
#include "Spotlight.h"

class StageObject
{
public:
	StageObject() {};


	virtual ~StageObject() {}

	virtual HRESULT Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	//クリック処理
	virtual bool IsClick(void) = 0;
	virtual void ClickUpdate(void) = 0;

	//マウスオーバー処理
	virtual bool IsMouseOver(void) = 0;
	virtual void MouseOverUpdate(void) = 0;

protected:

	VERTEX_SELECT_STAGE m_Vertex;

	Spotlight m_light;
};

