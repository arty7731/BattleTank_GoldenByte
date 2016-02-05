#include "BaseView.h"

BaseView::BaseView(int width, int height, ALLEGRO_BITMAP * backgroundImage, ALLEGRO_FONT * mainFont)
{
	this->backgroundImage = backgroundImage;
	this->mainFont = mainFont;
	this->height = height;
	this->width = width;
}