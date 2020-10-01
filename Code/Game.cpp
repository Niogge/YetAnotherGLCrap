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
					charGO->PlayAnimation();
					break;

				case SDLK_s:
					charGO->StopAnimation();
					break;

				case SDLK_LEFT:
					charGO->Move(Vector2(-1, 0)*50.*Time::GetDeltaTime());
					break;

				case SDLK_RIGHT:

					charGO->Move(Vector2(1, 0) * 50. * Time::GetDeltaTime());
					break;

				case SDLK_0:
					charGO->SwitchAnimation();

					break;
				default:

					break;
				}
			}
		}

		SDL_RenderClear(Renderer);

		Time::Tick();


		UpdateMgr::Update();
		DrawMgr::Draw();


		SDL_RenderPresent(Renderer);

		SDL_Delay(16);
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
				UpdateMgr::Init();
				DrawMgr::Init();
				Time::Init();

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


					charGO = new GameObject();
					charGO->Init(Renderer);
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
	
	if (!charGO->LoadTexture("Assets/Tikki.png",80,80))
	{
		printf("Failed to load Tikki' texture image!\n");
		success = false;
	}
	else
	{


		charGO->AddAnimation(0, 1, 3, 1,4);
		charGO->AddAnimation(0, 2, 4, 2,4);
	

	}
	return success;
}

void Game::End()
{
	SDL_FreeSurface(ScreenSurface);
	ScreenSurface = NULL;

	//free texture
	charGO->Destroy();
	//gBackgroundTexture->free();

	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	Window = NULL;
	Renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
