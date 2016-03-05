#pragma once
#include "BaseView.h"
#include "SpriteContainer.h"
#include "Level.h"
#include "KeyboardController.h"

class GameView : public BaseView
{
protected:
	ALLEGRO_BITMAP *arrowLeft;
	ALLEGRO_BITMAP *arrowRight;
	ALLEGRO_BITMAP *menuIcon;
	ALLEGRO_BITMAP *tankRight;
	ALLEGRO_BITMAP *tankLeft;
	ALLEGRO_BITMAP *bullet;

	KeyboardController* currentController;

	SpriteContainer *tankSprite;

	Level* currentLevel;

	static int whatFire;

	void DrawTanks();
	void DrawUI();
	void BorderLevel(Tank &tank);
	void DrawBullet();

public:
	GameView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont, KeyboardController *keyController);

	void ProcessIvent(ALLEGRO_EVENT *ev);
	ViewType CheckSwitchView(int x, int y);
	void StartLevel(Level* level);
	virtual void Update();
	ViewType GetViewType() const;
	void WhoFire();
	void SetDirection(Option dir);
	
	~GameView();
};

