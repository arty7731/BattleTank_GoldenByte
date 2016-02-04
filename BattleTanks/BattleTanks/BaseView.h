#pragma once
#include "Header.h"

class BaseView
{
public:
	BaseView();

	virtual void Draw() = 0;

	~BaseView();
};

