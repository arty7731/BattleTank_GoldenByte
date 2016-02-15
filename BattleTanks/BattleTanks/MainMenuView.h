#pragma once
#include "BaseView.h"

class MainMenuView : public BaseView
{
public:
	MainMenuView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);

	ViewType CheckSwitchView(int x, int y);
	ViewType GetViewType() const;
	virtual void Update();

	~MainMenuView();
};

