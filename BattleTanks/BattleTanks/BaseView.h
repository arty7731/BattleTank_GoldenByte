#pragma once
#include "Header.h"
#include "AllegroHeader.h"

class BaseView
{
protected:
	int width;
	int height;
	ALLEGRO_FONT *mainFont;
	ALLEGRO_BITMAP *backgroundImage;

public:
	BaseView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);

	virtual void Update() = 0;

};

