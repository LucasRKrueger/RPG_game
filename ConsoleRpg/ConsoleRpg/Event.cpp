#include "Event.h"

Event::Event()
{
	this->numberOfEvents = 2;
}

Event::~Event()
{

}

void Event::generateEvent(Character &character)
{
	int i = rand()% this->numberOfEvents;

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
	while (true)
	{

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
		Puzzle puzzle("Puzzles/" + std::to_string(randN) + ".txt");

		while (!completed && chances > 0)
		{
			chances--;
			std::cout << puzzle.getAsString() + "\n";

			std::cout << "Your Answer: ";
			std::cin >> userAnswer;
			std::cout << "\n";

			completed = puzzle.getCorrectAnswer() == userAnswer;
		}

		if (completed)
		{
			//receive random item
			character.receiveExperience();
			std::cout << "CONGRATS YOU SUCCEDED! \n \n";
		}
		else
		{
			//IMPLEMENT WHEN XP BECOMES LESS THAN 0 AND LEVEL BIGGER THAN 1
			character.stealExperience();
			std::cout << "YOU FAILED! XP STEALED!\n \n";			
		}
	}
}