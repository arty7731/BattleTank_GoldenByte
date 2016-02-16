#include "KeyboardController.h"

Direction KeyboardController::GetDirection(ALLEGRO_EVENT &ev)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_LEFT: return Direction::Right;
		case ALLEGRO_KEY_RIGHT: return Direction::Left;
		case ALLEGRO_KEY_UP: return Direction::Up;
		case ALLEGRO_KEY_DOWN: return Direction::Down;
		}
		return Direction::None;
	}
}

