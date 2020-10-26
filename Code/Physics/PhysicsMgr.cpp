#include "PhysicsMgr.h"

int Length;
Rigidbody** RigidBodyList;

void PhysicsMgr::Register(Rigidbody* Go)
{
	RigidBodyList = (Rigidbody**)realloc(RigidBodyList, (Length + 1) * sizeof(Rigidbody*));
	RigidBodyList[Length] = Go;
	Length++;
}

void PhysicsMgr::Remove(Rigidbody* Go)
{


	Rigidbody** f;
	f = (Rigidbody**)malloc((Length - 1) * sizeof(Rigidbody*));
	int j = 0;
	for (int i = 0; i < Length; i++)
	{
		if (RigidBodyList[i] == Go)
		{
			continue;
		}
		else
		{
			f[j] = RigidBodyList[i];
			j++;
		}
	}
	RigidBodyList = f;
	Length--;


}

void PhysicsMgr::UpdatePhysics()
{

	for (int i = 0; i < Length; i++)
	{
		if (RigidBodyList[i]->IsActive())
		{
			RigidBodyList[i]->Update();
		}
	}

	for (int i = 0; i < Length; i++)
	{
		for (int j = i+1; j < Length; j++)
		{
			if (RigidBodyList[i]->Collider->Collides(RigidBodyList[j]->Collider))//They Collide baby
			{
				RigidBodyList[i]->Owner->OnCollision(RigidBodyList[j]->Collider);
				RigidBodyList[j]->Owner->OnCollision(RigidBodyList[i]->Collider);
			}
		}
	}
}

void PhysicsMgr::Init()
{
	Length = 0;
}
