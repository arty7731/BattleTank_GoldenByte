#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(int X, int Y, char objectName, int speed, Direction direction)
	: Movable(X, Y, objectName, speed, direction)
{

}

void Bullet::OptionMove(Vector2d coordMuzzle, int forse, int angle)
{
	coordBullet = coordMuzzle;
	acceleration.SetVector2d(0, -2);

	if (angle == 0)		  speed.SetVector2d(0, 1);
	else if (angle == 10) speed.SetVector2d(1, 4);
	else if (angle == 20) speed.SetVector2d(1, 3);
	else if (angle == 30) speed.SetVector2d(1, 2);
	else if (angle == 40) speed.SetVector2d(1, 1);
	else if (angle == 50) speed.SetVector2d(2, 1);
	else if (angle == 60) speed.SetVector2d(3, 1);
	else if (angle == 70) speed.SetVector2d(4, 1);
	else if (angle == 80) speed.SetVector2d(5, 1);
	else if (angle == 90) speed.SetVector2d(1, 0);
	speed *= forse;

}

void Bullet::ChangeDirection()
{
	switch (direction)
	{
	case Direction::Right:
		direction = Direction::Left;
		break;
	case Direction::Left:
		direction = Direction::Right;
		break;
	}
}

void Bullet::Move()
{
	switch (direction)
	{
	case Direction::Right:
		while (coordBullet.GetY() <= 0)
		{
			coordBullet += speed;
			speed += acceleration;
		}
		break;
	case Direction::Left:
		//TODO direction left
		break;
	}

}
