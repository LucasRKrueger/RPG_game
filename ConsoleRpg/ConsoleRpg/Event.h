#pragma once
#include <stdlib.h>
#include "Puzzle.h"
#include "Enemy.h"
#include "Character.h"
class Event
{
public:
	Event();
	virtual ~Event();
	void generateEvent(Character& character);
	void enemyEncouter(Character& character);
	void puzzleEncouter(Character& character);
private:
	int numberOfEvents;
};