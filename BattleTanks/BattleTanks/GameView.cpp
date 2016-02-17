#include "GameView.h"

GameView::GameView(int width, int height, ALLEGRO_BITMAP * backgroundImage, ALLEGRO_FONT * mainFont)
	: BaseView(width, height, backgroundImage, mainFont)
{
	arrowLeft = nullptr;
	arrowLeft = al_load_bitmap("Resources/Images/arrowLeft.png");
	if (arrowLeft == nullptr) throw "Load image (arrowLeft) error!";
	arrowRight = nullptr;
	arrowRight = al_load_bitmap("Resources/Images/arrowRight.png");
	if (arrowRight == nullptr) throw "Load arrowRight error!";
	menuIcon = nullptr;
	menuIcon = al_load_bitmap("Resources/Images/menuIcon.png");
	if (menuIcon == nullptr) throw "Load menuIcon error!";
	tankRight = nullptr;
	tankRight = al_load_bitmap("Resources/Images/tankRight.png");
	if (tankRight == nullptr) throw "Load tankRight error!";
	tankLeft = nullptr;

	al_convert_mask_to_alpha(tankRight, al_map_rgb(41, 41, 41));
	tankSprite = new SpriteContainer(tankRight, 0, 0, 180, 175, 9);
	
	whatFire = 2;
}

ViewType GameView::CheckSwitchView(int x, int y)
{
	return ViewType::GameView;	
}

ViewType GameView::GetViewType() const
{
	return ViewType::GameView;
}

void GameView::StartLevel(Level* level)
{
	currentLevel = level;
}

bool flag = false;

void GameView::Update()
{
	currentLevel->LevelTimerTick();

	DrawUI();
	DrawTanks();
}

void GameView::DrawUI()
{
	// UI elements
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	al_draw_bitmap(arrowLeft, 20, 580, 0);
	al_convert_mask_to_alpha(arrowLeft, al_map_rgb(0, 0, 0));
	al_draw_bitmap(arrowRight, 1100, 580, 0);
	al_convert_mask_to_alpha(arrowRight, al_map_rgb(0, 0, 0));
	al_draw_bitmap(menuIcon, 1170, 10, 0);
	al_convert_mask_to_alpha(menuIcon, al_map_rgb(0, 0, 0));
}

void GameView::DrawTanks()
{
	ALLEGRO_BITMAP *sub_bitmap_player;
	ALLEGRO_BITMAP *sub_bitmap_enemy;


	Tank* playerTank = currentLevel->GetPlayerTank();
	Tank* enemyTank = currentLevel->GetEnemyTank();

	sub_bitmap_player = tankSprite->GetFrameByIndex(playerTank->GetCoordMuzzle().GetY() / 10);
	sub_bitmap_enemy = tankSprite->GetFrameByIndex(enemyTank->GetCoordMuzzle().GetY() / 10);
	
	/*if (playerTank->GetX() < 0)
	{
		playerTank->SetCoords(0, playerTank->GetY());
	}
	if ( playerTank->GetX() > ( currentLevel->GetWidth() - tankSprite->GetFrameWidth() ) )
	{
		playerTank->SetCoords( (currentLevel->GetWidth() - tankSprite->GetFrameWidth() ), playerTank->GetY() );
	}*/
	al_draw_bitmap(sub_bitmap_player, playerTank->GetX(), playerTank->GetY(), 0);
	al_draw_bitmap(sub_bitmap_enemy, enemyTank->GetX(), enemyTank->GetY(), ALLEGRO_FLIP_HORIZONTAL);
	
}

void GameView::WhatFire()
{
	if (whatFire == 1) whatFire = 2;
	else whatFire = 1;
}

void GameView::SetDirection(Direction dir)
{
	switch (whatFire)
	{
	case 1:
		currentLevel->GetPlayerTank()->SetDirection(dir);

		if (dir == Direction::Up)
		{
			currentLevel->GetPlayerTank()->MuzzleUp();
		}
		else if (dir == Direction::Down)
		{
			currentLevel->GetPlayerTank()->MuzzleDown();
		}
		break;
	case 2:
		currentLevel->GetEnemyTank()->SetDirection(dir);

		if (dir == Direction::Up)
		{
			currentLevel->GetEnemyTank()->MuzzleUp();
		}
		else if (dir == Direction::Down)
		{
			currentLevel->GetEnemyTank()->MuzzleDown();
		}
		break;
	}

}

GameView::~GameView()
{

}