#pragma once
#include "GameObject.h"
class Environment :
	public GameObject
{
public:
	Environment();
	Environment(int X, int Y, char objectName);
	~Environment() = 0;
};

