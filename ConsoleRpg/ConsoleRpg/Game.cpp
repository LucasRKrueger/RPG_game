#include "Game.h"

using namespace std;

Game::Game(){choice = 0;playing = true;}
Game::~Game(){}

//Functions
void Game::mainMenu()
{
	cout << "MAIN MENU" << endl << endl;
	cout << "0: Quit" << endl;
	cout << "1: Travel" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Level Up" << endl;
	cout << "4: Rest" << endl;
	cout << "5: Character sheet" << endl;

	cout << endl << "Choice: ";
	cin >> choice;

	switch (choice)
	{
		case 0:
			playing = false;
			break;
	}
}