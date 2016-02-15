#pragma once
#include "AllegroHeader.h"
#include "Header.h"
#include "BaseView.h"
#include "MainMenuView.h"
#include "AboutView.h"
#include "GameView.h"
#include "Level.h"
#include "KeyboardController.h"

class AllegroCore
{
	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_COLOR backgroundColor;

	ALLEGRO_BITMAP *backgroundImage;
	ALLEGRO_BITMAP *roadImage;

	ALLEGRO_FONT *mainFont;

	Level *firstLevel;

	int width;
	int height;

	int fpsTimeout;

	BaseView *currentView;
	BaseView **views;

public:
	AllegroCore();

	void Initialize(int width, int height, int r, int g, int b);

	void Main();

	~AllegroCore();
};