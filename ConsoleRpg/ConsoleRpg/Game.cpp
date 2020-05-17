#include "Game.h"

using namespace std;

Game::Game()
{
	choice = 0;
	playing = true;
}
Game::~Game(){}

void Game::initGame()
{
	string name;
	cout << "Enter name for character: ";
	getline(std::cin, name);

	character.initialize(name);
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
			character.printStatus();
			break;
	}
}