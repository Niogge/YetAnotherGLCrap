#pragma once
#ifndef TIME_H
#define TIME_H

#include "CoreInclude.h"

class Time
{
public:
	static void Init();
	static float GetTime();
	static float GetDeltaTime();
private:
	friend class Game;
	static void Tick();
};

#endif