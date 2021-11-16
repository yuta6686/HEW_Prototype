#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include "GO_SS_Target.h"

void GO_SS_ShotString::Initialize(void)
{
	//糸　パラメータ初期化
	{
		String_Texture = LoadTexture(TEX_NAME);

		String_Vertex.size.x = 0.0f;
		String_Vertex.size.y = 5.0f;
		String_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
		String_Vertex.angle = 0.0f;
	}

	//円　パラメータ初期化
	{
		Circle_Texture = LoadTexture(CIRCLE_TEX_NAME);

		Circle_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
		Circle_Vertex.size = D3DXVECTOR2(100.0f,0.0f);
		Circle_Vertex.alpha = 1.0f;
	}

	//当たり判定用変数初期化
	for (int i = 0; i < 4; i++) {
		Coordinate[i] = D3DXVECTOR2(0.0f, 0.0f);
	}
}

void GO_SS_ShotString::Finalize(void)
{

}

void GO_SS_ShotString::Update(void)
{
	DebugOut();

	//ポジションをプレイヤーのポジションにする
	String_Vertex.pos = m_pPlayer->GetPos();
	Circle_Vertex.pos = m_pPlayer->GetPos();

	//押されている間
	if (IsMouseLeftPressed())
	{
		if (IsInsideTarget > -1) {
			AimPos = m_pTarget->GetTarget()[IsInsideTarget].pos;
		}
		else {
			AimPos.x = GetMousePosX();
			AimPos.y = GetMousePosY();
		}
		

		//プレイヤーとカーソルの角度取得
		String_Vertex.angle = atan2f(String_Vertex.pos.y - AimPos.y,
			String_Vertex.pos.x - AimPos.x);

	}

	//糸の頂点座標をCoordinateにセット
	/*SetCoord(String_Vertex.pos, String_Vertex.size, 0.0f, 0.0f, 0.9f, 0.9f, 
		atan2f(AimPos.y - String_Vertex.pos.y,
			AimPos.x - String_Vertex.pos.x));*/

	//ターゲットではない場所をクリック
	NoTargetClick();

	//ターゲットをクリック
	TargetClick();




	//糸の長さがカーソルとの距離までに制限
	if (GetDistance(String_Vertex.pos, AimPos) * 2.0f <= String_Vertex.size.x) {
		String_Vertex.size.x = GetDistance(String_Vertex.pos, AimPos) * 2.0f;
	}
	else {
		//糸の長さ伸ばす
		String_Vertex.size.x += 20.0f;
	}

	//円のサイズを変更する
	if (IsMouseRightPressed()) {
		Circle_Vertex.size.x += 3.0f;
	}
	else {
		if (Circle_Vertex.size.x <= 200.0f) {
			Circle_Vertex.size.x = 200.0f;
		}
		else {
			Circle_Vertex.size.x -= 10.0f;
		}
	}

	Circle_Vertex.size.y = Circle_Vertex.size.x;
}

void GO_SS_ShotString::Draw(void)
{
	DrawSpriteColor(Circle_Texture, Circle_Vertex.pos.x, Circle_Vertex.pos.y,
		Circle_Vertex.size.x, Circle_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, Circle_Vertex.alpha));

	if (!IsClick)return;
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
	wsprintf(&GetDebugStr()[strlen(GetDebugStr())], " IsCollTarget:%d",
		0);

	SetWindowText(GethWnd()[0], GetDebugStr());
#endif
}

//ターゲットではない場所をクリック
void GO_SS_ShotString::NoTargetClick(void)
{
	//押されたら
	if (IsMouseLeftTriggered()) {
		String_Vertex.size.x = 0.0f;
	}

	//押していたら
	if (IsMouseLeftPressed()) {

		IsClick = true;

	}
	//離されたら
	else {
		IsClick = false;
	}
}

//ターゲットをクリックした
void GO_SS_ShotString::TargetClick(void)
{
	IsInsideTarget = IsMouseInsideTarget();


	//糸サイズリセット
	if (IsMouseLeftTriggered() && IsInsideTarget > -1) {
		String_Vertex.size.x = 0.0f;
		m_jumpCounter = 0;
		IsClickTarget = true;
	}

	if (IsMouseLeftPressed() && IsClickTarget){
			if (m_jumpCounter >= 120) {
				IsClickTarget = false;
			}
			else {
				m_jumpCounter++;
				IsClickTarget = true;
			}
	}
	else {
		IsClickTarget = false;
	}
}


int GO_SS_ShotString::IsMouseInsideTarget(void)
{	
	for (int i = 0; i < m_pTarget->GetTargetNumMax(); i++) {
		VERTEX_TARGET vt = m_pTarget->GetTarget()[i];
		if (!vt.use)continue;

		FLOAT x = powf(AimPos.x - vt.pos.x, 2.0f);
		FLOAT y = powf(AimPos.y - vt.pos.y, 2.0f);
		FLOAT dist = sqrtf(x + y);

		if (dist <= vt.size.x - 100.0f) {
			return i;
		}
	}
	
	return -1;
}

//bool GO_SS_ShotString::IsStringConnectTarget()
//{
//	for (int i = 0; i < m_pTarget->GetTargetNumMax(); i++) {
//		VERTEX_TARGET vt = m_pTarget->GetTarget()[i];
//		if (vt.use == false)continue;
//		if (IsClick == false)continue;
//		if (((Coordinate[1].x - Coordinate[0].x) * (vt.pos.y - Coordinate[0].y)) -
//			((vt.pos.x - Coordinate[0].x) * (Coordinate[1].y - Coordinate[0].y)) <= 0 &&
//
//			((Coordinate[2].x - Coordinate[1].x) * (vt.pos.y - Coordinate[1].y)) -
//			((vt.pos.x - Coordinate[1].x) * (Coordinate[2].y - Coordinate[1].y)) <= 0 &&
//
//			((Coordinate[3].x - Coordinate[2].x) * (vt.pos.y - Coordinate[2].y)) -
//			((vt.pos.x - Coordinate[2].x) * (Coordinate[3].y - Coordinate[2].y)) <= 0 &&
//
//			((Coordinate[0].x - Coordinate[3].x) * (vt.pos.y - Coordinate[3].y)) -
//			((vt.pos.x - Coordinate[3].x) * (Coordinate[0].y - Coordinate[3].y)) <= 0) {
//			return true;
//		}
//	}
//	return false;
//}
//
//void GO_SS_ShotString::SetCoord(D3DXVECTOR2 pos, D3DXVECTOR2 size, FLOAT tx, FLOAT ty, FLOAT tw, FLOAT th, FLOAT angle)
//{
//	size.y += 100.0f;
//
//	float hw, hh;
//	hw = size.x * 0.5f;
//	hh = size.y * 0.5f;
//
//	float rad = RADIAN * angle;
//
//	float rot_x = +hw * 2.0f;
//	float rot_y = -hh;
//
//	Coordinate[0] = D3DXVECTOR2(rot_x * cosf(rad) - rot_y * sinf(rad) + pos.x,
//		rot_x * sinf(rad) + rot_y * cosf(rad) + pos.y);
//
//
//	rot_x = 0.0f;
//	rot_y = -hh;
//	Coordinate[1] = D3DXVECTOR2(rot_x * cosf(rad) - rot_y * sinf(rad) + pos.x,
//		rot_x * sinf(rad) + rot_y * cosf(rad) + pos.y);
//
//	rot_x = +hw * 2.0f;
//	rot_y = +hh;
//	Coordinate[3] = D3DXVECTOR2(rot_x * cosf(rad) - rot_y * sinf(rad) + pos.x,
//		rot_x * sinf(rad) + rot_y * cosf(rad) + pos.y);
//
//	rot_x = 0.0f;
//	rot_y = +hh;
//	Coordinate[2] = D3DXVECTOR2(rot_x * cosf(rad) - rot_y * sinf(rad) + pos.x,
//		rot_x * sinf(rad) + rot_y * cosf(rad) + pos.y);
//}

