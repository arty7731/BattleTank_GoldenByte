#include "Vector2d.h"


Vector2d::Vector2d()
{
	X = Y = 0;
}

Vector2d::Vector2d(float x, float y)
{
	SetVector2d(x, y);
}

void Vector2d::SetVector2d(float x, float y)
{
	X = x;
	Y = y;
}