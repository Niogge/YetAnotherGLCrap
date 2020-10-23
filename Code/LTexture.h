#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "CoreInclude.h"


class LTexture
{
public:
	LTexture();
	~LTexture();
	bool loadFrom(std::string Name, SDL_Renderer* Renderer);
	void setTile(int w,int h);
	void free();
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(SDL_Rect* TilesetFrame, SDL_Rect* renderQuad, float angle);
	int getWidth();
	int getHeight();
	bool flipX;
	bool flipY;
private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
	SDL_Renderer* mRender;

	SDL_Rect mDefaultRect;
};
#endif // !TEXTURE_H