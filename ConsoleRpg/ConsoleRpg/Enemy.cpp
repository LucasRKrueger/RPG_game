#include "Enemy.h"

Enemy::Enemy(int level)
{
	this->level = level;
	this->hpMax = level * 10;
	this->hp = this->hpMax;	
	this->damageMin = this->level * 2;
	this->damageMax = this->level * 3;
	this->dropChance = rand() % 100;
	this->defence = rand() % 100;
	this->accuracy = rand() % 100;
	this->isDefending = false;
}

Enemy::~Enemy()
{

}

string Enemy::getAsString() const
{
	return  "Level: " + to_string(this->level) + "\n" +
		    "Hp: " + to_string(this->hp) + " / " + to_string(this->hpMax) + "\n" +
		    "Damage: " + to_string(this->damageMin) + " - " + to_string(this->damageMax) 
		    + "\n"  +
		    "Defence: " + to_string(this->defence) + "\n"
		    "Accuracy: " + to_string(this->accuracy) + "\n"
		    "Drop Chance: " + to_string(this->dropChance) + "\n";
}
string Enemy::getBattleAtributes() const
{
	return  "|Level: " + to_string(this->level) + "\n" +
		    "|Hp: " + to_string(this->hp) + " / " + to_string(this->hpMax) + "\n" +
		    "|Damage: " + to_string(this->damageMin) + " - " + to_string(this->damageMax) +
		    "\n" +
		    "|Defence: " + to_string(this->defence) + "\n";
}
