#pragma once
#ifndef PHYSMGR_H
#define PHYSMGR_H

#include"..\CoreInclude.h"

class Rigidbody;
class PhysicsMgr
{
public:
	static void Register(Rigidbody* Go);
	static void Remove(Rigidbody* Go);
private:
	friend class Game;
	static void UpdatePhysics();
	static void Init();

};

#endif // !PHYSMGR_H