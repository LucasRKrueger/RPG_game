#include "Weapon.h"
Weapon::Weapon(int damageMin, int damgeMax, std::string name,
int level, int buyvalue , int sellValue , int rarity)
{

}

Weapon::~Weapon()
{

}

std::string Weapon::toString()
{
	return std::to_string(this->damageMin);
}