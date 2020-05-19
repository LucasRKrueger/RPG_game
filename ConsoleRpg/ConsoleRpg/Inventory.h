#pragma once

#include "Weapon.h"
#include "Armor.h"
class Inventory
{
	public:
		Inventory();
		~Inventory();

		inline int size() const {return this->numberOfItems;}
		Item& operator[](const int index);
		Inventory(const Inventory& obj);
		void addItem(const Item &item);
		void removeItem(int index);
		inline void debugPrint() const
		{
			for (size_t i = 0; i < this->numberOfItems; i++)
			{
				std::cout << this->itemArr[i]->debugPrint() << std::endl;
			}
		}

	private:
		int capacity;
		int numberOfItems;
		Item **itemArr;
		void initialize(const int from = 0);
		void expand();
};