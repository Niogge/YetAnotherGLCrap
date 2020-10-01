#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "CoreInclude.h"


class LTexture;
class Animation;

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
	void AddAnimation(int startTileX, int startTileY, int EndTileX, int EndTileY,int FramesPerSecond);
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

#endif // !GAMEOBJECT_H