#pragma once
#include "GameObject.h"

class GO_SS_Player;
class GO_SS_Target;
class GO_SS_Scramble;

class GO_SS_ShotString :public GameObject
{
public:
	// GameObjectを介して継承されました
	virtual void Initialize		(void)	override;
	virtual void Finalize		(void)	override;
	virtual void Update			(void)	override;
	virtual void Draw			(void)	override;
	virtual int GetGameScene	(void)	override	{ return GAME_SCENE; }

	//ゲッター
	FLOAT GetAngle(void){ return String_Vertex.angle; }
	VERTEX_CIRCLE* GetCircle(void) { return &Circle_Vertex; }

	//セッター
	void SetPlayer(GO_SS_Player* p)	{ m_pPlayer = p; }
	void SetTarget(GO_SS_Target* p)	{ m_pTarget = p; }
	void SetScramble(GO_SS_Scramble* p) { m_pScramble = p; }

	void SetPos(D3DXVECTOR2 pos)	{ String_Vertex.pos = pos; }

	//public 変数

	bool IsClickTarget = false;

	int IsInsideTarget = -1;

	FLOAT m_TimeDelay;

private:
	//ゲームシーン用
	const int GAME_SCENE = GAMESCENE_GAME_TEST;

	//テクスチャ用
	char TEX_NAME[64] = "data/TEXTURE/String1.png";
	int String_Texture;

	char CIRCLE_TEX_NAME[64] = "data/TEXTURE/circle1.png";
	int Circle_Texture;

	//頂点パラメータ
	VERTEX_SHOOTSTIRNG	String_Vertex;
	VERTEX_CIRCLE		Circle_Vertex;

	//判定用
	D3DXVECTOR2 Coordinate[4];

	//狙う位置
	D3DXVECTOR2 AimPos;
	
	//カーソルとプライヤーの距離取得
	FLOAT GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2);

	//デバッグ用
	void DebugOut(void);

	GO_SS_Player* m_pPlayer;
	GO_SS_Target* m_pTarget;
	GO_SS_Scramble* m_pScramble;

	//ジャンプカウンター
	int m_jumpCounter = 0;

//メンバ関数
	
	//ターゲットではない場所をクリック
	void NoTargetClick(void);

	//ターゲットをクリックした
	void TargetClick(void);

	int TargetIsInRange(void);

	//bool IsStringConnectTarget();


	//糸の頂点座標をCoordinateにセット
	//void SetCoord(D3DXVECTOR2 pos, D3DXVECTOR2 size, FLOAT tx, FLOAT ty, FLOAT tw, FLOAT th, FLOAT angle);

};

