#pragma once
#include "BaseView.h"

class GameView : public BaseView
{
protected:
	ALLEGRO_BITMAP *arrowLeft;
	ALLEGRO_BITMAP *arrowRight;
	ALLEGRO_BITMAP *menuIcon;
	ALLEGRO_BITMAP *tankRight;
	ALLEGRO_BITMAP *tankLeft;
public:
	GameView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);

	ViewType CheckSwitchView(int x, int y);

	virtual void Update();

	~GameView();
};

