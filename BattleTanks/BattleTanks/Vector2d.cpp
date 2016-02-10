#include "Vector2d.h"



Vector2d::Vector2d()
{
	X = Y = 0;
}

Vector2d::Vector2d(int x, int y)
{
	SetVector2d(x, y);
}

void Vector2d::SetVector2d(int x, int y)
{
	SetX(x);
	SetY(y);
}

void Vector2d::SetX(int x)
{
	this->X = x;
}

void Vector2d::SetY(int y)
{
	this->Y = y;
}

int Vector2d::GetX() const
{
	return X;
}

int Vector2d::GetY() const
{
	return Y;
}

Vector2d& Vector2d::operator+(Vector2d vector)
{
	Vector2d tmp;
	tmp.X = X;
	tmp.Y = Y;

	tmp.X += vector.X;
	tmp.Y += vector.Y;
	return tmp;
}

Vector2d& Vector2d::operator+=(Vector2d vector)
{
	this->X += vector.X;
	this->Y += vector.Y;
	return *this;
}

Vector2d& Vector2d::operator - (Vector2d vector)
{
	Vector2d tmp;
	tmp.X = X;
	tmp.Y = Y;

	tmp.X -= vector.X;
	tmp.Y -= vector.Y;
	return tmp;
}

Vector2d& Vector2d::operator -= (Vector2d vector)
{
	this->X -= vector.X;
	this->Y -= vector.Y;
	return *this;
}

Vector2d& Vector2d::operator*(int number)
{
	Vector2d tmp;
	tmp.X = X;
	tmp.Y = Y;

	tmp.X *= number;
	tmp.Y *= number;
	return tmp;
}

Vector2d& Vector2d::operator*=(int number)
{
	this->X *= number;
	this->Y *= number;
	return *this;
}

bool Vector2d::operator == (Vector2d vector)
{
	if (this->X == vector.X && this->Y == vector.Y) return true;
	return false;
}

bool Vector2d::operator != (Vector2d vector)
{
	if (this->X != vector.X && this->Y != vector.Y) return true;
	return false;
}

Vector2d & Vector2d::operator=(Vector2d vector)
{
	this->X = vector.X;
	this->Y = vector.Y;
	return *this;
}
