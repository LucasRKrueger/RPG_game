#include "Event.h"

Event::Event()
{
	this->numberOfEvents = 2;
}

Event::~Event()
{

}

void Event::generateEvent(Character& character)
{
	int i = rand() % this->numberOfEvents;
	i = 0;

	switch (i)
	{
	case 0:
		enemyEncouter(character);
		break;
	case 1:
		puzzleEncouter(character);
		break;
	case 2:
		break;
	default:
		break;
	}
}

void Event::enemyEncouter(Character& character)
{
	vector<Enemy> enemies;

	int characterLevel = character.getLevel();

	GetEnemies(characterLevel, enemies);

	StartFight(enemies, character);
}



void Event::StartFight(vector<Enemy>& enemies, Character& character)
{
	bool isFighting = true;

	while (isFighting)
	{
		ShowAttributes(enemies, character);

		EnemyTurn(enemies, character);
		if (character.characterDoesntHasHp())
		{
			system("CLS");
			cout << "\nYOU ARE DEAD!\n" << endl;
			isFighting = false;
			continue;
		}
		system("CLS");

		ShowAttributes(enemies, character);

		CharacterTurn(enemies, character);
		
		isFighting = AllEnemiesDontHaveHp(enemies);

		system("CLS");
	}
}

void Event::puzzleEncouter(Character& character)
{
	bool completed = false;
	int userAnswer = 0;
	int chances = 1;
	int randN = 0;

	for (size_t i = 1; i < 10; i++)
	{
		//IMPLEMENT MORE PUZZLES
		randN = rand() % 10;
		Puzzle puzzle("Puzzles/" + to_string(randN) + ".txt");

		while (!completed && chances > 0)
		{
			chances--;

			cin >> userAnswer;
			cout << puzzle.getAsString() + "\n";
			cout << "Your Answer: ";
			cout << "\n";

			completed = puzzle.getCorrectAnswer() == userAnswer;
		}

		if (completed)
		{
			character.receiveExperience();
			cout << "CONGRATS YOU SUCCEDED! You're now with " << character.getExp() << "XP!\n \n";
		}
		else
		{
			//IMPLEMENT WHEN XP BECOMES LESS THAN 0 AND LEVEL BIGGER THAN 1
			character.stealExperience();
			cout << "YOU FAILED! XP STEALED!\n \n";
		}
	}
}

bool Event::AllEnemiesDontHaveHp(vector<Enemy>& enemies)
{
	int enemiesWithHp = 0;
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemiesWithHp = enemies[i].getHp() > 0 ? enemiesWithHp + 1 : enemiesWithHp;
	}
	return enemiesWithHp == 0;
}

vector<int> Event::EnemyAction(vector<Enemy>& enemies)
{	
	vector<int> actions;

	for (size_t i = 0; i < enemies.size(); i++)
	{
		actions.push_back(i);
		actions[i] = rand() % 2;
	}
	return actions;
}

void Event::CharacterTurn(std::vector<Enemy>& enemies, Character& character)
{
	int enemy;
	int action;	

	cout << "Select 1 to punch and 2 to defend" << endl;
	cin >> action;

	if (action == 1)
	{
		cout << "Which enemy do you want to punch: " << endl;
	}
	cin >> enemy;

	int characterDamage = character.getDamage();

	cout << "Enemy " << enemy << "taked " << characterDamage << " damage!" << endl;
	enemies[enemy-1].takeDamage(characterDamage);
}

void Event::EnemyTurn(std::vector<Enemy>& enemies, Character& character)
{
	vector<int> actions = EnemyAction(enemies);
	for (size_t i = 0; i < actions.size(); i++)
	{
		if (actions[i] == 1)
		{
			cout << "You taked" << enemies[i].getDamage() << " Damage!" << endl;
			character.takeDamage(enemies[i].getDamage());
		}
	}
}

void Event::ShowAttributes(vector<Enemy>& enemies, Character& character)
{
	system("CLS");
	cout << "ENEMIES \n\n" << endl;

	for (size_t i = 0; i < enemies.size(); i++)
	{
		cout << "Enemy " << i + 1 << endl;
		cout << enemies[i].getBattleAtributes() << "\n";		
	}
	cout << "\n\n";


	cout << "YOU \n\n" << character.getBattleAtributes();
}

void Event::GetEnemies(int characterLevel, std::vector<Enemy>& enemies)
{
	int position = 0;
	for (size_t i = characterLevel; i > 2; i -= 2)
	{
		Enemy enemy(rand() % characterLevel + 5);
		enemies.push_back(position);
		enemies[position] = enemy;
		position++;
	}	
}