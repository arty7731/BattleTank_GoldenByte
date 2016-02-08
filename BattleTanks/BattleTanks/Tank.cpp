#include "Tank.h"



Tank::Tank()
{
}
Tank::Tank(int X, int Y, char objectName, Direction direction, int speed, int rx, int ry, int lx, int ly, int mx, int my)
	: Movable(X, Y, objectName, direction, speed)
{
	SetCoordRightSide(rx, ry);
	SetCoordLeftSide(lx, ly);
	SetCoordMuzzle(mx, my);
}

void Tank::SetCoordRightSide(int X, int Y)
{
	coordRightSide.SetVector2d(X, Y);
}
void Tank::SetCoordRightSide(Vector2d coord)
{
	coordRightSide = coord;
}

void Tank::SetCoordLeftSide(int X, int Y)
{
	coordLeftSide.SetVector2d(X, Y);
}
void Tank::SetCoordLeftSide(Vector2d coord)
{
	coordLeftSide = coord;
}

void Tank::SetCoordMuzzle(int X, int Y)
{
	coordMuzzle.SetVector2d(X, Y);
}
void Tank::SetCoordMuzzle(Vector2d coord)
{
	coordMuzzle = coord;
}

Vector2d Tank::GetCoordLeftSide() const
{
	return coordLeftSide;
}
Vector2d Tank::GetCoordRightSide() const
{
	return coordRightSide;
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

void Tank::Fire(Vector2d speedBullet, Vector2d accelerationFire)
{
	this->speedBullet = speedBullet;
	this->accelerationFire = accelerationFire;
}


