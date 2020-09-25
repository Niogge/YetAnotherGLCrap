#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "LTexture.h"
#include "Animation.h"

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
	LTexture* charTexture;
	SDL_Window* Window;
	SDL_Surface* ScreenSurface;
	SDL_Renderer* Renderer;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	std::string WindowName;

};