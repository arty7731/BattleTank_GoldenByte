#pragma once
#include "Tank.h"

class PlayerTank : 
	public Tank
{

public:
	PlayerTank();

	PlayerTank(int X, int Y, char objectName, int speed, Direction direction, int mx, int my);

	int ChoiceFighter();
	virtual void Move();
};