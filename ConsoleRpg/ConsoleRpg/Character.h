#pragma once
#include "Inventory.h"
#include <vector>

class Character
{
	public:
		Character();
		virtual ~Character();
		
		void initialize(const string name);
		void printStatus() const;
		int necessaryXP(int level);
		void levelUp();
		string getAsString()const;//all of stuffs as string XD

		inline const int& getDistanceTravelled() const {return this->distanceTravelled;}
		inline const string& getName() const {return this->name;}
		inline const int& getLevel() const {return this->level;}
		inline const int& getExp() const {return this->exp;}
		inline const int& getExpNext() const {return this->expNext;}
		inline const int& getHp() const {return this->hp;}
		inline const int& getHpMax() const {return this->hpMax;}
		inline const int& getStamina() const {return this->stamina;}
		inline const int& getDamageMin() const {return this->damageMin;}
		inline const int& getDamageMax() const {return this->damageMax;}
		inline const int& getDefence() const {return this->defence;}
		inline const int& getAccuracy() const {return this->accuracy;}
		inline const int& getActiveCharacter(vector<Character> characters) const {return characters.size() - 1;}

		inline void setDistanceTravelled(const int& distance) {this->distanceTravelled = distance;}
		inline void travel() {this->distanceTravelled++;}

		inline void stealExperience() {this->exp -= this->level * 50;}
		inline void receiveExperience() {this->exp += this->level * 10;}

	private:
		int distanceTravelled;

		Inventory inventory;
		Weapon weapon;

		Armor armor_head;
		Armor armor_chest;
		Armor armor_arms;
		Armor armor_legs;
		int gold;
		
		string name;
		int level;
		int exp;
		int expNext;

		int strength;
		int vitality;
		int dexterity;
		int intelligence;

		int hp;
		int hpMax;
		int stamina;
		int staminaMax;
		int damageMin;
		int damageMax;
		int defence;
		int accuracy;
		int luck;

		int statPoints;
		int skillPoints;
};