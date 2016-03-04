#include "Level.h"


void Level::Initialization()
{
	//objects = new GameObject*[objectCount + 2 + 1];
	//movable = new Movable*[2 + 1];

	//int counter = 0;
	//for (counter = 0; counter < objectCount; counter++)
	//{
	//	objects[counter] = nullptr;
	//}
	//movable[counter] = new PlayerTank(1000.0f, 310.0f, 'P', 3, Option::None, 1010.0f, 400.0f);
	//objects[counter] = movable[counter++];
	//movable[counter] = new EnemyTank(100.0f, 310.0f, 'E', 3, Option::None, 100.0f, 15.0f);
	//objects[counter] = movable[counter++];
	//movable[counter] = nullptr;// new Bullet(10, 15, 'F', 3, Direction::None);
	//objects[counter] = nullptr;// movable[counter];
	//objectCount = 2;
	movable.push_back(new PlayerTank(1000.0f, 310.0f, 'P', 3, Option::None, 1010.0f, 400.0f));
	objects.push_back(new PlayerTank(1000.0f, 310.0f, 'P', 3, Option::None, 1010.0f, 400.0f));

	movable.push_back(new EnemyTank(100.0f, 310.0f, 'E', 3, Option::None, 100.0f, 15.0f));
	objects.push_back(new EnemyTank(100.0f, 310.0f, 'E', 3, Option::None, 100.0f, 15.0f));
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
	for (int i = 0; i < movable.size(); i++)
	{
		if (movable[i] != nullptr)
		{
			movable[i]->Move();

			if (movable[i]->GetX() < 0 || movable[i]->GetX() >= width - 1
				|| movable[i]->GetY() <= 0 || movable[i]->GetY() >= height)
			{
				movable[i]->SetDirection(Option::None);
			}
		}
	}
}

Tank * Level::GetPlayerTank() const
{
	for (int i = 0; i < movable.size(); i++)
	{
		if (movable[i] == nullptr) continue;
		Tank *tank = dynamic_cast<Tank*>(movable[i]);
		if(tank != nullptr && tank->IsPlayerTank()) return tank;
	}

}

Tank * Level::GetEnemyTank() const
{
	for (int i = 0; i < movable.size(); i++)
	{
		if (movable[i] == nullptr) continue;
		Tank *tank = dynamic_cast<Tank*>(movable[i]);
		if (tank != nullptr && !tank->IsPlayerTank()) return tank;
	}
}

Bullet * Level::GetBullet() const
{
		Bullet *bullet = dynamic_cast<Bullet*>(movable.back());
		if (bullet != nullptr && bullet->IsBullet())
		{
			//movable.pop_back();
			return bullet;
		}

		return nullptr;
}

void Level::SetBullet(Bullet* bullet)
{
	this->bullet = bullet;
	movable.push_back(bullet);
}

Level::~Level()
{
}