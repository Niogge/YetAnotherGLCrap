#pragma once
#ifndef Animation_H
#define Animation_H
#include "CoreInclude.h"
/*
	This was actually pretty fun to code
	There's nothing much to say, but the animation is NOT based on a texture.
	An animation is just a bunch of SDL_Rects that will be sent back to the GameObject.
	so if our artist draws every animation in the same order and same number of frames, for every character, we can swap texture
	without the need of changing the animation
	eg: Walk cycle is the first 4 frames of the first row for every tileset -> we can reuse the same animation even if we change the texture. 



*/

class Animation
{
public:
	Animation(std::string AnimName);
	~Animation();
	void SetAnimationClip(int startTileX, int startTileY, int EndTileX, int EndTileY, int tileW, int tileH, int FramesPerSecond);
	void AnimationExecution();
	SDL_Rect* GetFrame();
	void Play();
	void Stop();
	std::string getName();
	bool IsPlaying;

private:
	std::string AnimationName;
	int clipLength;
	SDL_Rect* frames;
	int currentFrame;
	float SecondsPerFrame;
	float CurrFrameTime;

};

#endif // !Animation_H