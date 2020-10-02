#pragma once
#ifndef GFXMGR_H
#define GFXMGR_H
#include "CoreInclude.h"

class GFXMgr
{
public:
	static SDL_Texture* GetImage(std::string TextureName);

private:
	friend class Game;
	static void Init(SDL_Renderer * renderer);
	static bool AddTexture(std::string Name, std::string path);

};


#endif // !GFXMGR_H
