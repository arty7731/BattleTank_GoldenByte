#pragma once
#include "Tank.h"

class EnemyTank :
	public Tank
{
public:
	EnemyTank(int X, int Y, char objectName, int speed, int rx, int ry, int lx, int ly, int mx, int my);

	void Move();

};