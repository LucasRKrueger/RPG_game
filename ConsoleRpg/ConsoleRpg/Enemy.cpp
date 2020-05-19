#include "Enemy.h"

Enemy::Enemy(int level)
{
	this->level = level;
	this->hpMax = level * 10;
	this->hp = this->hpMax;	
	this->damageMin = this->level * 4;
	this->damageMax = this->level * 5;
	this->dropChance = rand() % 100;
	this->defence = rand() % 100;
	this->accuracy = rand() % 100;
}

Enemy::~Enemy()
{

}
