#pragma once
#ifndef DRAWMGR_H
#define DRAWMGR_H
#include "CoreInclude.h"

class GameObject;
class DrawMgr
{
public:
	static void Init();
	static void Register(GameObject* Go);
	static void Remove(GameObject* Go);
private:
	friend class Game;
	static void Draw();

};



#endif // !UPDATEMGR_H