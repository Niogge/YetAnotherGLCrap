#pragma once
#ifndef UPDATEMGR_H
#define UPDATEMGR_H
#include "CoreInclude.h"

/* OK SO 
	declaring a friend class allows that class to access it's private functions and variables.
	So, the only place you can call the Update of the update manager is inside the Game class, nowhere else. 
*/

class GameObject;
class UpdateMgr
{
public:
	static void Register(GameObject* go);
	static void Remove(GameObject* go);
private:
	friend class Game;
	static void Update();
	static void Init();

};



#endif // !UPDATEMGR_H
