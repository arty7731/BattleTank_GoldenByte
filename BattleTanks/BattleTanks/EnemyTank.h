#pragma once
#include "Tank.h"

class EnemyTank :
	public Tank
{
public:
	EnemyTank(float X, float Y, char objectName, float speed, Option direction, float mx, float my);

	bool ChoiceFighter();
	void Move();

};