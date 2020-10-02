#include "GFXMgr.h"

SDL_Renderer* mRenderer;
static std::map<std::string, SDL_Texture*> LoadedTextures;

SDL_Texture* GFXMgr::GetImage(std::string TextureName)
{
	if (LoadedTextures[TextureName] != NULL)
	{
		return LoadedTextures[TextureName];
	}
	return NULL;
}

void GFXMgr::Init(SDL_Renderer* Render)
{
	mRenderer = Render;
	AddTexture("Tikki","Assets/Tikki.png");
	AddTexture("BG","Assets/BackGround.png");
	AddTexture("Block","Assets/Block.png");

}

bool GFXMgr::AddTexture(std::string Name,std::string path)
{
	SDL_Surface* tempTexture = IMG_Load(path.c_str());
	if (tempTexture != NULL)
	{
		SDL_Texture * newTexture = SDL_CreateTextureFromSurface(mRenderer, tempTexture);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", Name.c_str(), SDL_GetError());
			return false;
		}
		else
		{
		
			LoadedTextures[Name] = newTexture;
		}
		SDL_FreeSurface(tempTexture);
		return true;
	}
	else
	{
		printf("Unable to load %s image %s! SDL_image Error: %s\n",Name.c_str(), path.c_str(), IMG_GetError());
		return false;
	}
}
