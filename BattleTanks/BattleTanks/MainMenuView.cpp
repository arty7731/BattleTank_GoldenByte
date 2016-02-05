#include "MainMenuView.h"

MainMenuView::MainMenuView(int width, int height, ALLEGRO_BITMAP * backgroundImage, ALLEGRO_FONT * mainFont)
	: BaseView(width, height, backgroundImage, mainFont)
{

}

void MainMenuView::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	al_draw_text(mainFont, al_map_rgb(255, 255, 255), 260, 100, ALLEGRO_ALIGN_CENTRE, "Main menu");

}

MainMenuView::~MainMenuView()
{

}