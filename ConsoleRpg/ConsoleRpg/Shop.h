#pragma once
#include "vector"
#include "Weapon.h"
#include "Armor.h"
#include "Character.h"

class Shop{
public:
	Shop();
	virtual ~Shop();
	void getItems(Character character);

	inline int getRandomItemLevel(int charLevel)const {return rand() % (charLevel+2) - charLevel;}
	inline int getRandomDefence(int charLevel)const {return rand()%(charLevel+8)-charLevel;}
	inline vector<string> getArmorNames() {return { "Leather Greaves","Leather Helmet", "Leather Breastplate", "Leather Sabatons"  };}
	inline vector<string> getWeaponNames() {return { "Stick","Wooden Shield","Wooden Sword", "Stone Sword"};}

	Item& operator[](const int index);
	Shop(const Shop& obj);
	void addItem(const Item& item);
	inline void debugPrint() const
	{
		for (size_t i = 0; i < this->numberOfItems; i++)
		{
			cout << this->itemArr[i]->debugPrint(i) << endl;
		}
	}
private:
	int capacity;
	int numberOfItems;
	Item** itemArr;
	void initialize(const int from = 0);
	void expand();
};