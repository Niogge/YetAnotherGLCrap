#pragma once
#ifndef  GAME_H
#define GAME_H

#include "CoreInclude.h"

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
	SDL_Window* Window;
	SDL_Surface* ScreenSurface;
	SDL_Renderer* Renderer;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	std::string WindowName;

};
#endif // ! GAME_H