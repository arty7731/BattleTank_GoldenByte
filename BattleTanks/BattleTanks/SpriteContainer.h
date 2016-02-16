#pragma once
#include "Header.h"
#include "AllegroHeader.h"

class SpriteContainer
{
	vector<ALLEGRO_BITMAP*> sprites;
	int currentFrameIndex;
	int frameWidth;
	int frameHeight;

public:
	SpriteContainer(ALLEGRO_BITMAP* atlas, int startX, int startY, int width, int height, int count);

	void SetCurrentFrame(int index);
	ALLEGRO_BITMAP* GetNextFrame();
	ALLEGRO_BITMAP* GetPrevFrame();
	ALLEGRO_BITMAP* GetCurrentFrame();
	ALLEGRO_BITMAP* GetFrameByIndex(int index);

	void SetFrameWidth(int width);
	int GetFrameWidth() const;
	void SetFrameHeight(int height);
	int GetFrameHeight() const;

	~SpriteContainer();
};

