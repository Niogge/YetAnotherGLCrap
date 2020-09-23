#pragma once
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_Image.h>

class LTexture
{
public:
	LTexture();
	~LTexture();
	bool loadFrom(std::string path, SDL_Renderer* Renderer);
	void free();
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void render(int x, int y, SDL_Rect* clip = NULL);
	int getWidth();
	int getHeight();
private:
	SDL_Texture* mTexture;
	SDL_Renderer* mRender;
	int mWidth;
	int mHeight;

};