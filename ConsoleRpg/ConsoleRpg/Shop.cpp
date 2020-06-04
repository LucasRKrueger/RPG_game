#include "Shop.h"
Shop::Shop()
{	
	this->capacity = 5;
	this->numberOfItems = 0;
	this->itemArr = new Item * [capacity];
	this->initialize();
}

Shop::~Shop()
{
	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] itemArr;
}

vector<Item> Shop::getItems(int characterLevel)
{
	getRandomItemLevel(characterLevel);	
	vector<Item> items;
	vector<string>names = setItemNames();
	for (size_t i = 0; i < 4; i++)
	{
		items[i] = new Item(names[i], 1, 1, 1, 1);
	}
}

Shop::Shop(const Shop& obj)
{
	this->capacity = obj.capacity;
	this->numberOfItems = obj.numberOfItems;
	this->itemArr = new Item * [this->capacity];

	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	initialize(numberOfItems);
}

void Shop::addItem(const Item& item)
{
	if (this->numberOfItems >= this->capacity)
	{
		expand();
	}
	this->itemArr[this->numberOfItems++] = item.clone();
}

void Shop::initialize(const int from)
{
	for (size_t i = from; i < capacity; i++)
	{
		this->itemArr[i] = nullptr;
	}
}

void Shop::expand()
{
	this->capacity *= 2;

	Item** tempArr = new Item * [this->capacity];

	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		tempArr[i] = this->itemArr[i];
	}

	delete[] this->itemArr;

	this->itemArr = tempArr;

	this->initialize(this->numberOfItems);
}

Item& Shop::operator[](const int index)
{
	if (index < 0 || index >= this->numberOfItems)
		throw("BAD INDEX");
	return *this->itemArr[index];
}