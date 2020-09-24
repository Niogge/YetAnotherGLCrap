#pragma once
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_Image.h>
#include "Animation.h"

class LTexture
{
public:
	LTexture();
	~LTexture();
	bool loadFrom(std::string path, SDL_Renderer* Renderer);
	void setTile(int w,int h);
	void free();
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x, int y, SDL_Rect* clip = NULL);
	void PlayAnimation();
	void StopAnimation();
	void SwitchAnimation();
	void AddAnimation(int startTileX, int startTileY, int EndTileX, int EndTileY);
	int getWidth();
	int getHeight();
private:
	SDL_Texture* mTexture;
	SDL_Renderer* mRender;
	Animation** mAnimationClips;
	int currentAnimation;
	int NofAnimations;
	int mWidth;
	int mHeight;


	SDL_Rect mDefaultRect;
};