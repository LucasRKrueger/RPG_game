#pragma once
#include <string>
class Character
{
	public:
		Character();
		virtual ~Character();

	private:
		double xPosition;
		double yPosition;

		std::string name;
		int level;
		int exp;
		int expNext;
		int hp;
		int hpMax;
		int stamina;
		int damageMin;
		int damageMax;
		int defence;
};