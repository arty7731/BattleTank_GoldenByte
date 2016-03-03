#include "Tank.h"
#include "Header.h"

Tank::Tank()
{
}
Tank::Tank(float X, float Y, char objectName, int speed, Option direction, float mx, float my)
	: Movable(X, Y, objectName, speed, direction)
{
	SetCoordMuzzle(mx, my);
	angleMuzzle = 0;
	currentBullet = nullptr;
}

void Tank::SetCoordMuzzle(float X, float Y)
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

float Tank::GetSpeedBullet() const
{
	return speedBullet;
}
float Tank::GetAngleMuzzle() const
{
	return angleMuzzle;
}

bool Tank::ChoiceFighter()
{
	return true;
}

void Tank::ChangeDirection()
{
	switch (direction)
	{
	case Option::Right:
		direction = Option::None;
		break;
	case Option::Left:
		direction = Option::None;
		break;
	}
}

void Tank::MuzzleUp()
{
	if ((angleMuzzle + 10) > 80) return;

	coordMuzzle.X = coordMuzzle.X + 6;
	coordMuzzle.Y = coordMuzzle.Y - 9;

	angleMuzzle += 10.0f;
	cout << angleMuzzle << endl;
}

void Tank::MuzzleDown()
{
	if ((angleMuzzle - 10) < 0) return;

	coordMuzzle.X = coordMuzzle.X - 6;
	coordMuzzle.Y = coordMuzzle.Y + 9;

	angleMuzzle -= 10.0f;
	cout << angleMuzzle << endl;


}

bool Tank::IsPlayerTank()
{
	return false;
}

Bullet* Tank::Fire(int speed, int angle)
{
	currentBullet = new Bullet(coordMuzzle.X, coordMuzzle.Y, 'B', 3, Option::None);
	this->speedBullet = speed;
	this->angleMuzzle = angle;
	currentBullet->SetDirection(Option::Left);
	currentBullet->OptionMove(coordMuzzle, speedBullet, angleMuzzle);
	currentBullet->Move();
	currentBullet->ChangeDirection();
	return currentBullet;
}