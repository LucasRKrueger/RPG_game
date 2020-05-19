#include "Item.h"

Item::Item(std::string name,
	int level, int buyvalue, int sellValue, int rarity)
{
	this->name = name;
	this->level = level;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
	this->rarity = rarity;
}

Item::~Item()
{

}