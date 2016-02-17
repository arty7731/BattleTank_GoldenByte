#include "EnemyTank.h"

EnemyTank::EnemyTank(int X, int Y, char objectName, int speed, Direction direction, int mx, int my)
	: Tank(X, Y, objectName, speed, direction, mx, my)
{
}

void EnemyTank::Move()
{
	//TODO move enemy tank
	switch (direction)
	{
	case Direction::None:
		break;
	case Direction::Right:
		coord.SetX(coord.GetX() - speed);
		break;
	case Direction::Left:
		coord.SetX(coord.GetX() + speed);
		break;
	}
}