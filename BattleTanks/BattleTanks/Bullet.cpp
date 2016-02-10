#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(int X, int Y, char objectName, int speed)
	: Movable(X, Y, objectName, speed)
{

}

void Bullet::OptionMove(Vector2d coordMuzzle, int forse, int angle)
{
	coordBullet = coordMuzzle;
	acceleration.SetVector2d(0, -2);

	if (angle >= 0 && angle < 5)		speed.SetVector2d(0, 1);
	else if (angle >= 5 && angle < 10)  speed.SetVector2d(1, 9);
	else if (angle >= 10 && angle < 15) speed.SetVector2d(1, 8);
	else if (angle >= 15 && angle < 20) speed.SetVector2d(1, 7);
	else if (angle >= 20 && angle < 25) speed.SetVector2d(1, 6);
	else if (angle >= 25 && angle < 30) speed.SetVector2d(1, 5);
	else if (angle >= 30 && angle < 35) speed.SetVector2d(1, 4);
	else if (angle >= 35 && angle < 40) speed.SetVector2d(1, 3);
	else if (angle >= 40 && angle < 45) speed.SetVector2d(1, 2);
	else if (angle >= 45 && angle < 50) speed.SetVector2d(1, 1);
	else if (angle >= 50 && angle < 55) speed.SetVector2d(2, 1);
	else if (angle >= 55 && angle < 60) speed.SetVector2d(3, 1);
	else if (angle >= 60 && angle < 65) speed.SetVector2d(4, 1);
	else if (angle >= 65 && angle < 70) speed.SetVector2d(5, 1);
	else if (angle >= 70 && angle < 75) speed.SetVector2d(6, 1);
	else if (angle >= 75 && angle < 80) speed.SetVector2d(7, 1);
	else if (angle >= 80 && angle < 85) speed.SetVector2d(8, 1);
	else if (angle >= 85 && angle < 90) speed.SetVector2d(9, 1);
	else if (angle == 90)				speed.SetVector2d(1, 0);
	speed *= forse;

}

void Bullet::Move()
{
	while (coordBullet.GetY() <= 0)
	{
		coordBullet += speed;
		speed += acceleration;
	}
}
