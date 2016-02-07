#include "AboutView.h"

AboutView::AboutView(int width, int height, ALLEGRO_BITMAP * backgroundImage, ALLEGRO_FONT * mainFont)
	: BaseView(width, height, backgroundImage, mainFont)
{

}

ViewType AboutView::CheckSwitchView(int x, int y)
{
	if (x > 190 && x < 330 && y > 515 && y < 566)
	{
		return ViewType::MainMenu;
	}
	else
	{
		return ViewType::AboutMenu;
	}
}

void AboutView::Update()
{
	al_draw_bitmap(backgroundImage, 0, 0, 0);
	al_draw_text(mainFont, al_map_rgb(255, 255, 255), 260, 100, ALLEGRO_ALIGN_CENTRE, "About menu");
	al_draw_text(mainFont, al_map_rgb(255, 255, 255), 260, 500, ALLEGRO_ALIGN_CENTRE, "back");
}

AboutView::~AboutView()
{

}