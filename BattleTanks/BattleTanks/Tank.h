#pragma once
#include "Movable.h"

class Tank :
	public Movable
{
protected:
	Vector2d coordTank[3];

	Vector2d speedBullet;
	Vector2d accelerationFire;

public:
	Tank();
	Tank(int X, int Y, char objectName, int speed,
		int rx, int ry, int lx, int ly, int mx, int my);

	void SetCoordRightSide(int X, int Y);
	void SetCoordRightSide(Vector2d coord);

	void SetCoordLeftSide(int X, int Y);
	void SetCoordLeftSide(Vector2d coord);

	void SetCoordMuzzle(int X, int Y);
	void SetCoordMuzzle(Vector2d coord);

	Vector2d GetCoordLeftSide() const;
	Vector2d GetCoordRightSide() const;
	Vector2d GetCoordMuzzle() const;
	Vector2d GetSpeedBullet() const;
	Vector2d GetAccelerationFire() const;

	virtual void Move() {}
	virtual int ChoiceFighter();
	virtual void Fire(Vector2d speedBullet, Vector2d accelerationFire);
};

