#pragma once
#include "Tank.h"

class PlayerTank : 
	public Tank
{

public:
	PlayerTank();

	PlayerTank(float X, float Y, char objectName, float speed, Option direction, float mx, float my);

	bool IsPlayerTank();
	virtual void Move();
};