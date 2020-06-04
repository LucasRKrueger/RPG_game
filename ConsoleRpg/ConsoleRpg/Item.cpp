#include "Item.h"

Item::Item(string name = "NONE",
	int level = 0, int buyvalue = 0, int sellValue = 0, int rarity = 0)
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