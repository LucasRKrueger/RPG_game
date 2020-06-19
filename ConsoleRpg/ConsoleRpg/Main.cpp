#include "Game.h"

int main()
{
	srand(time(NULL));

	Game game;
	Inventory inventory;
	game.initGame();

	while (game.getPlaying())
	{
		game.mainMenu(inventory);
	}
	return 0;
}


