#include "Weapon.h"
Weapon::Weapon(int type,int damageMin, int damageMax, string name,
int level, int buyValue , int sellValue , int rarity) : Item (name,level,buyValue,sellValue,rarity)
{
	this->type = type;
	this->damageMin = damageMin;
	this->damageMax = damageMax;
	this->buyValue = buyValue;
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