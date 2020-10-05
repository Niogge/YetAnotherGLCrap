#include "InputMgr.h"

const Uint8* _keyStates = nullptr;
InputMgr::InputMgr()
{
	Init();
}
InputMgr::~InputMgr()
{
	Free();
}
void InputMgr::Init()
{
}
void InputMgr::Free()
{
}
bool InputMgr::GetKey(SDL_Scancode key)
{
	if (_keyStates != 0)
	{
		return _keyStates[key];
	}
	return false;
}

void InputMgr::Update(bool* quitEvent)
{
	_keyStates = SDL_GetKeyboardState(0);
	SDL_Event e;
	while (SDL_PollEvent(&e) != NULL)
	{
		if (quitEvent != nullptr && e.type == SDL_QUIT) //quit request, che e` tipo er click sulla X 
		{
			*quitEvent = true;
		}
	}


}
