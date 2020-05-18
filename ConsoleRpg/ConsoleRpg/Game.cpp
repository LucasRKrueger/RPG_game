#include "Game.h"

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
	createNewCharacter();
}

//Functions
void Game::mainMenu()
{
	cout << "= MAIN MENU =" << endl << endl;
	cout << "0: Quit" << endl;
	cout << "1: Travel" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Level Up" << endl;
	cout << "4: Rest" << endl;
	cout << "5: Character sheet" << endl;
	cout << "6: Create new character" << endl;
	cout << "7: Save Character" << endl;
	cout << "8: Load Character" << endl;

	cout << std::endl;

	cout << endl << "Choice: ";
	cin >> choice;
	std::cout << std::endl;

	switch (choice)
	{
		case 0:
			playing = false;
			break;
		case 5:
			characters[activeCharacter].printStatus();
			break;
		case 6:
			createNewCharacter();
			saveCharacters();
			break;
		case 8:
			loadCharacter();
			break;
	}
}
void Game::createNewCharacter()
{
	string name;
	cout << "Character Name: ";
	getline(std::cin, name);
	cin.ignore();

	activeCharacter = character.getActiveCharacter(characters);
	characters[activeCharacter].initialize(name);
}

void Game::saveCharacters()
{

}

void Game::loadCharacter()
{

}