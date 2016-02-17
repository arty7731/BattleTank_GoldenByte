#include "Tank.h"


Tank::Tank()
{
}
Tank::Tank(int X, int Y, char objectName, int speed, Direction direction, int mx, int my)
	: Movable(X, Y, objectName, speed, direction)
{
	SetCoordMuzzle(mx, my);
	angleMuzzle = 0;
}

void Tank::SetCoordMuzzle(int X, int Y)
{
	coordMuzzle.SetVector2d(X, Y);
}
void Tank::SetCoordMuzzle(Vector2d coord)
{
	coordMuzzle = coord;
}

Vector2d Tank::GetCoordMuzzle() const
{
	return coordMuzzle;
}

int Tank::GetSpeedBullet() const
{
	return speedBullet;
}
int Tank::GetAngleMuzzle() const
{
	return angleMuzzle;
}

void Tank::ChangeDirection()
{
	switch (direction)
	{
	case Direction::Right:
		direction = Direction::None;
		break;
	case Direction::Left:
		direction = Direction::None;
		break;
	}
}

void Tank::MuzzleUp()
{
	//if (GetCoordMuzzle().GetX() + 10 > 80) return;
	if (angleMuzzle == 90) return;
	coordMuzzle += 10;
	angleMuzzle += 10;
}

void Tank::MuzzleDown()
{
	//if (GetCoordMuzzle().GetX() - 10 < 0) return;
	if (angleMuzzle == -10) return;
	coordMuzzle -= 10;
	angleMuzzle -= 10;
}

bool Tank::IsPlayerTank()
{
	return false;
}

bool Tank::ChoiceFighter()
{
	return false;
}

void Tank::Fire(int speedBullet, int accelerationFire)
{
	this->speedBullet = speedBullet;
	this->angleMuzzle = angleMuzzle;
	ChoiceFighter();
}