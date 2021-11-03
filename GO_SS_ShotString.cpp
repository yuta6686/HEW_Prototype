#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"

void GO_SS_ShotString::Initialize(void)
{
	String_Texture = LoadTexture(TEX_NAME);

	String_Vertex.size.x = 0.0f;
	String_Vertex.size.y = 5.0f;
	String_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
	String_Vertex.angle = 0.0f;

}

void GO_SS_ShotString::Finalize(void)
{
}

void GO_SS_ShotString::Update(void)
{
	DebugOut();

	//押されている間
	if(IsMouseLeftPressed())
	{
		//カーソル取得
		CursorPos.x = GetMousePosX();
		CursorPos.y = GetMousePosY();


		//プレイヤーとカーソルの角度取得
		String_Vertex.angle = atan2f(String_Vertex.pos.y - CursorPos.y,
			String_Vertex.pos.x - CursorPos.x);


	}

	//押されたら
	if (IsMouseLeftTriggered()) {
		IsClick = true;
		String_Vertex.size.x = 0.0f;
	}

	

	//糸の長さがカーソルとの距離までに制限
	if (GetDistance(String_Vertex.pos, CursorPos) * 2.0f <= String_Vertex.size.x) {
		String_Vertex.size.x = GetDistance(String_Vertex.pos, CursorPos) * 2.0f;
	}
	else {
		String_Vertex.size.x += 20.0f;
	}
	
}

void GO_SS_ShotString::Draw(void)
{
	DrawSpriteColorRotate(String_Texture, String_Vertex.pos.x, String_Vertex.pos.y,
		String_Vertex.size.x, String_Vertex.size.y,
		0.0f, 0.0f, 0.9f, 0.9f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), String_Vertex.angle);
}

FLOAT GO_SS_ShotString::GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2)
{
	return sqrtf(powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2));
}

void GO_SS_ShotString::DebugOut(void)
{
#ifdef _DEBUG	// デバッグ版の時だけAngleを表示する
	wsprintf(GetDebugStr(), WINDOW_CAPTION);
	wsprintf(&GetDebugStr()[strlen(GetDebugStr())], " angle:%d",
		(int)(String_Vertex.angle * (FLOAT)180.0f / (FLOAT)PI));

	SetWindowText(GethWnd()[0], GetDebugStr());
#endif
}
