#pragma once
#include "Movable.h"

class Tank :
	public Movable
{
protected:
	Vector2d coordMuzzle;

	Vector2d speedBullet;
	Vector2d accelerationFire;

public:
	Tank();
	Tank(int X, int Y, char objectName, int speed, Direction direction, int mx, int my);

	void SetCoordMuzzle(int X, int Y);
	void SetCoordMuzzle(Vector2d coord);

	Vector2d GetCoordMuzzle() const;
	Vector2d GetSpeedBullet() const;
	Vector2d GetAccelerationFire() const;

	virtual void ChangeDirection();
	void MuzzleUp();
	void MuzzleDown();
	virtual bool IsPlayerTank();
	virtual void Move() = 0;
	virtual int ChoiceFighter();
	virtual void Fire(Vector2d speedBullet, Vector2d accelerationFire);
};

