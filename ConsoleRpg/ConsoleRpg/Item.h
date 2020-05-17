#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Item
{
	public:
		Item();
		virtual ~Item();
		inline std::string debugPrint() const {return this->name;}

	private:
		std::string name;
		int buyValue;
		int sellValue;


};