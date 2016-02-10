#pragma once
#include "Tank.h"

class PlayerTank : 
	public Tank
{

public:
	PlayerTank();

	PlayerTank(int X, int Y, char objectName, int speed,
		int rx, int ry, int lx, int ly, int mx, int my);

	int ChoiceFighter();
	virtual void Move();
};