/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "LTexture.h"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//Create window and shiet
bool init();
//Load media
bool loadMedia();
//FREEEEEEEEE
void close();
SDL_Surface* loadSurface(std::string path);
SDL_Texture* loadTexture(std::string path);



SDL_Surface* gCurrentSurface = NULL;

//globals
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer = NULL;

SDL_Rect gSpriteClips[4];
LTexture* gSpriteSheetTexture;

int main(int argc, char* args[])
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{

		gScreenSurface = SDL_GetWindowSurface(gWindow);
		SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0xAA, 0xAA, 0xAA));
		if (!loadMedia())
		{
			printf("Failed to load media!\n");

		}
		else
		{

			bool quit = false;
			SDL_Event e;

			//stretch stuff
			/*SDL_Rect stretchRect;
			stretchRect.x = 0;
			stretchRect.y = 0;
			stretchRect.w = gPNGSurface->w;
			stretchRect.h = gPNGSurface->h;*/

			while (!quit)
			{

				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT) //quit request, che e` tipo er click sulla X 
					{
						quit = true;
					}
					//User presses a key
					else if (e.type == SDL_KEYDOWN)
					{
						//Select surfaces based on key press
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:

							break;

						case SDLK_DOWN:

							break;

						case SDLK_LEFT:

							break;

						case SDLK_RIGHT:

							break;

						default:

							break;
						}
					}
				}

				SDL_RenderClear(gRenderer);

				//gBackgroundTexture->render(0, 0);
				//gFooTexture->render(240, 190);
				gSpriteSheetTexture->setColor(0xFF, 0xFF, 0xFF);
				gSpriteSheetTexture->render(0, 0, &gSpriteClips[0]);
				gSpriteSheetTexture->setColor(0xFF, 0, 0);
				gSpriteSheetTexture->render(SCREEN_WIDTH-gSpriteClips[1].w, 0, &gSpriteClips[1]);
				gSpriteSheetTexture->setColor(0, 0xFF, 0);
				gSpriteSheetTexture->render(0, SCREEN_HEIGHT- gSpriteClips[2].h, &gSpriteClips[2]);
				gSpriteSheetTexture->setColor(0, 0, 0xFF);
				gSpriteSheetTexture->render(SCREEN_WIDTH - gSpriteClips[3].w, SCREEN_HEIGHT - gSpriteClips[3].h, &gSpriteClips[3]);

				SDL_RenderPresent(gRenderer);


				//SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
				//Update the surface
				//SDL_UpdateWindowSurface(gWindow);
			}
		}

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
		gWindow = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{

				//init Render Color
				SDL_SetRenderDrawColor(gRenderer, 0x8A, 0x8A, 0x8A, 0xFF);

				int imgFlags = IMG_INIT_PNG;// init png support
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				else
				{
					gScreenSurface = SDL_GetWindowSurface(gWindow);
					gSpriteSheetTexture = new LTexture();
				}
			}

		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	//Load default surface
	/*gPNGSurface = loadSurface("Assets/Guy.PNG");
	if (gPNGSurface == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}*/

	if (!gSpriteSheetTexture->loadFrom("Assets/Tikki.png", gRenderer))
	{
		printf("Failed to load Tikki' texture image!\n");
		success = false;
	}
	else
	{
		//TL
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 80;
		gSpriteClips[0].h = 80;
		//TR
		gSpriteClips[1].x = 80;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 80;
		gSpriteClips[1].h = 80;

		//BL
		gSpriteClips[2].x = 0;
		gSpriteClips[2].y = 80;
		gSpriteClips[2].w = 80;
		gSpriteClips[2].h = 80;
		//BR
		gSpriteClips[3].x = 80;
		gSpriteClips[3].y = 80;
		gSpriteClips[3].w = 80;
		gSpriteClips[3].h = 80;
	}



	return success;
}

void close()
{
	SDL_FreeSurface(gCurrentSurface);
	gCurrentSurface = NULL;

	//free texture
	gSpriteSheetTexture->free();
	//gBackgroundTexture->free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	//SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	//if (loadedSurface == NULL)
	//{
	//	printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	//}
	//return loadedSurface;
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else
	{
		//convert surface to screenFormat
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		/*
		when you load a bitmap, it's typically loaded in a 24bit format since most bitmaps are 24bit.
		Most, if not all, modern displays are not 24bit by default.
		If we blit an image that's 24bit onto a 32bit image, SDL will convert it every single time the image is blitted.
		*/
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}


	return optimizedSurface;
}

//SDL_Texture* loadTexture(std::string path)
//{
//	SDL_Texture* newTexture = NULL;
//
//	//Load Image
//	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//	if (loadedSurface == NULL)
//	{
//		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
//	}
//	else
//	{
//		//create texture from surface 
//		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
//		if (newTexture == NULL)
//		{
//			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//		}
//
//		SDL_FreeSurface(loadedSurface);
//	}
//	return newTexture;
//}