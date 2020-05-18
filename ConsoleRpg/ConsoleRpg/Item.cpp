#include "Item.h"

Item::Item(int damageMin, int damgeMax, std::string name,
	int level, int buyvalue, int sellValue, int rarity)
{
	this->name = "NONE";
	this->level = level
	this->buyValue = 0;
	this->sellValue = 0;
	this->rarity = rarity
}

Item::~Item()
{

}