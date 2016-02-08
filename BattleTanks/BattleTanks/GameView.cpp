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
}

ViewType GameView::CheckSwitchView(int x, int y)
{
	if (x > 110 && x > 405 && y > 217 && y > 270)
	{
		return ViewType::MainMenu;
	}
	else
	{
		return ViewType::GameView;
	}
}

void GameView::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	al_draw_bitmap(arrowLeft, 20, 580, 0);
	al_convert_mask_to_alpha(arrowLeft, al_map_rgb(0, 0, 0));
	al_draw_bitmap(arrowRight, 1100, 580, 0);
	al_convert_mask_to_alpha(arrowRight, al_map_rgb(0, 0, 0));
	al_draw_bitmap(menuIcon, 1170, 10, 0);
	al_convert_mask_to_alpha(menuIcon, al_map_rgb(0, 0, 0));
	//al_draw_text(mainFont, al_map_rgb(255, 255, 255), 260, 100, ALLEGRO_ALIGN_CENTRE, "Game is here!");
}

GameView::~GameView()
{

}