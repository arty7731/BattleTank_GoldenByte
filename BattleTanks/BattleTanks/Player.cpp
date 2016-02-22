#include "Player.h"



Player::Player()
{
	name = "Empty";
	money = level = 0;
}

Player::Player(string name)
{
	this->name = name;
}

void Player::SetMoney(int money)
{
	this->money = money;
}

void Player::SetLevel(int level)
{
	this->level = level;
}

void Player::SetBulletPack(Bullet * bulletPack)
{
	this->bulletPack = bulletPack;
}

void Player::SetTank(Tank * tank)
{
	this->tank = tank;
}

string Player::GetName() const
{
	return name;
}

int Player::GetMoney() const
{
	return money;
}

int Player::GetLevel() const
{
	return level;
}

Bullet * Player::GetBulletPack() const
{
	return bulletPack;
}

Tank * Player::GetTank() const
{
	return tank;
}

void Player::SaveGame()
{
	ofstream writer;
	writer.open("saveGame.save", ios::binary);
	if (writer.is_open())
	{
		writer.write((char*)this, sizeof(this));
		writer.close();
	}
}

Player* Player::LoadGame()
{
	ifstream reader;
	reader.open("saveGame.save", ios::binary);
	if (reader.is_open())
	{
		reader.read((char*)this, sizeof(this));
		reader.close();
	};
	return this;
}
