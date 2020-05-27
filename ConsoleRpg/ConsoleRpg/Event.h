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
	void EnemyTurn(std::vector<Enemy>& enemies, Character& character);
	void ShowAttributes(std::vector<Enemy>& enemies, Character& character);
	void puzzleEncouter(Character& character);
	void Fighting(Character& character, Enemy& enemy);
	bool AllEnemiesDontHaveHp(vector<Enemy> enemies);
	vector<int>EnemyAction(vector<Enemy> enemies);
private:
	int numberOfEvents;
};