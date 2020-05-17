#pragma once

#include "Item.h"

class Inventory
{
	public:
		Inventory();
		~Inventory();
		void addItem(const Item &item);
		void removeItem(int index);

	private:
		int capacity;
		int numberOfItems;
		Item** itemArr;
		void initialize(const int from);
		void expand();

};