#pragma once
#include "Movable.h"

class Tank :
	public Movable
{
protected:
	Vector2d coordMuzzle;
	bool choiceFighter;
	int speedBullet;
	int angleMuzzle;


public:
	Tank();
	Tank(int X, int Y, char objectName, int speed, Direction direction, int mx, int my);

	void SetCoordMuzzle(int X, int Y);
	void SetCoordMuzzle(Vector2d coord);

	Vector2d GetCoordMuzzle() const;
	int GetSpeedBullet() const;
	int GetAngleMuzzle() const;

	virtual void ChangeDirection();
	void MuzzleUp();
	void MuzzleDown();
	virtual bool IsPlayerTank();
	virtual bool ChoiceFighter();
	virtual void Move() = 0;
	virtual void Fire(int speedBullet, int accelerationFire);
};

