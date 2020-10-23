#include "Game.h"

GameObject* charGO;
GameObject* Block1;
GameObject* Block2;

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
		if (InputMgr::GetKey(SDL_SCANCODE_C))
		{
			CMovement* c = charGO->getComponent<CMovement>();
			//std::cout << typeid(CMovement**).name() << std::endl;
			if (c != nullptr)
			{
				c->SetSpeed(200.);
			}
		}

		if (InputMgr::GetKey(SDL_SCANCODE_R))
		{
			charGO->DetachComponent<CMovement>();
		}

		UpdateMgr::Update();
		PhysicsMgr::UpdatePhysics();

		DrawMgr::Draw();

		SDL_Rect outlineRect = { charGO->transform->position.x, charGO->transform->position.y, 68,80 };
		SDL_SetRenderDrawColor(Renderer, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderDrawRect(Renderer, &outlineRect);
		SDL_SetRenderDrawColor(Renderer, 0x8A, 0x8A, 0x8A, 0xFF);


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


					charGO = new GameObject();
					CMovement* movementComponent = new CMovement();
					movementComponent->SetSpeed(100.);
					charGO->AddComponent(movementComponent);
					charGO->Init(Renderer);
					charGO->RB = new Rigidbody(charGO);
					charGO->RB->EnableGravity(false);
					
					charGO->RB->MakeCollider(Vector2(0, 0), 68,80);
					charGO->UpdateLayer(2);
					charGO->DrawLayer(2);
					//movementComponent = nullptr;

					Block1 = new GameObject();
					Block1->Init(Renderer);
					Block1->transform->position = Vector2(60, 13);
					Block1->DrawLayer(1);

					Block2 = new GameObject();
					Block2->Init(Renderer);
					Block2->transform->position = Vector2(150, 13);
					Block2->RB = new Rigidbody(Block2);
					Block2->RB->EnableGravity(false);
					Block2->RB->MakeCollider(Vector2(0, 0), 60,60);
					Block2->DrawLayer(3);
					Block2->transform->Rotate(45);
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

	if (!charGO->LoadTexture("Tikki", 80, 80))
	{
		printf("Failed to load Tikki' texture image!\n");
		success = false;
	}
	else
	{


		charGO->AddAnimation(0, 0, 2, 0, 4,"idle");
		charGO->AddAnimation(0, 1, 3, 1, 4,"walk");
		charGO->AddAnimation(0, 2, 4, 2, 4,"die");


	}
	if (!Block1->LoadTexture("Block"))
	{
		printf("Failed to load Block texture image!\n");
		success = false;
	}
	if (!Block2->LoadTexture("Block"))
	{
		printf("Failed to load Block texture image!\n");
		success = false;
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
