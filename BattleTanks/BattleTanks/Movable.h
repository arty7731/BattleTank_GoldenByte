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
	Movable(int x, int y, char objectName, Direction direction, int speed);

	void SetMovabe(Direction direction, int speed);
	void SetSpeed(int speed);
	void SetDirection(Direction direction);

	Direction GetDirection() const;
	int GetSpeed() const;

	virtual void Move() = 0;
};

