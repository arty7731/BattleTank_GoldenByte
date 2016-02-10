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
	coord.SetVector2d(X, Y);
}

void GameObject::SetGameObject(int X, int Y, char objectName)
{
	SetCoords(X, Y);
	this->objectName = objectName;
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
