#pragma once
#include "Header.h"
#include "Bullet.h"
#include "Tank.h"

class Player
{
	string name;
	int money;
	int level;
	Bullet *bulletPack;
	Tank *tank;

public:
	Player();
	Player(string name);

	void SetMoney(int money);
	void SetLevel(int level);
	void SetBulletPack(Bullet *bulletPack);
	void SetTank(Tank *tank);

	string GetName() const;
	int GetMoney() const;
	int GetLevel() const;
	Bullet* GetBulletPack() const;
	Tank* GetTank() const;

	void SaveGame();
	Player* LoadGame();

};

