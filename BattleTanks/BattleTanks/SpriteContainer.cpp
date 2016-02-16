#include "SpriteContainer.h"

SpriteContainer::SpriteContainer(ALLEGRO_BITMAP* atlas, int startX, int startY, int width, int height, int count)
{
	SetFrameHeight(height);
	SetFrameWidth(width);
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

void SpriteContainer::SetFrameWidth(int width)
{
	this->frameWidth = width;
}

int SpriteContainer::GetFrameWidth() const
{
	return this->frameWidth;
}

void SpriteContainer::SetFrameHeight(int height)
{
	this->frameHeight = height;
}

int SpriteContainer::GetFrameHeight() const
{
	return frameHeight;
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
