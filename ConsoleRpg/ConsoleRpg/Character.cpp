#include "Character.h"

Character::Character()
{
	this->xPosition = 0.0;
	this->yPosition = 0.0;
	this->distanceTravelled = 0;

	this->gold = 0;

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
	this->accuracy = 0;
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
	this->distanceTravelled = 0;

	this->gold = 100;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = necessaryXP(this->level);

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hpMax = (this->vitality * 2) + (this->strength/2);
	this->hp = hpMax;
	this->staminaMax = this->vitality + (this->strength/2) + (this->dexterity/3);
	this->stamina = this->staminaMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->defence = this->dexterity + (this->intelligence/2);
	this->luck = this->intelligence;
	this->accuracy = this->dexterity / 2;


	this->skillPoints = 0;
	this->statPoints = 0;
}

void Character::printStatus() const
{
	std::cout << "| ## Character Sheet ##" << std::endl;
	std::cout << "|================================" << std::endl;
	std::cout << "| Name: " << this->name << std::endl;
	std::cout << "| Level: " << this->level <<std::endl;
	std::cout << "| Exp: " << this->exp << std::endl;
	std::cout << "| Exp to Next Level: " << this->expNext <<std::endl;
	std::cout << "|================================" <<std::endl;
	std::cout << "| Strenght: " << this->strength << std::endl;
	std::cout << "| Vitality: " << this->vitality << std::endl;
	std::cout << "| Dexterity: " << this->dexterity << std::endl;
	std::cout << "| Intelligence: " << this->intelligence << std::endl;
	std::cout << "================================"<<std::endl;
	std::cout << "| HP: " << this->hp<< " / " <<this-> hpMax << std::endl;
	std::cout << "| Stamina: " << this->stamina<< " / " << this->staminaMax << std::endl;
	std::cout << "| Damage: " << this->damageMin<<  " / " << this->damageMax <<std::endl;
	std::cout << "| Defence: " << this->defence << std::endl;
	std::cout << "| Accuracy: " << this->accuracy << std::endl;
	std::cout << "| Luck: " << this->luck << std::endl;

	std::cout << "================================"<< std::endl;
	std::cout << std::endl;
}

int Character::necessaryXP(int level)
{
	return static_cast<int>(50 / 3) * (pow(level, 3) - 6 * pow(level, 2) + 17 * level -12) + 100;
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


std::string Character::getAsString() const
{
	return std::to_string(xPosition) + " "
		+ std::to_string(yPosition) + " "
		+ name + " "
		+ std::to_string(level) + " "
		+ std::to_string(exp) + " "
		+ std::to_string(strength) + " "
		+ std::to_string(vitality) + " "
		+ std::to_string(dexterity) + " "
		+ std::to_string(intelligence) + " "
		+ std::to_string(hp) + " "
		+ std::to_string(stamina) + " "
		+ std::to_string(statPoints) + " "
		+ std::to_string(skillPoints);
}