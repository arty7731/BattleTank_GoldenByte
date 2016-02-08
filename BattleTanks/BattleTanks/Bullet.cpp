#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(int x, int y, char objectName, Direction direction, int speed)
	: Movable(x, y, objectName, direction, speed)
{

}

void Bullet::OptionMove(Tank &tank)
{
	coordBullet = tank.GetCoordMuzzle();
	speed = tank.GetSpeedBullet();
	acceleration = tank.GetAccelerationFire();
}

void Bullet::Move()
{
	while (coordBullet.GetY() <= 0)
	{
		coordBullet += speed;
		speed += acceleration;
		cout << coordBullet.GetX() << ", " << coordBullet.GetY() << endl;
	}
}
