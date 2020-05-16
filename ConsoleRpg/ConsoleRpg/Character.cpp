#include "Character.h"

Character::Character()
{
	this->name = "";
	this->level = 1;
	this->exp = 0;
	this->expNext = 0;
	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
}

Character::~Character()
{

}

void Character::initialize(int level, std::string name)
{
	this->name = name;
	this->level = level;
	this->exp = 0;
	this->expNext = level*100;
	this->hp = 10;
	this->hpMax = 10;
	this->stamina = 10;
	this->damageMin = 2;
	this->damageMax = 4;
	this->defence = 1;
}