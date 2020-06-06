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

	StartBattle(enemies, character);
}

void Event::StartBattle(vector<Enemy>& enemies, Character& character)
{
	bool isFighting = true;
	cout << "THE BATTLE IS ABOUT TO BEGIN\n";
	while (isFighting)
	{
		ShowAttributes(enemies, character);

		system("pause");

		EnemyTurn(enemies, character);

		if (character.characterDoesntHasHp())
		{
			system("CLS");

			cout << "YOU ARE DEAD!\n" << endl;

			isFighting = false;

			continue;
		}

		system("CLS");

		ShowAttributes(enemies, character);

		CharacterTurn(enemies, character);

		isFighting = AllEnemiesWithoutHp(enemies);

		if (!isFighting)
		{
			if (enemies.size() > 1)
			{
				cout << "YOU DEFEATED ALL THE ENEMIES!";
			}
			character.receiveExperience(enemies.size());
			cout << "You're now with " << character.getExp() << "XP!" << endl;
			system("pause");
		}

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

bool Event::AllEnemiesWithoutHp(vector<Enemy>& enemies)
{
	int enemiesWithoutHp = 0;
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].getHp() <= 0)
		{
			enemiesWithoutHp += 1;
			cout << "YOU DEFEATED THE ENEMY " << i + 1 << "\n\n" << endl;
		}
	}
	return enemiesWithoutHp == 0;
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

void Event::GetEnemies(int characterLevel, std::vector<Enemy>& enemies)
{
	int position = 0;

	if (characterLevel == 1) {
		Enemy enemy(rand() % characterLevel + 1);
		enemies.push_back(position);
		enemies[position] = enemy;
		position++;
	}
	else
	{
		for (size_t i = characterLevel; i > 2; i -= 2)
		{
			Enemy enemy(rand() % characterLevel + 5);
			enemies.push_back(position);
			enemies[position] = enemy;
			position++;
		}
	}
}

void Event::CharacterTurn(std::vector<Enemy>& enemies, Character& character)
{
	int enemy;
	int action;

	cout << "Select 1 to punch and 2 to defend" << endl;
	cin >> action;

	if (action == 1 && enemies.size() > 1)
	{
		cout << "Which enemy do you want to punch: " << endl;
		cin >> enemy;
	}
	else if (action != 1)
	{
		character.setIsDefending(true);
		for (size_t i = 1; i < enemies.size(); i++)
		{
			enemies[i].setIsDefending(false);
		}
	}
	else
	{
		enemy = 1;
	}

	int characterDamage = character.getDamage();

	system("CLS");

	if (action == 1)
	{
		if (enemies[enemy-1].getIsDefending())
		{
			cout << "ENEMY IS DEFENDING\n" << endl;

			CharacterDamage(characterDamage, enemies, enemy);

			enemies[enemy - 1].takeDamage(characterDamage);

			cout << "Enemy " << enemy << " taked " << characterDamage << " damage!\n" << endl;

			enemies[enemy - 1].setIsDefending(false);
		}
		else
		{
			enemies[enemy - 1].takeDamage(characterDamage);

			cout << "Enemy " << enemy << " taked " << characterDamage << " damage!\n" << endl;
		}
	}
	system("pause");
}

void Event::CharacterDamage(int& characterDamage, std::vector<Enemy>& enemies, int enemy)
{
	bool damageIsGreaterThanZero = characterDamage - (enemies[enemy - 1].getDefence() / 2) > 0;
	characterDamage -= enemies[enemy - 1].getDefence() / 2;
	characterDamage = damageIsGreaterThanZero ? characterDamage : 0;
}

void Event::EnemyTurn(std::vector<Enemy>& enemies, Character& character)
{
	vector<int> actions = EnemyAction(enemies);
	int enemyDamage;

	for (size_t i = 0; i < actions.size(); i++)
	{
		if (actions[i] == 1)
		{
			enemyDamage = enemies[i].getDamage();	

			system("CLS");

			if (character.getIsDefending())
			{
				cout << "YOU ARE DEFENDING\n" << endl;

				EnemyDamage(enemyDamage, character);

				character.takeDamage(enemyDamage);

				cout << "You taked " << enemyDamage << " Damage!\n" << endl;

				character.setIsDefending(false);
			}
			else
			{
				character.takeDamage(enemyDamage);

				cout << "You taked " << enemyDamage << " Damage!\n" << endl;
			}
			system("pause");
		}
		else
		{
			enemies[i].setIsDefending(true);
			character.setIsDefending(false);
		}
	}
}

void Event::EnemyDamage(int& enemyDamage, Character& character)
{
	bool damageIsGreaterThanZero = enemyDamage - (character.getDefence() / 2) > 0;

	enemyDamage -= character.getDefence() / 2;
	enemyDamage = damageIsGreaterThanZero ? enemyDamage : 0;
}

void Event::ShowAttributes(vector<Enemy>& enemies, Character& character)
{
	system("CLS");
	cout << "ENEMIES \n " << endl;

	for (size_t i = 0; i < enemies.size(); i++)
	{
		cout << "Enemy " << i + 1 << endl;
		cout << enemies[i].getBattleAtributes() << "\n";
	}
	cout << "\n\n";

	cout << "YOU \n\n" << character.getBattleAtributes() << "\n";
}