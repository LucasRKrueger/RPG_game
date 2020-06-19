#include "Shop.h"
#include "Inventory.h"
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

void Shop::getItems(Character character, Inventory& _inventory)
{	
	int characterLevel = character.getLevel();

	vector<string> armorNames = getArmorNames();
	vector<string> weaponNames = getWeaponNames();

	int buyValue = characterLevel * 10;
	int sellValue = buyValue / 2;

	for (size_t i = 0; i < 4; i++)
	{
		addItem(Weapon(1, getRandomDefence(characterLevel), armorNames[i], getRandomItemLevel(characterLevel), buyValue, sellValue, 1));
		addItem(Armor(2, getRandomDefence(characterLevel), weaponNames[i], getRandomItemLevel(characterLevel), buyValue, sellValue, 1));
	}

	debugPrint();
	int itemIndex;

	cout << "Choose an item that you want to buy: ";
	cin >> itemIndex;

	Item* itemObj = itemArr[itemIndex - 1];
	
	if (character.hasGoldToBuy(itemObj->getBuyValue()))
	{	
		string name = itemObj->getName();
		int level = itemObj->getLevel();
		int buyValue = itemObj->getBuyValue();
		int sellValue = itemObj->getSellValue();
		int rarity = itemObj->getRarity();

		if (name.find("ARMOR"))
		{
			int defence = level * 3;

			int type = level < 50 ? 1 : 2;

			_inventory.addItem(Armor(type, defence, name, level, buyValue, sellValue, rarity));
		}
		else
		{
			int damageMin = level * 2;

			int damageMax = level * 4;

			_inventory.addItem(Weapon(damageMin, damageMax,name,level,buyValue, sellValue, rarity));
		}
		system("cls");
		cout << "You now have " << name << "!!" << endl;
		system("pause");
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