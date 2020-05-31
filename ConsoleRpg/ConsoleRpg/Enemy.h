#pragma once

#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
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
		bool isDefending;

	public:
		Enemy(int level = 0);
		virtual ~Enemy();
		inline bool isAlive() {return this->hp > 0;}
		string getAsString()const;
		string getBattleAtributes()const;
		inline void takeDamage(int damage) {this->hp -= damage;}
		inline int getDamage()const {return rand()% this->damageMax + this->damageMin;};
		inline int getExp() const {return this->level*100;}
		inline int getHp() const {return this->hp;}		
		inline int getDefence()const {return this->defence;}
		inline bool getIsDefending()const {this->isDefending;}
		inline bool setIsDefending(bool isDefending) {this->isDefending = isDefending;}
};