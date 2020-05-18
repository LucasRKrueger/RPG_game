#pragma once
#include "Item.h"

class Armor : public Item
{
	public:
		int type;
		int defence;

	private:
		Armor(int type = 0, int defence = 0, std::string name = "NONE",
			int level = 0, int buyvalue = 0, int sellValue = 0, int rarity = 0);

		virtual ~Armor();

		std::string toString();

		virtual Armor* clone() const;
};