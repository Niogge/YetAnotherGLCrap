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

bool LTexture::loadFrom(std::string Name, SDL_Renderer* Renderer)
{
	free();

	//This is some wrapping for basic SDL functions, i'm not going to comment this in depth
	//Just remember that the basic logic is:
	// assign the result of a function to a pointer
	//check if the pointer is null
	// if true: Error
	// if false: Go on.


	SDL_Texture* newTexture = GFXMgr::GetImage(Name);
	mRender = Renderer;
	SDL_QueryTexture(newTexture, NULL, NULL, &mWidth, &mHeight);

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

void LTexture::render(SDL_Rect* TilesetFrame, SDL_Rect* renderQuad, float angle)
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

	SDL_RenderCopyEx(mRender, mTexture, TilesetFrame, renderQuad,angle,NULL,flipType);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
