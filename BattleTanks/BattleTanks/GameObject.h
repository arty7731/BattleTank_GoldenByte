#pragma once
#include "Vector2d.h"

class GameObject
{
protected:
	Vector2d coord;
	char objectName;

public:
	GameObject();
	GameObject(float X, float Y, char objectName);

	void SetCoords(float X, float Y);
	void SetGameObject(float X, float Y, char objectName);
	void SetX(float X);
	void SetY(float Y);

	float GetX() const;
	float GetY() const;
	char GetObjectName() const;

	virtual ~GameObject() = 0;
};