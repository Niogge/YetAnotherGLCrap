#pragma once
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_Image.h>


class Animation
{
public:
	Animation();
	~Animation();
	void SetAnimationClip(int startTileX, int startTileY, int EndTileX, int EndTileY, int tileW, int tileH);
	SDL_Rect* AnimationExecution();
	void Play();
	void Stop();
	bool IsPlaying;

private:
	int clipLength;
	SDL_Rect* frames;
	int currentFrame;
};
