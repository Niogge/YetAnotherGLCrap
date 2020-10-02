#pragma once
#ifndef TIME_H
#define TIME_H

#include "CoreInclude.h"
/*
This is basic, uses SDL_GetTicks and some fucking basic math to give deltaTime 
*/
class Time
{
public:
	static float GetTime();
	static float GetDeltaTime();
private:
	friend class Game;
	static void Tick();
	static void Init();
};

#endif