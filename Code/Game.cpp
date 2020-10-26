#include "Game.h"



Game::Game(int W, int H, std::string Name)
{
	SCREEN_WIDTH = W;
	SCREEN_HEIGHT = H;
	WindowName = Name;

	Window = NULL;
	ScreenSurface = NULL;
	Renderer = NULL;

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

		SDL_RenderClear(Renderer);

		Time::Tick();

		InputMgr::Update(&quit);
		if (InputMgr::GetKey(SDL_SCANCODE_P))
		{
			SceneMgr::SetScene(1);
		}
		if (InputMgr::GetKey(SDL_SCANCODE_Q))
		{

			SceneMgr::SetScene(0);
		}
		SceneMgr::UpdateScene();
		UpdateMgr::Update();
		PhysicsMgr::UpdatePhysics();

		DrawMgr::Draw();

		//SDL_Rect outlineRect = { charGO->transform->position.x-10, charGO->transform->position.y-10, 20,20 };
		//SDL_SetRenderDrawColor(Renderer, 0x00, 0xFF, 0x00, 0xFF);
		//SDL_RenderDrawRect(Renderer, &outlineRect);
		//SDL_SetRenderDrawColor(Renderer, 0x8A, 0x8A, 0x8A, 0xFF);


		SDL_RenderPresent(Renderer);

		SDL_Delay(16);
	}
}

bool Game::Init()
{
	bool success = true;
	// The basic logic is:
	// assign the result of a function to a pointer
	// check if the pointer is null
	// if true: Error
	// if false: Go on.


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
				//Remember? friend class! :D 
				UpdateMgr::Init();
				GFXMgr::Init(Renderer);
				SceneMgr::Init(this);
				DrawMgr::Init();
				PhysicsMgr::Init();
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
					TestSceneOne* one =new  TestSceneOne();
					TestSceneTwo* two = new  TestSceneTwo();
					SceneMgr::Register(one);
					SceneMgr::Register(two);
					SceneMgr::SetScene(1);

				
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

	
	return success;
}

void Game::End()
{
	SDL_FreeSurface(ScreenSurface);
	ScreenSurface = NULL;

	//free texture
	
	//gBackgroundTexture->free();

	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	Window = NULL;
	Renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

SDL_Renderer* Game::GetRenderer()
{
	return Renderer;
}
