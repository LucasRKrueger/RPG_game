#include "Weapon.h"
Weapon::Weapon(int damageMin, int damageMax, std::string name,
int level, int buyvalue , int sellValue , int rarity) : Item (name,level,buyvalue,sellValue,rarity)
{
	this->damageMin = damageMin;
	this->damageMax = damageMax;
}

Weapon::~Weapon()
{

}

std::string Weapon::toString()
{
	return std::to_string(this->damageMin) + " " + std::to_string(this->damageMax);
}

 Weapon* Weapon::clone() const
{
	 return new Weapon(*this);
}