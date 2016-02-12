#pragma once
#include "PlayerTank.h"
#include "EnemyTank.h"
#include "Bullet.h"
#include "Ground.h"

class Level
{

	GameObject **objects;
	Movable **movable;

	int width;
	int height;
	
	int objectCount;

	void Initialization();

public:
	Level();
	Level(int width, int height, int objectCount);

	//API
	void LevelTimerTick();

	~Level();
};

