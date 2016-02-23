#include "GameView.h"

GameView::GameView(int width, int height, ALLEGRO_BITMAP * backgroundImage, ALLEGRO_FONT * mainFont, KeyboardController *keyController)
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
	
	bullet = al_load_bitmap("Resources/Images/bullet.png");
	if (bullet == nullptr) throw "Load bullet error!";

	this->currentController = keyController;

	whatFire = 2;
}

void GameView::ProcessIvent(ALLEGRO_EVENT *ev)
{

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

void GameView::BorderLevel(Tank & tank)
{
	if (tank.GetX() < 0)
	{
		tank.SetX(0);
	}
	if (tank.GetX() > (currentLevel->GetWidth() - tankSprite->GetFrameWidth()))
	{
		tank.SetX(currentLevel->GetWidth() - tankSprite->GetFrameWidth());
	}
}

void GameView::DrawBullet(Tank &tank)
{
	al_draw_bitmap(bullet, tank.GetCoordMuzzle().GetX(), tank.GetCoordMuzzle().GetY(), 0);
	al_convert_mask_to_alpha(bullet, al_map_rgb(255, 255, 255));
}

void GameView::DrawTanks()
{
	ALLEGRO_BITMAP *sub_bitmap_player;
	ALLEGRO_BITMAP *sub_bitmap_enemy;


	Tank* playerTank = currentLevel->GetPlayerTank();
	Tank* enemyTank = currentLevel->GetEnemyTank();

	DrawBullet(*playerTank);

	sub_bitmap_player = tankSprite->GetFrameByIndex(playerTank->GetAngleMuzzle() / 10);
	sub_bitmap_enemy = tankSprite->GetFrameByIndex(enemyTank->GetAngleMuzzle() / 10);
	
	BorderLevel(*playerTank);
	BorderLevel(*enemyTank);

	al_draw_bitmap(sub_bitmap_player, playerTank->GetX(), playerTank->GetY(), 0);
	al_draw_bitmap(sub_bitmap_enemy, enemyTank->GetX(), enemyTank->GetY(), ALLEGRO_FLIP_HORIZONTAL);
	
}

void GameView::WhoFire()
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