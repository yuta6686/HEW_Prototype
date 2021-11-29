#include "GO_SS_Goal.h"
#include "GO_Player.h"


void GO_SS_Goal::Initialize(void)
{
	Goal_Texture = LoadTexture(GOAL_TEX_NAME);

	Goal_Vertex.pos = D3DXVECTOR2(1000.0f, 300.0f);
	Goal_Vertex.size = D3DXVECTOR2(180.0f, 200.0f);

}

void GO_SS_Goal::Finalize(void)
{
}

void GO_SS_Goal::Update(void)
{
	
}

void GO_SS_Goal::Draw(void)
{
	DrawSprite(Goal_Texture, Goal_Vertex.pos.x, Goal_Vertex.pos.y,
		Goal_Vertex.size.x, Goal_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f);
}