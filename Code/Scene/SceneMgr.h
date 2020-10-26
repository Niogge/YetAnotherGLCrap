#pragma once
#ifndef SCENEMGR_H
#define SCENEMGR_H
#include "..\CoreInclude.h"
class Game;
class Scene;
class SceneMgr
{
public:
	static int Register(Scene* scene);
	static void Remove(Scene* scene);
	static void SetScene(int sceneIndex);
	static Game* GetCurrentGame();
private:
	friend class Game;
	static void UpdateScene();
	static void Init(Game* currentGame);
};

#endif // !SCENEMGR_H
