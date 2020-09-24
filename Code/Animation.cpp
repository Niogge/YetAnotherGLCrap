#include "Animation.h"
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_Image.h>


Animation::Animation()
{
	int clipLength = 0;
	int currentFrame = 0;
	bool IsPlaying = false;
	frames = nullptr;
}

Animation::~Animation()
{
	//KEK
}

void Animation::SetAnimationClip(int startTileX, int startTileY, int EndTileX, int EndTileY, int tileW, int tileH)
{
	clipLength = ((EndTileX - startTileX + 1) * (EndTileY - startTileY + 1));
	frames = (SDL_Rect*)malloc(clipLength * sizeof(SDL_Rect));
	int currTile = 0;
	for (int i = startTileY; i <= EndTileY; i++)
	{
		for ( int  j = startTileX; j <= EndTileX; j++)
		{
			frames[currTile] = { j * tileW,i * tileH, tileW, tileH };
			currTile++;
		}
	}
}

SDL_Rect* Animation::AnimationExecution()
{
	SDL_Rect* toreturn = nullptr;
	
	if (frames != nullptr)
	{

		toreturn = frames + currentFrame;
		if (IsPlaying)
		{
			currentFrame = (currentFrame + 1) % clipLength;
		}
	}
	return toreturn;
}

void Animation::Play()
{
	IsPlaying = true;
	currentFrame = 0;
}

void Animation::Stop()
{
	IsPlaying = false;
	currentFrame = 0;
}
