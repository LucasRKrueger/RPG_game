#include "Game.h"
#include "stdlib.h"
using namespace std;

Game::Game()
{
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "character.txt";
}
Game::~Game(){}

void Game::initGame()
{
	Inventory inventory;
	//inventory.addItem(Weapon(2, 4, "stick\n", 1, 3, 1, 1));
	//inventory.addItem(Weapon(2, 4, "stick2\n", 1, 3, 1, 1));
	//inventory.addItem(Weapon(4, 6, "wooden sword\n", 1, 3, 1, 1));
	//inventory.addItem(Armor(1, 2, "Helmet\n", 1, 3, 1, 1));
	//inventory.addItem(Armor(2, 2, "Grevas\n", 1, 3, 1, 1));

	for (size_t i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i].debugPrint() << endl;
	}

	createNewCharacter();
}

//Functions
void Game::mainMenu()
{
	int activeCharacter = character.getActiveCharacter(characters);
	cout << "CHARACTER NAME: " << characters[activeCharacter].getName() << endl << endl;

	cout << "| = MAIN MENU =            |" << endl;
	cout << "|==========================|" << endl;
	cout << "| 0: Quit                  |" << endl;
	cout << "| 1: Travel                |" << endl;
	cout << "| 2: Shop                  |" << endl;
	cout << "| 3: Level Up              |" << endl;
	cout << "| 4: Rest                  |" << endl;
	cout << "| 5: Character sheet       |" << endl;
	cout << "| 6: Create new character  |" << endl;
	cout << "| 7: Save Character        |" << endl;
	cout << "| 8: Load Character        |" << endl;
	cout << "|==========================|" << endl;

	cout << std::endl;

	cout << endl << "Choice: ";
	cin >> choice;
	std::cout << std::endl;

	system("CLS");

	switch (choice)
	{
		case 0:
			playing = false;
			break;
		case 5:
			characters[activeCharacter].printStatus();
			break;
		case 6:
			cin.ignore();
			createNewCharacter();
			saveCharacters();
			break;
		case 7:
			saveCharacters();
			break;
		case 8:
			loadCharacter();
			break;

		default:
			break;
	}
}
void Game::createNewCharacter()
{
	string name;
	cout << "Character Name: ";
	getline(std::cin, name);
	characters.push_back(Character());
	activeCharacter = character.getActiveCharacter(characters);
	characters[activeCharacter].initialize(name);
	system("CLS");
}

void Game::saveCharacters()
{
	ofstream outFile(fileName);
	if (outFile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].getAsString() << "\n";
		}
	}
	outFile.close();
}

void Game::loadCharacter()
{

}