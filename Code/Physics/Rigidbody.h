#pragma once
#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#include "../CoreInclude.h"
class Rigidbody
{
public:
	Rigidbody(GameObject* owner);
	~Rigidbody();
	bool EnableGravity(bool Active);
	void AddForce(Vector2 force);
	void SetMass(float mass);
	static void SetGravity(Vector2 GravityDirection, float GravityValue);
private:
	friend class GameObject;
	Vector2 Velocity;
	GameObject* Owner;
	bool UseGravity;
	float mass;
	void Update();

	


};
#endif // !RIGIDBODY_H
