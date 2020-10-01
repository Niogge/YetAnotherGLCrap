#pragma once
#ifndef Animation_H
#define Animation_H


#include "CoreInclude.h"


class Animation
{
public:
	Animation();
	~Animation();
	void SetAnimationClip(int startTileX, int startTileY, int EndTileX, int EndTileY, int tileW, int tileH, int FramesPerSecond);
	void AnimationExecution();
	SDL_Rect* GetFrame();
	void Play();
	void Stop();
	bool IsPlaying;

private:
	int clipLength;
	SDL_Rect* frames;
	int currentFrame;
	float SecondsPerFrame;
	float CurrFrameTime;

};

#endif // !Animation_H