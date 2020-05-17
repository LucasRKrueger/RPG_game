#include "Game.h"

int main()
{
	srand(time(NULL));

	Game game;
	game.initGame();

	Inventory inventory;
	//MOCK TEST
	inventory.addItem(Item());
	inventory.addItem(Item());
	inventory.addItem(Item());
	inventory.addItem(Item());
	inventory.addItem(Item());
	inventory.debugPrint();


	while (game.getPlaying())
	{
		game.mainMenu();
	}
	return 0;
}


