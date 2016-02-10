#include "Tank.h"


Tank::Tank()
{
	/*speedBullet.SetVector2d(0, 0);
	accelerationFire = speedBullet;
	coordTank[0] = accelerationFire;
	coordTank[1] = accelerationFire;
	coordTank[2] = accelerationFire;*/

}
Tank::Tank(int X, int Y, char objectName, int speed, int rx, int ry, int lx, int ly, int mx, int my)
	: Movable(X, Y, objectName, speed)
{
	SetCoordRightSide(rx, ry);
	SetCoordLeftSide(lx, ly);
	SetCoordMuzzle(mx, my);
}

void Tank::SetCoordRightSide(int X, int Y)
{
	coordTank[(int)CoordTank::coordRightSide].SetVector2d(X, Y);
}
void Tank::SetCoordRightSide(Vector2d coord)
{
	coordTank[(int)CoordTank::coordRightSide] = coord;
}

void Tank::SetCoordLeftSide(int X, int Y)
{
	coordTank[(int)CoordTank::coordLeftSide].SetVector2d(X, Y);
}
void Tank::SetCoordLeftSide(Vector2d coord)
{
	coordTank[(int)CoordTank::coordLeftSide] = coord;
}

void Tank::SetCoordMuzzle(int X, int Y)
{
	coordTank[(int)CoordTank::coordMuzzle].SetVector2d(X, Y);
}
void Tank::SetCoordMuzzle(Vector2d coord)
{
	coordTank[(int)CoordTank::coordMuzzle] = coord;
}

Vector2d Tank::GetCoordLeftSide() const
{
	return coordTank[(int)CoordTank::coordLeftSide];
}
Vector2d Tank::GetCoordRightSide() const
{
	return coordTank[(int)CoordTank::coordRightSide];
}
Vector2d Tank::GetCoordMuzzle() const
{
	return coordTank[(int)CoordTank::coordMuzzle];
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


