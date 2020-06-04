#pragma once
#include "vector"
#include "Armor.h"

class Shop {
public:
	Shop();
	virtual ~Shop();
	vector<Item> getItems(int characterLevel);
	inline int getRandomItemLevel(int charLevel)const {return rand() % (charLevel+2) - charLevel;}
	inline vector<string> setItemNames() {return { "Stick","Wooden Shield","Wooden Sword","Wooden Helmet" };}
};