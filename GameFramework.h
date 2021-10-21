#pragma once
//---------------------------
//	[GameFramework.h]
//	Yuta Yanagisawa 
//---------------------------

class GameObject;
class Enemy;
class Player;
class Collision;

class GameFramework {
public:
	GameFramework();
	~GameFramework();

	void Initialize(void);
	void Finalize(void);
	void Update(void);
	void Draw(void);

	void Register(GameObject* pGameObject);

	void SetPlayer(Player* pPlayer) { mp_player = pPlayer; }
	//void SetEnemy(Enemy* pEnemy) { mp_enemy = pEnemy; }
	//void SetCollision(Collision* pColl) { mp_collision = pColl; }

private:

	static const int GAME_OBJECT_MAX = 100;

	GameObject* m_pGameObjects[GAME_OBJECT_MAX];

	Player* mp_player;
	//Enemy* mp_enemy;
	//Collision* mp_collision;
};
