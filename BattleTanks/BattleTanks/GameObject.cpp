#include "GameObject.h"



GameObject::GameObject()
{
	coord.SetVector2d(0, 0);
	objectName = 'E';
}

GameObject::GameObject(int X, int Y, char objectName)
{
	SetGameObject(X, Y, objectName);
}

void GameObject::SetCoords(int X, int Y)
{
	SetX(X);
	SetY(Y);
}

void GameObject::SetGameObject(int X, int Y, char objectName)
{
	SetCoords(X, Y);
	this->objectName = objectName;
}

void GameObject::SetX(int X)
{
	coord.SetX(X);
}

void GameObject::SetY(int Y)
{
	coord.SetY(Y);
}

int GameObject::GetX() const
{
	return coord.GetX();
}

int GameObject::GetY() const
{
	return coord.GetY();
}

char GameObject::GetObjectName() const
{
	return objectName;
}


GameObject::~GameObject()
{
}
