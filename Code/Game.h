#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "GameObject.h"


class Game
{
public:
	Game(int W, int H, std::string Name);
	~Game();
	void Loop();
	bool Init();
	bool LoadMedia();
	void End();
private:
	GameObject* charGO;
	SDL_Window* Window;
	SDL_Surface* ScreenSurface;
	SDL_Renderer* Renderer;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	std::string WindowName;

};