#include "Armor.h"

Armor::Armor(int type, int defence, string name,
	int level, int buyvalue, int sellValue, int rarity) : Item(name, level, buyvalue, sellValue, rarity)
{	
	this->type = type;
	this->defence = defence;
}

Armor::~Armor()
{

}

string Armor::toString()
{
	return to_string(this->type) + to_string(this->defence);
}

Armor* Armor::clone() const
{
	return new Armor(*this);
}