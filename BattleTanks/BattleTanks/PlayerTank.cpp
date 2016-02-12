#include "PlayerTank.h"

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

void PlayerTank::Move()
{
}
