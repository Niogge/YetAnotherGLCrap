#pragma once
#ifndef GFXMGR_H
#define GFXMGR_H
#include "CoreInclude.h"

class GFXMgr
{
public:
	static SDL_Surface* GetImage(std::string TextureName);

private:
	friend class Game;
	static void Init();
	static bool AddTexture(std::string Name, std::string path);
};


#endif // !GFXMGR_H
