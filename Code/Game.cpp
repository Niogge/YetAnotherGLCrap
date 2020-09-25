#include "Game.h"

Game::Game(int W, int H, std::string Name)
{
	SCREEN_WIDTH = W;
	SCREEN_HEIGHT = H;
	WindowName = Name;

	Window = NULL;
	ScreenSurface = NULL;
	Renderer= NULL;
}

Game::~Game()
{
	End();
}

void Game::Loop()
{
	bool quit = false;
	SDL_Event e;

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
				case SDLK_p:
					charTexture->PlayAnimation();
					break;

				case SDLK_s:
					charTexture->StopAnimation();
					break;

				case SDLK_LEFT:
					charTexture->SwitchAnimation();
					break;

				case SDLK_RIGHT:

					break;

				default:

					break;
				}
			}
		}

		SDL_RenderClear(Renderer);

		charTexture->render(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);


		SDL_RenderPresent(Renderer);

		SDL_Delay(200);
	}
}

bool Game::Init()
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
		Window = SDL_CreateWindow(WindowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (Window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
			if (Renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{

				//init Render Color
				SDL_SetRenderDrawColor(Renderer, 0x8A, 0x8A, 0x8A, 0xFF);

				int imgFlags = IMG_INIT_PNG;// init png support
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				else
				{


					ScreenSurface = SDL_GetWindowSurface(Window);


					charTexture = new LTexture();
				}
			}

		}
	}

	return success;
}

bool Game::LoadMedia()
{

	ScreenSurface = SDL_GetWindowSurface(Window);
	SDL_FillRect(ScreenSurface, NULL, SDL_MapRGB(ScreenSurface->format, 0xAA, 0xAA, 0xAA));

	bool success = true;

	//Load default surface
	/*gPNGSurface = loadSurface("Assets/Guy.PNG");
	if (gPNGSurface == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}*/

	if (!charTexture->loadFrom("Assets/Tikki.png", Renderer))
	{
		printf("Failed to load Tikki' texture image!\n");
		success = false;
	}
	else
	{
		charTexture->setBlendMode(SDL_BLENDMODE_BLEND);
		charTexture->setTile(80, 80);
		charTexture->AddAnimation(0, 1, 3, 1);
		charTexture->AddAnimation(0, 2, 4, 2);

	}
	return success;
}

void Game::End()
{
	SDL_FreeSurface(ScreenSurface);
	ScreenSurface = NULL;

	//free texture
	charTexture->free();
	//gBackgroundTexture->free();

	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	Window = NULL;
	Renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
