#pragma once
//---------------------------
//	[GameFramework.h]
//	Yuta Yanagisawa 
//---------------------------

class GameObject;
class Enemy;
class GO_Player;
class Collision;
class GO_Vortex;
class GO_VortexRotation;

class GameFramework {
public:
	GameFramework();
	~GameFramework();

	void Initialize(void);
	void Finalize(void);
	void Update(void);
	void Draw(void);

	void Register(GameObject* pGameObject);
	

	void SetPlayer(GO_Player* pPlayer) { mp_player = pPlayer; }
	//void SetEnemy(Enemy* pEnemy) { mp_enemy = pEnemy; }
	//void SetCollision(Collision* pColl) { mp_collision = pColl; }

private:

	static const int GAME_OBJECT_MAX = 100;

	GameObject* m_pGameObjects[GAME_OBJECT_MAX];

	GO_Player* mp_player;
	GO_Vortex* mp_vortex;
	GO_VortexRotation* mp_VoRot;
	//Enemy* mp_enemy;
	//Collision* mp_collision;

	void Create();

	void SetGameObject();
};
