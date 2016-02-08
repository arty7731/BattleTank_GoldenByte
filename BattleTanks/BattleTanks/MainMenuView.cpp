#include "MainMenuView.h"

MainMenuView::MainMenuView(int width, int height, ALLEGRO_BITMAP * backgroundImage, ALLEGRO_FONT * mainFont)
	: BaseView(width, height, backgroundImage, mainFont)
{

}

ViewType MainMenuView::CheckSwitchView(int x, int y)
{
	if (y > 414 && y < 470 && x > 160 && x < 360)		// About
	{
		return ViewType::AboutMenu;
	}
	else if (x > 110 && x < 405 && y > 217 && y < 270)	// Game
	{
		return ViewType::GameView;
	}
	else if (x > 200 && x < 320 && y > 515 && y < 565)	// Exit
	{
		return ViewType::Exit;
	}
	else
	{
		return ViewType::MainMenu;
	}
}

void MainMenuView::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	al_draw_text(mainFont, al_map_rgb(255, 255, 255), 260, 100, ALLEGRO_ALIGN_CENTRE, "Main menu");
	al_draw_text(mainFont, al_map_rgb(255, 255, 255), 260, 200, ALLEGRO_ALIGN_CENTRE, "New game");
	al_draw_text(mainFont, al_map_rgb(255, 255, 255), 260, 300, ALLEGRO_ALIGN_CENTRE, "Resume");
	al_draw_text(mainFont, al_map_rgb(255, 255, 255), 260, 400, ALLEGRO_ALIGN_CENTRE, "About");
	al_draw_text(mainFont, al_map_rgb(255, 255, 255), 260, 500, ALLEGRO_ALIGN_CENTRE, "Exit");
}

MainMenuView::~MainMenuView()
{

}