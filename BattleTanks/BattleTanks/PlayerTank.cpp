#include "PlayerTank.h"

PlayerTank::PlayerTank()
{

}

PlayerTank::PlayerTank(int X, int Y, char objectName, int speed, int rx, int ry, int lx, int ly, int mx, int my)
	: Tank(X, Y, objectName, speed, rx, ry, lx, ly, mx, my)
{
}

int PlayerTank::ChoiceFighter()
{
	return 1;
}

void PlayerTank::Move()
{
}
