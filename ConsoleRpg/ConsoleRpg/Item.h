#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Item
{
	public:
		Item(std::string name = "NONE", int level = 0, int buyvalue = 0, int sellValue = 0, int rarity = 0);

		virtual ~Item();

		inline std::string debugPrint() const {return this->name;}
		virtual Item* clone() const = 0;

		inline const std::string& getName() const {return this->name;}
		inline const int& getLevel() const {return this->level;}
		inline const int& getBuyValue() const {return this->buyValue;}
		inline const int& getSellValue() const {return this->sellValue;}
		inline const int& getRarity() const {return this->rarity;}

	private:
		std::string name;
		int buyValue;
		int sellValue;
		int level;
		int rarity;
};