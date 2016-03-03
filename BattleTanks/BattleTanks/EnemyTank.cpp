#include "EnemyTank.h"

EnemyTank::EnemyTank(float X, float Y, char objectName, float speed, Option direction, float mx, float my)
	: Tank(X, Y, objectName, speed, direction, mx, my)
{
}

bool EnemyTank::ChoiceFighter()
{
	return false;
}

void EnemyTank::Move()
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