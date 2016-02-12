#include "Level.h"



void Level::Initialization()
{
	objects = new GameObject*[objectCount + 2 + 1];
	movable = new Movable*[2 + 1];

	int counter = 0;
	movable[counter] = new PlayerTank(10, 10, 'P', 3, Direction::None, 10, 15);
	objects[counter] = movable[counter++];
	movable[counter] = new EnemyTank(100, 10, 'E', 3, Direction::None, 100, 15);
	objects[counter] = movable[counter++];
	movable[counter] = new Bullet(10, 15, 'F', 3, Direction::None);
	objects[counter] = movable[counter];

}

Level::Level()
{
}

Level::Level(int width, int height, int objectCount)
{
	this->height = height;
	this->width = width;
	this->objectCount = objectCount;
}


void Level::LevelTimerTick()
{
	for (int i = 0; i < 2 + 1; i++)
	{
		if (movable[i] != nullptr)
		{
			movable[i]->Move();

			if (movable[i]->GetX() <= 0 || movable[i]->GetX() >= width - 1
				|| movable[i]->GetY() <= 0 || movable[i]->GetY() >= height - 1)
			{
				//movable[i]->ChangeDirection();
			}
		}
	}
}

Level::~Level()
{
}