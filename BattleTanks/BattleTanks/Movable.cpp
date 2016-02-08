#include "Movable.h"



Movable::Movable()
{
	direction = Direction::None;
}

Movable::Movable(int x, int y, char objectName, Direction direction, int speed)
	: GameObject(x, y, objectName)
{
	SetMovabe(direction, speed);
}

void Movable::SetMovabe(Direction direction, int speed)
{
	SetDirection(direction);
	SetSpeed(speed);
}

void Movable::SetSpeed(int speed)
{
	this->speed = speed;
}

void Movable::SetDirection(Direction direction)
{
	this->direction = direction;
}

Direction Movable::GetDirection() const
{
	return direction;
}

int Movable::GetSpeed() const
{
	return speed;
}
