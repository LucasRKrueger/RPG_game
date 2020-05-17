#include "Character.h"

Character::Character()
{
	this->xPosition = 0.0;
	this->yPosition = 0.0;

	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->luck = 0;

	this->skillPoints = 0;
	this->statPoints = 0;
}

Character::~Character()
{

}

void Character::initialize(std::string name)
{
	this->xPosition = 0.0;
	this->yPosition = 0.0;

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
	this->staminaMax = 10;
	this->damageMin = 2;
	this->damageMax = 4;
	this->defence = 1;
	this->luck = 1;


	this->skillPoints = 0;
	this->statPoints = 0;
}

void Character::printStatus() const
{
	std::cout << "= Character Sheet =" << std::endl;
	std::cout << "= Name: " << this->name << std::endl;
	std::cout << "= Level: " << this->level <<std::endl;
	std::cout << "= Exp: " << this->exp << std::endl;
	std::cout << "= Exp to Next Level: " << this->expNext <<std::endl;
	std::cout << std::endl;
	std::cout << "= Strenght: " << this->strength << std::endl;
	std::cout << "= Vitality: " << this->vitality << std::endl;
	std::cout << "= Dexterity: " << this->dexterity << std::endl;
	std::cout << "= Intelligence: " << this->intelligence << std::endl;
	std::cout <<  std::endl;
	std::cout << "= HP: " << this->hp<< " / " <<this-> hpMax << std::endl;
	std::cout << "= Stamina: " << this->stamina<< " / " << this->staminaMax << std::endl;
	std::cout << "= Dagame: " << this->damageMin<<  " / " << this->damageMax <<std::endl;
	std::cout << "= Defence: " << this->defence << std::endl;
	std::cout << "= Luck: " << this->luck << std::endl;

	std::cout << std::endl;
}

int Character::necessaryXP(int level)
{
	return static_cast<int>(50 / 3) * (pow(level, 3) - 6 * pow(level, 2) + 17 * level -12);
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