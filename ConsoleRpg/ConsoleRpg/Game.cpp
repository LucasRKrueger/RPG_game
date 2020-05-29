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
	createNewCharacter();
}

//Functions
void Game::mainMenu()
{
	int activeCharacter = character.getActiveCharacter(characters);

	if (characters[activeCharacter].getHp() > 0)
	{
		cout << "CHARACTER NAME: " << characters[activeCharacter].getName() << endl << endl;

		levelUpAvaliable(activeCharacter);

		cout << "|       = MAIN MENU =      |" << endl;
		cout << "|==========================|" << endl;
		cout << "| 0: Quit                  |" << endl;
		cout << "| 1: Travel                |" << endl;
		cout << "| 2: Shop                  |" << endl;
		cout << "| 3: Level Up              |" << endl;
		cout << "| 4: Character sheet       |" << endl;
		cout << "| 5: Create new character  |" << endl;
		cout << "| 6: Save Character        |" << endl;
		cout << "| 7: Load Character        |" << endl;
		cout << "|==========================|" << endl;

		cout << endl;

		cout << endl << "Choice: ";
		cin >> choice;
		cout << endl;

		system("CLS");

		switch (choice)
		{
		case 0:
			playing = false;
			break;
		case 1:
			Travel();
			break;
		case 2:
			break;
		case 3:
			this->characters[activeCharacter].levelUp();
			break;
		case 4:
			characters[activeCharacter].printStatus();
			break;
		case 5:
			cin.ignore();
			createNewCharacter();
			saveCharacters();
			break;
		case 6:
			saveCharacters();
			break;
		case 7:
			loadCharacter();
			break;

		default:
			break;
		}
	}
	else
	{
		cout << "Character Recreated! \n\n";
		reCreateCharacter(characters[activeCharacter].getName());
	}
}
void Game::levelUpAvaliable(int activeCharacter)
{
	if (this->characters[activeCharacter].getExp() >= this->characters[activeCharacter].getExpNext())
	{
		cout << "LEVEL UP IS AVALIABLE! \n\n";
	}
}
void Game::reCreateCharacter(string _name)
{
	characters.push_back(Character());
	activeCharacter = character.getActiveCharacter(characters);
	characters[activeCharacter].initialize(_name);
}

void Game::createNewCharacter()
{
	string name;
	cout << "Character Name: ";
	getline(cin, name);	
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
	ifstream inFile(fileName);

	this->characters.clear();

	string name = "";
	int distanceTravelled = 0;
	int gold = 0;
	int level = 0;
	int exp = 0;
	int strength = 0;
	int vitality = 0;
	int dexterity = 0;
	int intelligence = 0;
	int hp = 0;
	int stamina = 0;
	int statusPoints = 0;
	int skillPoints = 0;

	string line = "";
	stringstream str;

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			str.str(line);
			str >> name;
			str >> distanceTravelled;
			str >> gold;
			str >> level;
			str >> exp;
			str >> strength;
			str >> vitality;
			str >> dexterity;
			str >> intelligence;
			str >> hp;
			str >> stamina;
			str >> statusPoints;
			str >> skillPoints;

			Character character(name, distanceTravelled, gold, level, exp,                                 strength, vitality, dexterity, intelligence, 
				                hp, stamina, statusPoints, skillPoints);

			this->characters.push_back(Character(character));

			cout << "Character Loaded! \n";
		}
	}
	inFile.close();

	if (this->characters.size() <= 0)
	{
		throw("No Character loaded or empty file!");
	}
}

void Game::Travel()
{
	this->characters[activeCharacter].travel();

	Event event;

	event.generateEvent(this->characters[activeCharacter]);

}