//---------------------------
//	[GameFramework.cpp]
//	Yuta Yanagisawa 
//---------------------------

#include "GameFramework.h"
#include "GameObject.h"
#include "GO_Player.h"
#include "GO_Scramble.h"
#include "GO_ScrambleRotation.h"
#include "GO_Throw.h"
#include "GO_Timer.h"
#include "GS_Scramble.h"

GameFramework::GameFramework()
{
	nowScene = std::make_unique<GS_Scramble>();
}



GameFramework::~GameFramework()
{

}

void GameFramework::Initialize(void)
{
	nowScene->Initialize();
	
}
void GameFramework::Finalize(void)
{
	nowScene->Finalize();
}
void GameFramework::Update(void)
{
	nowScene->Update();
}
void GameFramework::Draw(void)
{
	nowScene->Draw();
}

