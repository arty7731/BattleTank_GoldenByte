#pragma once
#include "GameObject.h"
#include "CoreEnumeration.h"

class Movable :
	public GameObject
{
protected:
	int speed;
	Direction direction;
public:
	Movable();
	Movable(int X, int Y, char objectName, int speed, Direction direction);

	void SetSpeed(int speed);
	int GetSpeed() const;

	void SetDirection(Direction direction);
	Direction GetDirection() const;

	virtual void Move() = 0;
};

