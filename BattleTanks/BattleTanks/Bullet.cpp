#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(float X, float Y, char objectName, int speed, Option direction)
	: Movable(X, Y, objectName, speed, direction)
{

}

void Bullet::OptionMove(Vector2d coordMuzzle, int forse, int angle)
{
	coordBullet = coordMuzzle;
	acceleration.SetVector2d(0, 2);
	switch (direction)
	{
	case Option::Right:
		if (angle == 80)		  speed.SetVector2d(0, -1);
		else if (angle == 70) speed.SetVector2d(1, -4);
		else if (angle == 60) speed.SetVector2d(1, -3);
		else if (angle == 50) speed.SetVector2d(1, -2);
		else if (angle == 40) speed.SetVector2d(1, -1);
		else if (angle == 30) speed.SetVector2d(2, -1);
		else if (angle == 20) speed.SetVector2d(3, -1);
		else if (angle == 10) speed.SetVector2d(4, -1);
		else if (angle == 0) speed.SetVector2d(5, -1);
		//else if (angle == 90) speed.SetVector2d(1, 0);
		break;
	case Option::Left:
		if (angle == 80)		  speed.SetVector2d(0, -1);
		else if (angle == 70) speed.SetVector2d(1, -4);
		else if (angle == 60) speed.SetVector2d(1, -3);
		else if (angle == 50) speed.SetVector2d(1, -2);
		else if (angle == 40) speed.SetVector2d(1, -1);
		else if (angle == 30) speed.SetVector2d(2, -1);
		else if (angle == 20) speed.SetVector2d(3, -1);
		else if (angle == 10) speed.SetVector2d(4, -1);
		else if (angle == 0) speed.SetVector2d(5, -1);
		//else if (angle == 90) speed.SetVector2d(-1, 0);
		break;
	}
	speed.X *= forse;
	speed.Y *= forse;

}

float Bullet::GetX() const
{
	return coordBullet.X;
}

float Bullet::GetY() const
{
	return coordBullet.Y;
}

void Bullet::ChangeDirection()
{
	switch (direction)
	{
	case Option::Right:
		direction = Option::Left;
		break;
	case Option::Left:
		direction = Option::Right;
		break;
	}
}

bool Bullet::IsBullet() const
{
	return true;
}

void Bullet::Move()
{
	coordBullet.X += speed.X;
	coordBullet.Y += speed.Y;

	speed.X += acceleration.X;
	speed.Y += acceleration.Y;
}
