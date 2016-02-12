#include "Movable.h"



Movable::Movable()
{
	speed = 0;
}

Movable::Movable(int X, int Y, char objectName, int speed, Direction direction)
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

void Movable::SetDirection(Direction direction)
{
	this->direction = direction;
}
Direction Movable::GetDirection() const
{
	return direction;
}