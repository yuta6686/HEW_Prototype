#pragma once
#include "GameObject.h"

class GO_SS_Player;
class GO_SS_Target;

class GO_SS_ShotString :public GameObject
{
public:
	// GameObjectを介して継承されました
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;
	virtual int GetGameScene(void) override { return GAME_SCENE; }

	//ゲッター
	FLOAT GetAngle(void) { return String_Vertex.angle; }

	//セッター
	void SetPlayer(GO_SS_Player* p) { m_pPlayer = p; }
	void SetTarget(GO_SS_Target* p) { m_pTarget = p; }

	

	//public 変数
	bool IsClick = false;

	bool IsClickTarget = false;

	bool IsInsideTarget = false;

private:
	//ゲームシーン用
	const int GAME_SCENE = GAMESCENE_GAME_TEST;

	//テクスチャ用
	char TEX_NAME[64] = "data/TEXTURE/String1.png";
	int String_Texture;

	//頂点パラメータ
	VERTEX_SHOOTSTIRNG String_Vertex;

	//カーソルポジション
	D3DXVECTOR2 CursorPos;
	
	//カーソルとプライヤーの距離取得
	FLOAT GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2);

	//デバッグ用
	void DebugOut(void);

	GO_SS_Player* m_pPlayer;
	GO_SS_Target* m_pTarget;

	//ジャンプカウンター
	int m_jumpCounter = 0;

//メンバ関数
	
	//ターゲットではない場所をクリック
	void NoTargetClick(void);

	//ターゲットをクリックした
	void TargetClick(void);

	bool IsMouseInsideTarget(void);
};