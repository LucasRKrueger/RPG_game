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
	int position = 0;
	bool isFighting = true;
	for (size_t i = characterLevel; i > 10; i -= 10)
	{
		Enemy enemy(rand() % characterLevel + 5);
		enemies[position] = enemy;
		position++;
	}
	//CREATE A COMBAT METHOD	
	while (isFighting)
	{
		ShowAttributes(enemies, character);

		EnemyTurn(enemies, character);

		//CHARACTER TURN

		isFighting = character.characterDoesntHasHp() || AllEnemiesDontHaveHp(enemies);
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

bool Event::AllEnemiesDontHaveHp(vector<Enemy> enemies)
{
	int enemiesWithHp = 0;
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemiesWithHp = enemies[i].getHp() > 0 ? enemiesWithHp + 1 : enemiesWithHp;
	}
	return enemiesWithHp == 0;
}

vector<int> Event::EnemyAction(vector<Enemy> enemies)
{	
	vector<int> actions;

	for (size_t i = 0; i < enemies.size(); i++)
	{
		actions[i] = rand() % 2;
	}
	return actions;
}

void Event::EnemyTurn(std::vector<Enemy>& enemies, Character& character)
{
	vector<int> actions = EnemyAction(enemies);
	for (size_t i = 0; i < actions.size(); i++)
	{
		if (actions[i] == 1)
		{
			character.takeDamage(enemies[i].getDamage());
		}
	}
}

void Event::ShowAttributes(std::vector<Enemy>& enemies, Character& character)
{
	cout << "ENEMIES \n\n" << endl;

	for (size_t i = 0; i < enemies.size(); i++)
	{
		cout << enemies[i].getBattleAtributes();
	}
	cout << "\n\n";


	cout << "YOU \n\n" << character.getBattleAtributes();
}