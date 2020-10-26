#pragma once
#ifndef SCENE_H
#define SCENE_H


class Scene
{
public:
	Scene();
	~Scene();
	virtual void InitScene()=0;
	virtual void UpdateScene()=0;
	virtual void ExitScene()=0;
protected:
	virtual bool LoadSceneMedia() = 0;
};


#endif