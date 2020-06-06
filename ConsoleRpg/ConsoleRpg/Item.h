#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Item
{
	public:
		Item(string name, int level, int buyvalue , int sellValue, int rarity);

		~Item();

		inline string debugPrint() const {return "Name " + this->name + "Price " + to_string(this->buyValue);}
		virtual Item* clone() const = 0;

		inline const string& getName() const {return this->name;}
		inline const int& getLevel() const {return this->level;}
		inline const int& getBuyValue() const {return this->buyValue;}
		inline const int& getSellValue() const {return this->sellValue;}
		inline const int& getRarity() const {return this->rarity;}

	private:
		string name;
		int buyValue;
		int sellValue;
		int level;
		int rarity;
};