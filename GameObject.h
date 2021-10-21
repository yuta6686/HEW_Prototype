#pragma once
//---------------------------
//	[GameObject.h]
//	Yuta Yanagisawa 
//---------------------------
#include "main.h"

class GameObject {
public:
	GameObject() {}
	virtual ~GameObject() {}

	virtual void Initialize(void) = 0;
	virtual void Finalize(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

};

