#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include "GO_SS_Target.h"
#include "GO_SS_Scramble.h"

void GO_SS_ShotString::Initialize(void)
{
	//糸　パラメータ初期化
	{
		String_Texture = LoadTexture(TEX_NAME);

		String_Vertex.size.x = 0.0f;
		String_Vertex.size.y = 5.0f;
		String_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
		String_Vertex.angle = 0.0f;
		String_Vertex.use = false;
	}

	//円　パラメータ初期化
	{
		Circle_Texture = LoadTexture(CIRCLE_TEX_NAME);

		Circle_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
		Circle_Vertex.size = D3DXVECTOR2(100.0f,0.0f);
		Circle_Vertex.alpha = 1.0f;
	}


	m_AimFlag = false;
}

void GO_SS_ShotString::Finalize(void)
{

}

void GO_SS_ShotString::Update(void)
{

	m_pScramble->SetPos(m_pPlayer->GetPos());

	if (IsMouseRightPressed()) {
		String_Vertex.use = true;
	}


	//	ターゲットではない場所をクリック
	NoTargetClick();

	//	ターゲットをクリック
	TargetClick();

	//	↑TargetClickより下に配置
	//	エイム変更
	ChangeAim();

	//ポジションをプレイヤーのポジションにする
	String_Vertex.pos = m_pPlayer->GetPos();
	Circle_Vertex.pos = m_pPlayer->GetPos();

	//	プレイヤーとカーソルの角度取得
	String_Vertex.angle = GetAnglePlayerAndCursor();

	//--糸の長さ伸ばす--//
	//	引数:伸ばす量	//
	//	max -> ターゲットとプレイヤーの距離	//
	ExtendLengthOfString(100.0f);

	//円のサイズを変更する
	ChangeSizeOfCircle();

	Circle_Vertex.alpha = Circle_Vertex.size.x / 1000.0f;
}

void GO_SS_ShotString::Draw(void)
{
	SetBlendState(BLEND_MODE_ADD);

	DrawSpriteColor(Circle_Texture, Circle_Vertex.pos.x, Circle_Vertex.pos.y,
		Circle_Vertex.size.x, Circle_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, Circle_Vertex.alpha));

	SetBlendState(BLEND_MODE_ADD);


	if (String_Vertex.use) {
		DrawSpriteColorRotate(String_Texture, String_Vertex.pos.x, String_Vertex.pos.y,
			String_Vertex.size.x, String_Vertex.size.y,
			0.0f, 0.0f, 0.9f, 0.9f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), String_Vertex.angle);
	}
	

}

//	円のサイズを変更する
void GO_SS_ShotString::ChangeSizeOfCircle()
{
	if (IsMouseRightPressed()) {
		Circle_Vertex.size.x += m_pScramble->GetPreviousDiff() / 10.0f;

		Circle_Vertex.size.x -= Circle_Vertex.size.x / m_CircleSizeMax * m_TimeDelay;
	}
	else {
		if (Circle_Vertex.size.x <= m_CircleSizeMax) {
			Circle_Vertex.size.x = m_CircleSizeMax;
		}
		else {
			Circle_Vertex.size.x -= 10.0f * m_TimeDelay;
		}
	}

	//	yとxのサイズ同じにする
	Circle_Vertex.size.y = Circle_Vertex.size.x;
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

//ターゲットをクリックした
void GO_SS_ShotString::TargetClick(void)
{
	IsInsideTarget = TargetIsInRange();

	if (IsInsideTarget >= 0) {
		if (m_pTarget->GetTarget()[IsInsideTarget].pos.x <= 0.0f) {
			m_AimFlag = false;
			
		}

		m_AimTarget = IsInsideTarget;

		m_AimFlag = true;
	}
	else {
		m_AimFlag = false;		
	}

	if (m_AimTarget < 0 || m_pTarget->GetTarget()[IsInsideTarget].pos.x <= 0.0f) {
		SetStringUse(false);
	}

	//	糸サイズリセット
	if (IsMouseLeftTriggered() && IsInsideTarget > -1) {
		String_Vertex.size.x = 0.0f;
		m_jumpCounter = 0;
		IsClickTarget = true;
	}

	if (IsMouseLeftPressed() && IsClickTarget){
		//	サイドにあたっていたら強制終了
		if (m_pPlayer->IsColl && m_pPlayer->IsCollSide > -1) {
			m_jumpCounter += 120;
		}
		
		//	終了
		if (m_jumpCounter >= 120) {
			IsClickTarget = false;
		}

		else {
			m_jumpCounter++;
			IsClickTarget = true;
			//m_AimFlag = true;

			Circle_Vertex.size.x -= Circle_Vertex.size.x / 20.0f;
		}
	}
	else {
		IsClickTarget = false;
		m_AimFlag = false;
	}
}

void GO_SS_ShotString::ChangeAim(void)
{
	if (m_AimFlag) {
		m_AimTarget = IsInsideTarget;		
	}
	AimPos = m_pTarget->GetTarget()[m_AimTarget].pos;
}

int GO_SS_ShotString::TargetIsInRange(void)
{	
	int index = -1;

	for (int i = 0; i < m_pTarget->GetTargetNumMax(); i++) {
		VERTEX_TARGET vt = m_pTarget->GetTarget()[i];
		if (!vt.use)continue;

		FLOAT x = powf(Circle_Vertex.pos.x - vt.pos.x, 2.0f);
		FLOAT y = powf(Circle_Vertex.pos.y - vt.pos.y, 2.0f);
		FLOAT dist = sqrtf(x + y);

		if (dist <= vt.size.x + Circle_Vertex.size.x - 550.0f) {
			index = i;
		}
	}

	return index;
}


void GO_SS_ShotString::ExtendLengthOfString(FLOAT amount)
{	
	//糸の長さがカーソルとの距離までに制限
	if (GetDistance(String_Vertex.pos, AimPos) * 2.0f <= String_Vertex.size.x) {
		String_Vertex.size.x = GetDistance(String_Vertex.pos, AimPos) * 2.0f;
	}
	else {
		//糸の長さ伸ばす
		String_Vertex.size.x += amount * m_TimeDelay;
	}
}

//ターゲットではない場所をクリック
void GO_SS_ShotString::NoTargetClick(void)
{
	//押されたら
	if (IsMouseLeftTriggered()) {
		String_Vertex.size.x = 0.0f;
	}

}

FLOAT GO_SS_ShotString::GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2)
{
	return sqrtf(powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2));
}

FLOAT GO_SS_ShotString::GetAnglePlayerAndCursor()
{
	return atan2f(String_Vertex.pos.y - AimPos.y,
		String_Vertex.pos.x - AimPos.x);
}