/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>




//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Create window and shiet
bool init();

//Load media
bool loadMedia();

//FREEEEEEEEE
void close();


//globals
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

int main(int argc, char* args[])
{
	if (init())
	{
		loadMedia();
		gScreenSurface = SDL_GetWindowSurface(gWindow);
		//Fill the surface white
		SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0xFF, 0xFF, 0xFF));

		//Update the surface
		SDL_UpdateWindowSurface(gWindow);

		//Wait two seconds
		SDL_Delay(2000);
	}

	close();


	return 0;
}


bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize SDL_Error:%s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//create video
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	gHelloWorld = SDL_LoadBMP("Assets/hello.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "Assets/hello.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void close()
{
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}