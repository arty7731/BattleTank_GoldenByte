#pragma once
#include "Header.h"
#include "AllegroHeader.h"
#include "CoreEnumeration.h"

class BaseView
{
protected:
	int width;
	int height;
	ALLEGRO_FONT *mainFont;
	ALLEGRO_BITMAP *backgroundImage;

public:
	BaseView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);

	virtual ViewType CheckSwitchView(int x, int y) = 0;
	virtual void Update() = 0;
	virtual ViewType GetViewType() const = 0;
};

