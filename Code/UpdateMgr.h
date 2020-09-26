#pragma once
#ifndef UPDATEMGR_H
#define UPDATEMGR_H
#include "CoreInclude.h"

class GameObject;
class UpdateMgr
{
public:
	static void Init();
	static void Register(GameObject* go);
	static void Remove(GameObject* go);
private:
	friend class Game;
	static void Update();

};



#endif // !UPDATEMGR_H
