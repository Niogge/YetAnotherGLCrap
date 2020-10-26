#pragma once
#ifndef SCENETSTONE_H
#define SCENETSTONE_H
#include "..\CoreInclude.h"

class TestSceneOne :public Scene
{
public:
	TestSceneOne();
	~TestSceneOne();
	virtual void InitScene();
	virtual void UpdateScene();
	virtual void ExitScene();

protected:
	virtual bool LoadSceneMedia();
private:
	GameObject* charGO;
	GameObject* Blocks[4];
};
#endif // !SCENETSTONE_H

