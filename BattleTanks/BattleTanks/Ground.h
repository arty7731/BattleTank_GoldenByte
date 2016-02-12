#pragma once
#include "Environment.h"
class Ground :
	public Environment
{

public:
	Ground();
	Ground(int X, int Y, char objectName);
	~Ground();
};

