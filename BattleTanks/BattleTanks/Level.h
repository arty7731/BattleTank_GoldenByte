#pragma once
#include "PlayerTank.h"
#include "EnemyTank.h"
#include "Bullet.h"
#include "Ground.h"

class Level
{

	GameObject **objects;
	Movable **movable;
	Bullet* bullet;

	int width;
	int height;
	
	int objectCount;

	void Initialization();

public:
	Level();
	Level(int width, int height, int objectCount);

	int GetWidth() const;
	int GetHeigth() const;

	//API
	void LevelTimerTick();
	Tank* GetPlayerTank() const;
	Tank* GetEnemyTank() const;
	Bullet* GetBullet() const;
	void SetBullet(Bullet* bullet);

	~Level();
};

