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
	Puzzle puzzle("Puzzles/1.txt");

	while (!completed && chances > 0)
	{
		chances--;
		std::cout << puzzle.getAsString() + "\n";

		std::cout << "Your Answer: ";
		std::cin >> userAnswer;
		std::cout << "\n";

		if (puzzle.getCorrectAnswer() == userAnswer)
		{
			completed = true;
			//Give exp etc.. and continue
		}
	}

	if (completed) 
	{
		std::cout << "CONGRATS YOU SUCCEDED! \n \n";
	}
	else
	{
		std::cout << "YOU FAILED! \n \n";
	}
}