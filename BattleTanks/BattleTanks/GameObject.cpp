#include "GameObject.h"



GameObject::GameObject()
{
	coord.SetVector2d(0, 0);
	objectName = 'E';
}

GameObject::GameObject(float X, float Y, char objectName)
{
	SetGameObject(X, Y, objectName);
}

void GameObject::SetCoords(float X, float Y)
{
	SetX(X);
	SetY(Y);
}

void GameObject::SetGameObject(float X, float Y, char objectName)
{
	SetCoords(X, Y);
	this->objectName = objectName;
}

void GameObject::SetX(float X)
{
	coord.X = X;
}

void GameObject::SetY(float Y)
{
	coord.Y = Y;
}

float GameObject::GetX() const
{
	return coord.X;
}

float GameObject::GetY() const
{
	return coord.Y;
}

char GameObject::GetObjectName() const
{
	return objectName;
}


GameObject::~GameObject()
{
}
