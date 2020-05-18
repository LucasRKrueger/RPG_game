#pragma once
#include "Item.h"

class Weapon : public Item
{
	private:
		int damageMin;
		int damageMax;

	public:
		Weapon(int damageMin = 0, int damgeMax = 0, std::string name = "NONE",
			int level = 0, int buyvalue = 0, int sellValue = 0, int rarity = 0);
		virtual ~Weapon();

		std::string toString();		
};