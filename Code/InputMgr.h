#pragma once
#ifndef INPUTMGR_H
#define INPUTMGR_H

#include "CoreInclude.h"

class InputMgr
{
public:
	InputMgr();
	~InputMgr();
	static void Init();
	static void Free();
	static bool GetKey(SDL_Scancode key);
private:
	friend class Game;
	static void Update(bool * quitEvent);
	
};
#endif // !INPUT_MGR
