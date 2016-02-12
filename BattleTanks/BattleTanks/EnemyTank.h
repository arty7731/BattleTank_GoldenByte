#pragma once
#include "Tank.h"

class EnemyTank :
	public Tank
{
public:
	EnemyTank(int X, int Y, char objectName, int speed, Direction direction, int mx, int my);

	void Move();

};