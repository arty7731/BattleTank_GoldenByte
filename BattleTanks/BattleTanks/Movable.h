#pragma once
#include "GameObject.h"
#include "CoreEnumeration.h"

class Movable :
	public GameObject
{
protected:
	int speed;
	Option direction;
public:
	Movable();
	Movable(float X, float Y, char objectName, int speed, Option direction);

	void SetSpeed(int speed);
	int GetSpeed() const;

	void SetDirection(Option direction);
	Option GetDirection() const;
	virtual void ChangeDirection() = 0;

	virtual void Move() = 0;
};

