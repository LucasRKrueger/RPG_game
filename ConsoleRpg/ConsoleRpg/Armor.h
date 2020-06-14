#pragma once
#include "Item.h"

class Armor : public Item
{
	public:
		Armor(int type = 0, int defence = 0, string name = "NONE",
			int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0);

		virtual ~Armor();

		string toString();
		inline int const getType() {return type;}
		virtual Armor* clone() const;

	private:
		int type;
		int defence;
		int buyValue;
};