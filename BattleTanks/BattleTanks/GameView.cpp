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
	
}

ViewType GameView::CheckSwitchView(int x, int y)
{
	
	return ViewType::GameView;
	
}

bool flag = false;

void GameView::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	al_draw_bitmap(arrowLeft, 20, 580, 0);
	al_convert_mask_to_alpha(arrowLeft, al_map_rgb(0, 0, 0));
	al_draw_bitmap(arrowRight, 1100, 580, 0);
	al_convert_mask_to_alpha(arrowRight, al_map_rgb(0, 0, 0));
	al_draw_bitmap(menuIcon, 1170, 10, 0);
	al_convert_mask_to_alpha(menuIcon, al_map_rgb(0, 0, 0));
	//ALLEGRO_BITMAP *sub_bitmap = al_create_sub_bitmap(tankRight, 0, 0, 116, 116);
	//al_draw_bitmap(sub_bitmap, 1100, 450, 0);	

	ALLEGRO_BITMAP *sub_bitmap;

	if (flag)
	{
		sub_bitmap = tankSprite->GetNextFrame();		
	}
	else
	{
		sub_bitmap = tankSprite->GetPrevFrame();
	}

	if (sub_bitmap == nullptr)
	{
		flag = !flag;
	}
	else
	{
		al_draw_bitmap(sub_bitmap, 1100, 450, 0);	
	}
}

GameView::~GameView()
{

}