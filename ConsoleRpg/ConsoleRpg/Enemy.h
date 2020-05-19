#pragma once

#include <stdlib.h>

class Enemy
{
	private:
		int level;
		int hp;
		int hpMax;
		int damageMin;
		int damageMax;
		float dropChance;
		int defence;
		int accuracy;

	public:
		Enemy(int level = 0);
		virtual ~Enemy();
		inline bool isAlive() {return this->hp > 0;}
};