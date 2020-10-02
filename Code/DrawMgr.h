#pragma once
#ifndef DRAWMGR_H
#define DRAWMGR_H
#include "CoreInclude.h"


/* OK SO
	declaring a friend class allows that class to access it's private functions and variables.
	So, the only place you can call the Draw of the Draw manager is inside the Game class, nowhere else.
*/

class GameObject;
class DrawMgr
{
public:
	static void Register(GameObject* Go, int8_t layer = 0);
	static void Remove(GameObject* Go);
private:
	friend class Game;
	static void Draw();
	static void Init();

};



#endif // !UPDATEMGR_H