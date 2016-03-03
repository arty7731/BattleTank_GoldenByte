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
	Bullet(float X, float Y, char objectName, int speed, Option direction);
	
	void OptionMove(Vector2d coordMuzzle, int forse, int angle);
	void ChangeDirection();

	bool IsBullet() const;
	virtual void Move();

	float GetX() const;
	float GetY() const;

};