#include "Movable.h"



Movable::Movable()
{
	speed = 0;
}

Movable::Movable(int X, int Y, char objectName, int speed)
	: GameObject(X, Y, objectName)
{
	SetSpeed(speed);
}

void Movable::SetSpeed(int speed)
{
	this->speed = speed;
}

int Movable::GetSpeed() const
{
	return speed;
}
