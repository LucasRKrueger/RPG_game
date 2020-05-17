#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Item
{
	public:
		Item();
		virtual ~Item();
	private:
		std::string name;
		int buyValue;
		int sellValue;


};