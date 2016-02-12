#include "Tank.h"


Tank::Tank()
{
}
Tank::Tank(int X, int Y, char objectName, int speed, Direction direction, int mx, int my)
	: Movable(X, Y, objectName, speed, direction)
{
	SetCoordMuzzle(mx, my);
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

Vector2d Tank::GetSpeedBullet() const
{
	return speedBullet;
}
Vector2d Tank::GetAccelerationFire() const
{
	return accelerationFire;
}

int Tank::ChoiceFighter()
{
	return 2;
}

void Tank::Fire(Vector2d speedBullet, Vector2d accelerationFire)
{
	this->speedBullet = speedBullet;
	this->accelerationFire = accelerationFire;
}