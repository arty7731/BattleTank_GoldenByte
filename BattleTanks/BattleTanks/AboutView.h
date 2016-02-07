#pragma once
#include "BaseView.h"

class AboutView : public BaseView
{
public:
	AboutView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);

	ViewType CheckSwitchView(int x, int y);

	virtual void Update();

	~AboutView();
};

