#pragma once
#include "Inventory.h"
#include <vector>

class Character
{
	public:
		Character();
		virtual ~Character();
		
		void initialize(const std::string name);
		void printStatus() const;
		int necessaryXP(int level);
		void levelUp();
		std::string getAsString()const;//all of stuffs as string XD

		inline const double& getX() const {return this->xPosition;}
		inline const double& getY() const {return this->yPosition;}
		inline const std::string& getName() const {return this->name;}
		inline const int& getLevel() const {return this->level;}
		inline const int& getExp() const {return this->exp;}
		inline const int& getExpNext() const {return this->expNext;}
		inline const int& getHp() const {return this->hp;}
		inline const int& getHpMax() const {return this->hpMax;}
		inline const int& getStamina() const {return this->stamina;}
		inline const int& getDamageMin() const {return this->damageMin;}
		inline const int& getDamageMax() const {return this->damageMax;}
		inline const int& getDefence() const {return this->defence;}
		inline const int& getActiveCharacter(std::vector<Character> characters) const {return characters.size() - 1;}

 
	private:
		double xPosition;
		double yPosition;

		Inventory inventory;
		Weapon weapon;

		Armor armor_head;
		Armor armor_chest;
		Armor armor_arms;
		Armor armor_legs;

		std::string name;
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
		int luck;

		int statPoints;
		int skillPoints;
};