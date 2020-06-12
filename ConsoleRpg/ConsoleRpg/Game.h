#pragma once

#include "Functions.h"
#include "Event.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <sstream>
#include "Shop.h"

class Game
{
	public:
		Game();
		virtual ~Game();	
		void initGame();
		void mainMenu();
		void levelUpAvaliable(int activeCharacter);
		void createNewCharacter();
		void reCreateCharacter(string name);
		void saveCharacters();
		void loadCharacter();
		void Travel();
		void goToShop(Character character);

		inline bool getPlaying() const {return this->playing;}
	private:
		int choice;
		bool playing;
		int activeCharacter;
		Character character;
		vector<Character> characters;
		string fileName;
};