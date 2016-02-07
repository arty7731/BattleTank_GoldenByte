#pragma once
#include "BaseView.h"

class GameView : public BaseView
{
public:
	GameView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);

	ViewType CheckSwitchView(int x, int y);

	virtual void Update();

	~GameView();
};

