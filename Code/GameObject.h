#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "CoreEngine.h"
#include "LTexture.h"
#include "Animation.h"


class GameObject
{
public:
	GameObject();
	~GameObject();
	void Init(SDL_Renderer* Renderer);
	void Update();
	void Draw();
	void PlayAnimation();
	void StopAnimation();
	void SwitchAnimation();
	void AddAnimation(int startTileX, int startTileY, int EndTileX, int EndTileY);
	bool LoadTexture(std::string path);
	bool LoadTexture(std::string path, int TileWidth, int TileHeight);
	void Destroy();
	//REMOVE THIS:
	void Move(Vector2 dir);
private:
	Vector2 position;
	Vector2 pivot;
	LTexture* texture;
	SDL_Renderer* mRender;
	Animation** mAnimationClips;
	int currentAnimation;
	int NofAnimations;
	int tileWidth;
	int tileHeight;
};
