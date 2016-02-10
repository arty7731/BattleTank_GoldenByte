#pragma once

class Vector2d
{
	int X;
	int Y;
public:
	Vector2d();
	Vector2d(int x, int y);

	void SetVector2d(int x, int y);
	void SetX(int x);
	void SetY(int y);

	int GetX() const;
	int GetY() const;

	Vector2d& operator + (Vector2d vector);
	Vector2d& operator += (Vector2d vector);

	Vector2d& operator - (Vector2d vector);
	Vector2d& operator -= (Vector2d vector);

	Vector2d& operator * (int number);
	Vector2d& operator *= (int number);

	bool operator == (Vector2d vector);
	bool operator != (Vector2d vector);

	Vector2d& operator = (Vector2d vector);


};