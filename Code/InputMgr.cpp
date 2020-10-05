#include "InputMgr.h"

SDL_Event e;
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
bool InputMgr::GetKey(SDL_Keycode key)
{

	if (SDL_PollEvent(&e) != NULL && e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == key)
		{
			return true;
		}
		return false;
	}
	return false;
}

void InputMgr::Update(bool* quitEvent)
{
	if (SDL_PollEvent(&e) != NULL)
	{
		if (quitEvent != nullptr && e.type == SDL_QUIT) //quit request, che e` tipo er click sulla X 
		{
			*quitEvent = true;
		}
	}
}
