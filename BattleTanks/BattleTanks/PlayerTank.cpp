#include "PlayerTank.h"
#include "Environment.h"

PlayerTank::PlayerTank()
{

}

PlayerTank::PlayerTank(float X, float Y, char objectName, float speed, Option direction, float mx, float my)
	: Tank(X, Y, objectName, speed, direction, mx, my)
{
}

bool PlayerTank::IsPlayerTank()
{
	return true;
}

Bullet* PlayerTank::Fire(int speed, int angle)
{
	currentBullet = new Bullet(coordMuzzle.X, coordMuzzle.Y, 'B', 3, Option::Right);
	this->speedBullet = speed;
	this->angleMuzzle = angle;
	currentBullet->OptionMove(coordMuzzle, speedBullet, angleMuzzle);
	currentBullet->Move();
	//currentBullet->ChangeDirection();
	return currentBullet;
}

void PlayerTank::Move()
{
	switch (direction)
	{
	case Option::None:
		break;
	case Option::Right:
		coord.X = coord.X - speed;
		coordMuzzle.X = coordMuzzle.X - speed;
		break;
	case Option::Left:
		coord.X = coord.X + speed;
		coordMuzzle.X = coordMuzzle.X + speed;
		break;
	}
}

void ChangeDirection()
{
}
