#include "Tank.h"
#include "Header.h"

Tank::Tank()
{
}
Tank::Tank(int X, int Y, char objectName, int speed, Direction direction, int mx, int my)
	: Movable(X, Y, objectName, speed, direction)
{
	SetCoordMuzzle(mx, my);
	angleMuzzle = 0;
	currentBullet = nullptr;
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
	if ((angleMuzzle + 10) > 80) return;

	coordMuzzle.SetX(coordMuzzle.GetX() + 6);
	coordMuzzle.SetY(coordMuzzle.GetY() - 9);

	angleMuzzle += 10;
	cout << angleMuzzle << endl;
}

void Tank::MuzzleDown()
{
	if ((angleMuzzle - 10) < 0) return;

	coordMuzzle.SetX(coordMuzzle.GetX() - 6);
	coordMuzzle.SetY(coordMuzzle.GetY() + 9);

	angleMuzzle -= 10;
	cout << angleMuzzle << endl;


}

bool Tank::IsPlayerTank()
{
	return false;
}

Bullet* Tank::Fire(int speed, int angle)
{
	currentBullet = new Bullet(coordMuzzle.GetX(), coordMuzzle.GetY(), 'B', 3, Direction::None);
	this->speedBullet = speed;
	this->angleMuzzle = angle;
	currentBullet->SetDirection(Direction::Left);
	currentBullet->OptionMove(coordMuzzle, speedBullet, angleMuzzle);
	currentBullet->Move();
	currentBullet->ChangeDirection();
	return currentBullet;
}