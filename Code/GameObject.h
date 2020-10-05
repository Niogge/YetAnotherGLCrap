#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "CoreInclude.h"
#include <stdlib.h>
/*
Ok so, this is clearly missing a lot of features (like component stuff and some "get" functions)

*/

class LTexture;
class Animation;
class Transform;
class IComponent;
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
	void AddAnimation(int startTileX, int startTileY, int EndTileX, int EndTileY, int FramesPerSecond);
	bool LoadTexture(std::string TextureName);
	bool LoadTexture(std::string TextureName, int TileWidth, int TileHeight);
	bool isActive();
	bool SetActive(bool activeState);
	void Destroy();
	void UpdateLayer(int8_t layer);
	void DrawLayer(int8_t layer);

	void AddComponent(IComponent* Component);
	void DetachComponent(IComponent* Component);
	template <typename T>
	T* getComponent();
	template <typename T>
	void DetachComponent();
	Transform* transform;

private:
	Vector2 pivot;
	LTexture* texture;
	SDL_Renderer* mRender;
	Animation** mAnimationClips;

	IComponent** Components;
	int NofComponents;

	int currentAnimation;
	int NofAnimations;
	int tileWidth;
	int tileHeight;
	bool active;
};

#endif // !GAMEOBJECT_H

template<typename T>
inline T* GameObject::getComponent()
{
	for (int i = 0; i < NofComponents; i++)
	{
		//std::cout << Components[i]->getType() << " " << typeid(T*).name() << std::endl;
		if (Components[i]->getType() == typeid(T*).name())
		{

			return (T*)Components[i];
		}
	}
	return nullptr;
}

template<typename T>
inline void GameObject::DetachComponent()
{
	T* component = this->getComponent<T>();
	DetachComponent(component);
}
