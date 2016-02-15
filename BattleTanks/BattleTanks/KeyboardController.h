#pragma once
#include "AllegroHeader.h"
#include "CoreEnumeration.h"

class KeyboardController
{
public:

	Direction GetDirection(ALLEGRO_EVENT &ev);
};