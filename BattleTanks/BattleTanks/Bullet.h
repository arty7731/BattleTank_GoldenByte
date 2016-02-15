#pragma once
#include "Movable.h"


class Bullet : 
	public Movable
{
protected:
	Vector2d coordBullet;
	Vector2d speed;
	Vector2d acceleration;

	int forse;
	int angle;

public:
	Bullet();
	Bullet(int X, int Y, char objectName, int speed, Direction direction);
	
	void OptionMove(Vector2d coordMuzzle, int forse, int angle);
	void ChangeDirection();

	bool IsBullet() const;
	virtual void Move();

};