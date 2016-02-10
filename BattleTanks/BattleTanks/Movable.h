#pragma once
#include "GameObject.h"
#include "CoreEnumeration.h"

class Movable :
	public GameObject
{
protected:
	int speed;
public:
	Movable();
	Movable(int X, int Y, char objectName, int speed);

	void SetSpeed(int speed);

	int GetSpeed() const;

	virtual void Move() = 0;
};

