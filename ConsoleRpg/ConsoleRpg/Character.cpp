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

void Character::initialize(const std::string name)
{
	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = necessaryXP(this->level);

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hp = 10;
	this->hpMax = 10;
	this->stamina = 10;
	this->damageMin = 2;
	this->damageMax = 4;
	this->defence = 1;


	this->skillPoints = 0;
	this->statPoints = 0;

}

std::string Character::getAsString() const
{

}

int Character::necessaryXP(int level)
{
	return (50 / 3) * (pow(level, 3) - 6 * pow(level, 3) + (17 * level) - 11);
}

void Character::levelUp()
{
	while (exp >= expNext)
	{
		exp -= expNext;
		level++;
		this->expNext = necessaryXP(this->level);
		this->statPoints++;
		this->skillPoints++;
	}
}