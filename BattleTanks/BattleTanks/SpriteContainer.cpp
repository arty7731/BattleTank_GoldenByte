#include "SpriteContainer.h"

SpriteContainer::SpriteContainer(ALLEGRO_BITMAP* atlas, int startX, int startY, int width, int height, int count)
{
	for (int i = 0; i < count; i++)
	{
		ALLEGRO_BITMAP* s = al_create_sub_bitmap(atlas, startX, startY, width, height);
		startX += width;
		sprites.push_back(s);

		currentFrameIndex = 0;
	}	
}

void SpriteContainer::SetCurrentFrame(int index)
{
	currentFrameIndex = index;
}

ALLEGRO_BITMAP* SpriteContainer::GetFrameByIndex(int index)
{
	int spriteCount = 9;
	if (index > sprites.size() - 1)
	{
		currentFrameIndex = sprites.size() - 1;
		return sprites[currentFrameIndex];
	}
	else if (index < 0)
	{
		currentFrameIndex = 0;
		return sprites[0];
	}
	else
	{
		return sprites[index];
	}
}

ALLEGRO_BITMAP* SpriteContainer::GetCurrentFrame()
{
	return sprites[currentFrameIndex];
}

ALLEGRO_BITMAP* SpriteContainer::GetNextFrame()
{
	if (currentFrameIndex + 1 < sprites.size())
	{
		return sprites[++currentFrameIndex];
	}

	return nullptr;
}

ALLEGRO_BITMAP* SpriteContainer::GetPrevFrame()
{
	if (currentFrameIndex > 0)
	{
		return sprites[--currentFrameIndex];
	}

	return nullptr;
}

SpriteContainer::~SpriteContainer()
{
}
