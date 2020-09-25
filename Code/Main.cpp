/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

#include "Game.h"



int main(int argc, char* args[])
{
	Game* newGame = new Game(640, 480, "Best Game Ever");
	
	if (!newGame->Init())
	{
		printf("Failed to initialize!\n");

	}
	else
	{
		if (!newGame->LoadMedia())
		{
			printf("Failed to load media!\n");

		}
		else
		{
			newGame->Loop();
		}
	}
	newGame->End();
	return 0;

	
}

