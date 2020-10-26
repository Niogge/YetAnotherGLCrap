#include "SceneMgr.h"

int SceneListLength;
Scene** SceneList;
Game* game;
Scene* CurrentScene;
int SceneMgr::Register(Scene* scene)
{
	SceneList = (Scene**)realloc(SceneList, (SceneListLength + 1) * sizeof(Scene*));
	SceneList[SceneListLength] = scene;
	SceneListLength++;
	return SceneListLength - 1;
}

void SceneMgr::Remove(Scene* scene)
{
	Scene** f;
	f = (Scene**)malloc((SceneListLength - 1) * sizeof(Scene*));
	int j = 0;
	for (int i = 0; i < SceneListLength; i++)
	{
		if (SceneList[i] == scene)
		{
			continue;
		}
		else
		{
			f[j] = SceneList[i];
			j++;
		}
	}
	SceneList = f;
	SceneListLength--;
}

void SceneMgr::SetScene(int sceneIndex)
{
	if (sceneIndex >= SceneListLength)
	{
		return;
	}
	if (CurrentScene != nullptr)
	{
		CurrentScene->ExitScene();
	}

	CurrentScene = SceneList[sceneIndex];
	CurrentScene->InitScene();
}

Game* SceneMgr::GetCurrentGame()
{
	return game;
}

void SceneMgr::UpdateScene()
{
	CurrentScene->UpdateScene();
}

void SceneMgr::Init(Game* currentGame)
{
	SceneListLength = 0;
	CurrentScene = nullptr;
	game = currentGame;
}
