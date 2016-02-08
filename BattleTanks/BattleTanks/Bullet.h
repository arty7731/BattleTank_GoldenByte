#pragma once
#include "Movable.h"
#include "Vector2d.h"
#include "Tank.h"

#include "Header.h"

class Bullet : public Movable
{
protected:
	Vector2d coordBullet;
	Vector2d speed;
	Vector2d acceleration;


public:
	Bullet();
	Bullet(int x, int y, char objectName, Direction direction, int speed);
	
	void OptionMove(Tank &tank);


	void Move();

};