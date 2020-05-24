#include "Weapon.h"
Weapon::Weapon(int damageMin, int damageMax, string name,
int level, int buyvalue , int sellValue , int rarity) : Item (name,level,buyvalue,sellValue,rarity)
{
	this->damageMin = damageMin;
	this->damageMax = damageMax;
}

Weapon::~Weapon()
{

}

string Weapon::toString()
{
	return to_string(this->damageMin) + " " + to_string(this->damageMax);
}

 Weapon* Weapon::clone() const
{
	 return new Weapon(*this);
}