#include "GFXMgr.h"


std::map<std::string, SDL_Surface*> LoadedTextures;

SDL_Surface* GFXMgr::GetImage(std::string TextureName)
{
	if (LoadedTextures[TextureName] != NULL)
	{
		return LoadedTextures[TextureName];
	}
	return NULL;
}

void GFXMgr::Init()
{
	AddTexture("Tikki","Assets/Tikki.png");
}

bool GFXMgr::AddTexture(std::string Name,std::string path)
{
	SDL_Surface* tempTexture = IMG_Load(path.c_str());
	if (tempTexture != NULL)
	{
		LoadedTextures[Name] = tempTexture;
		return true; 
	}
	else
	{
		printf("Unable to load %s image %s! SDL_image Error: %s\n",Name.c_str(), path.c_str(), IMG_GetError());
	}
}
