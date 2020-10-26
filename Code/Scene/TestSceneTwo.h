#pragma once
#ifndef SCENETSTTWO_H
#define SCENETSTTWO_H
#include "..\CoreInclude.h"

class TestSceneTwo : public Scene
{
public:
	TestSceneTwo();
	~TestSceneTwo();
	virtual void InitScene();
	virtual void UpdateScene();
	virtual void ExitScene();

protected:
	virtual bool LoadSceneMedia();
private:
	GameObject* charGO;
	GameObject* Blocks[4];
};
#endif // !SCENETSTTWO_H

