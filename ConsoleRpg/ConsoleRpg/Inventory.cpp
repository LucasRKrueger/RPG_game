#include "Inventory.h"

Inventory::Inventory()
{
	this->capacity = 10;
	this->numberOfItems = 0;
	this->itemArr = new Item*[capacity];
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] itemArr;
}

void Inventory::addItem(const Item& item)
{
	if (this->numberOfItems >= this->capacity)
	{
		expand();
	}
	this->itemArr[this->numberOfItems++] = new Item;
}
void Inventory::removeItem(int index)
{

}

void Inventory::initialize(const int from)
{
	for (size_t i = from; i < capacity; i++)
	{
		this->itemArr[i] = nullptr;
	}
}

void Inventory::expand()
{
	this->capacity *= 2;

	Item** tempArr = new Item * [this->capacity];

	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		tempArr[i] = new Item(*this->itemArr[i]);
	}

	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;

	this->itemArr = tempArr;

	this->initialize(this->numberOfItems);
}