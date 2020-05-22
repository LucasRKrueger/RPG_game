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

void enemyEncouter(Character& character)
{

}

void puzzleEncouter(Character& character)
{

}