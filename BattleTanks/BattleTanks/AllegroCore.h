#pragma once
#include "AllegroHeader.h"
#include "Header.h"
#include "BaseView.h"
#include "MainMenuView.h"
#include "AboutView.h"
#include "GameView.h"

class AllegroCore
{
	ALLEGRO_DISPLAY *display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *eventQueue;
	ALLEGRO_COLOR backgroundColor;

	ALLEGRO_BITMAP *backgroundImage;

	ALLEGRO_FONT *mainFont;

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