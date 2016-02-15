#include "PlayerTank.h"
#include "Environment.h"

PlayerTank::PlayerTank()
{

}

PlayerTank::PlayerTank(int X, int Y, char objectName, int speed, Direction direction, int mx, int my)
	: Tank(X, Y, objectName, speed, direction, mx, my)
{
}

int PlayerTank::ChoiceFighter()
{
	return 1;
}

bool PlayerTank::IsPlayerTank()
{
	return true;
}

void PlayerTank::Move()
{
	switch (direction)
	{
	case Direction::None:
		break;
	case Direction::Right:
		coord.SetX(coord.GetX() - 3);
		break;
	case Direction::Left:
		coord.SetX(coord.GetX() + 3);
		break;
	}
}

void ChangeDirection()
{
}
