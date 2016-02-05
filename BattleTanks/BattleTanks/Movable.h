#pragma once
#include "GameObject.h"
#include "CoreEnumeration.h"

class Movable :
	public GameObject
{
protected:
	Direction direction;
	int speed;
public:
	Movable();

	void SetSpeed(int speed);
	void SetDirection(Direction direction);

};

