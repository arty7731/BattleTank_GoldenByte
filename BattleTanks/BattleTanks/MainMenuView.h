#pragma once
#include "BaseView.h"

class MainMenuView : public BaseView
{
public:
	MainMenuView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);

	ViewType CheckSwitchView(int x, int y);
	bool IsExitButton(int x, int y);

	virtual void Update();

	~MainMenuView();
};

