#pragma once
#include "Vector2d.h"

class GameObject
{
protected:
	Vector2d coord;
	char objectName;

public:
	GameObject();
	GameObject(int X, int Y, char objectName);

	void SetCoords(int X, int Y);
	void SetGameObject(int X, int Y, char objectName);

	int GetX() const;
	int GetY() const;
	char GetObjectName() const;

	virtual ~GameObject() = 0;
};

