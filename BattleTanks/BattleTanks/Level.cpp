#include "Level.h"


void Level::Initialization()
{
	objects = new GameObject*[objectCount + 2 + 1];
	movable = new Movable*[2 + 1];

	int counter = 0;
	for (counter = 0; counter < objectCount; counter++)
	{
		objects[counter] = nullptr;
	}
	movable[counter] = new PlayerTank(1000, 310, 'P', 3, Direction::None, 1010, 400);
	objects[counter] = movable[counter++];
	movable[counter] = new EnemyTank(100, 310, 'E', 3, Direction::None, 100, 15);
	objects[counter] = movable[counter++];
	movable[counter] = nullptr;// new Bullet(10, 15, 'F', 3, Direction::None);
	objects[counter] = nullptr;// movable[counter];
	objectCount = 2;
}

Level::Level()
{
}

Level::Level(int width, int height, int objectCount)
{
	this->height = height;
	this->width = width;
	this->objectCount = objectCount;

	Initialization();
}

int Level::GetWidth() const
{
	return width;
}

int Level::GetHeigth() const
{
	return height;
}


void Level::LevelTimerTick()
{
	static int frame = 0;

	if (++frame % 5 != 0) return;


	for (int i = 0; i < 2 + 1; i++)
	{
		if (movable[i] != nullptr)
		{
			movable[i]->Move();

			if (movable[i]->GetX() < 0 || movable[i]->GetX() >= width - 1
				|| movable[i]->GetY() <= 0 || movable[i]->GetY() >= height)
			{
				movable[i]->SetDirection(Direction::None);
			}
		}
	}
}

Tank * Level::GetPlayerTank() const
{
	for (int i = 0; i < 2 + 1; i++)
	{
		if (movable[i] == nullptr) continue;
		Tank *tank = dynamic_cast<Tank*>(movable[i]);
		if(tank != nullptr && tank->IsPlayerTank()) return tank;
	}

}

Tank * Level::GetEnemyTank() const
{
	for (int i = 0; i < 2 + 1; i++)
	{
		if (movable[i] == nullptr) continue;
		Tank *tank = dynamic_cast<Tank*>(movable[i]);
		if (tank != nullptr && !tank->IsPlayerTank()) return tank;
	}
}

Bullet * Level::GetBullet() const
{
	for (int i = 0; i < 2 + 1; i++)
	{
		if (movable[i] == nullptr) continue;
		Bullet *bullet = dynamic_cast<Bullet*>(movable[i]);
		if (bullet != nullptr && bullet->IsBullet()) return bullet;
	}
	return nullptr;
}

void Level::SetBullet(Bullet* bullet)
{
	this->bullet = bullet;
	movable[objectCount++] = bullet;
}

Level::~Level()
{
}