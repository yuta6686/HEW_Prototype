#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"

void GO_SS_ShotString::Initialize(void)
{
	String_Texture = LoadTexture(TEX_NAME);

	String_Vertex.size.x = 0.0f;
	String_Vertex.size.y = 5.0f;
}

void GO_SS_ShotString::Finalize(void)
{
}

void GO_SS_ShotString::Update(void)
{
	player_Parameter.pos = mp_player->GetPos();
	

	if (IsMouseLeftTriggered())
	{
		CursorPos.x = GetMousePosX();
		CursorPos.y = GetMousePosY();

		angle = atan2f(CursorPos.y - player_Parameter.pos.y,
			CursorPos.x - player_Parameter.pos.x);
	
		//String_Vertex.size.x = 0.0f;
		String_Vertex.size.x = GetDistance(player_Parameter.pos, CursorPos) * 2.0f;
		
	}
	//String_Vertex.size.x += 20.0f;
}

void GO_SS_ShotString::Draw(void)
{
	DrawSpriteColorRotate(String_Texture, player_Parameter.pos.x, player_Parameter.pos.y, String_Vertex.size.x, String_Vertex.size.y,
		0.1f, 0.1f, 0.9f, 0.9f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), angle);
}

FLOAT GO_SS_ShotString::GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2)
{
	return sqrt(pow(((double)p1.x - (double)p2.x), 2) + pow((double)p1.y - (double)p2.y, 2));
}
