#pragma once
#include "Movable.h"
#include "Bullet.h"

class Tank :
	public Movable
{
protected:
	Vector2d coordMuzzle;
	bool choiceFighter;
	int speedBullet;
	int angleMuzzle;

	Bullet *currentBullet;


public:
	Tank();
	Tank(float X, float Y, char objectName, int speed, Option direction, float mx, float my);

	void SetCoordMuzzle(float X, float Y);
	void SetCoordMuzzle(Vector2d coord);

	Vector2d GetCoordMuzzle() const;
	float GetSpeedBullet() const;
	float GetAngleMuzzle() const;

	virtual bool ChoiceFighter();
	virtual void ChangeDirection();
	void MuzzleUp();
	void MuzzleDown();
	virtual bool IsPlayerTank();
	virtual void Move() = 0;
	virtual Bullet* Fire(int speed, int angle) = 0;
};

