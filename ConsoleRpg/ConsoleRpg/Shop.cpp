#include "Shop.h"
Shop::Shop()
{	
}

Shop::~Shop()
{

}

vector<Item> Shop::getItems(int characterLevel)
{
	getRandomItemLevel(characterLevel);	
	vector<Item> items;
	vector<string>names = setItemNames();
	for (size_t i = 0; i < 4; i++)
	{
		//implement new items
	}
}