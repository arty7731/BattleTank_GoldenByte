#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(int X, int Y, char objectName)
{
	SetGameObject(X, Y, objectName);
}

void GameObject::SetCoords(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

void GameObject::SetGameObject(int X, int Y, char objectName)
{
	SetCoords(X, Y);
	this->objectName = objectName;
}

int GameObject::GetX() const
{
	return X;
}

int GameObject::GetY() const
{
	return Y;
}

char GameObject::GetObjectName() const
{
	return objectName;
}


GameObject::~GameObject()
{
}
