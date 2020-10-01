#include "LTexture.h"

LTexture::LTexture()
{
	mTexture = (SDL_Texture*)malloc(sizeof(SDL_Texture*));
	mWidth = 0;
	mHeight = 0;
	mDefaultRect = { 0,0,0,0 };
	mRender = (SDL_Renderer*)malloc(sizeof(SDL_Renderer*));
	flipX = false;
	flipY = false;
}



LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFrom(std::string path, SDL_Renderer* Renderer)
{
	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	mRender = Renderer;
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		//texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//get the d...mensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	mDefaultRect = { 0,0,mWidth,mHeight };


	mTexture = newTexture;
	return mTexture != NULL;

}

void LTexture::setTile(int w, int h)
{
	if (w != 0 && h != 0)//TILESHEET! 
	{
		mDefaultRect = { 0,0,w,h };
	}
}

void LTexture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
		
	}
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(SDL_Rect* TilesetFrame, SDL_Rect* renderQuad)
{
	
	SDL_RendererFlip flipType;
	if (flipX)
	{
		flipType = SDL_FLIP_HORIZONTAL;
	}
	else
	{
		flipType = SDL_FLIP_NONE;
	}

	SDL_RenderCopyEx(mRender, mTexture, TilesetFrame, renderQuad,0,NULL,flipType);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
