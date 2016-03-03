#include "KeyboardController.h"

Option KeyboardController::GetDirection(ALLEGRO_EVENT &ev)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_LEFT: return Option::Right;
		case ALLEGRO_KEY_RIGHT: return Option::Left;
		case ALLEGRO_KEY_UP: return Option::Up;
		case ALLEGRO_KEY_DOWN: return Option::Down;
		case ALLEGRO_KEY_SPACE: return Option::Fire;
		}
		return Option::None;
	}
}

