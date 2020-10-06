#include "Animation.h"
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_Image.h>


Animation::Animation(std::string AnimName)
{
	int clipLength = 0;
	int currentFrame = 0;
	bool IsPlaying = false;
	frames = nullptr;
	CurrFrameTime = 0.;
	SecondsPerFrame = 0.;
	AnimationName = AnimName;
}

Animation::~Animation()
{
	//KEK
}

void Animation::SetAnimationClip(int startTileX, int startTileY, int EndTileX, int EndTileY, int tileW, int tileH, int FramesPerSecond)
{
	//There was no need to use a malloc here, but whatever.
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
	SecondsPerFrame = 1. / FramesPerSecond;
}

void Animation::AnimationExecution()
{
	if (frames != nullptr)
	{

		if (IsPlaying)
		{
			CurrFrameTime += Time::GetDeltaTime();
			if (CurrFrameTime >= SecondsPerFrame)
			{
				CurrFrameTime = 0.;
				currentFrame = (currentFrame + 1) % clipLength;
			}
		}
	}
	
}

SDL_Rect* Animation::GetFrame()
{
	return frames + currentFrame;
}

void Animation::Play()
{
	if (!IsPlaying)
	{
		IsPlaying = true;
		currentFrame = 0;
		CurrFrameTime = 0.;

	}
}

void Animation::Stop()
{
	IsPlaying = false;
	currentFrame = 0;
	CurrFrameTime = 0.;
}

std::string Animation::getName()
{
	return AnimationName;
}
