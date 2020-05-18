#include "Armor.h"

Armor::Armor(int type, int defence, std::string name,
	int level, int buyvalue, int sellValue, int rarity) : Item(name, level, buyvalue, sellValue, rarity)
{
	this->type = type;
	this->defence = defence;
}

Armor::~Armor()
{

}

std::string Armor::toString()
{
	return std::to_string(this->type) + std::to_string(this->defence);
}

Armor* Armor::clone() const
{
	return new Armor(*this);
}