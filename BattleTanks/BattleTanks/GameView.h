#pragma once
#include "BaseView.h"
#include "SpriteContainer.h"
#include "Level.h"

class GameView : public BaseView
{
protected:
	ALLEGRO_BITMAP *arrowLeft;
	ALLEGRO_BITMAP *arrowRight;
	ALLEGRO_BITMAP *menuIcon;
	ALLEGRO_BITMAP *tankRight;
	ALLEGRO_BITMAP *tankLeft;
	ALLEGRO_BITMAP *bullet;

	SpriteContainer *tankSprite;

	Level* currentLevel;

	int whatFire;

	void DrawTanks();
	void DrawUI();
	void BorderLevel(Tank &tank);
	void DrawBullet(Tank &tank);

public:
	GameView(int width, int height, ALLEGRO_BITMAP *backgroundImage, ALLEGRO_FONT *mainFont);

	ViewType CheckSwitchView(int x, int y);
	void StartLevel(Level* level);
	virtual void Update();
	ViewType GetViewType() const;
	void WhoFire();
	void SetDirection(Direction dir);
	
	~GameView();
};

