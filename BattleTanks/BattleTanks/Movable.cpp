#include "Movable.h"



Movable::Movable()
{
	speed = 0;
}

Movable::Movable(float X, float Y, char objectName, int speed, Option direction)
	: GameObject(X, Y, objectName)
{
	SetSpeed(speed);
	SetDirection(direction);
}

void Movable::SetSpeed(int speed)
{
	this->speed = speed;
}
int Movable::GetSpeed() const
{
	return speed;
}

void Movable::SetDirection(Option direction)
{
	this->direction = direction;
}
Option Movable::GetDirection() const
{
	return direction;
}