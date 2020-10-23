#pragma once
#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#include "../CoreInclude.h"

class Rect;
class Transform;
class Rigidbody
{
public:
	Rigidbody(GameObject* owner);
	~Rigidbody();
	bool EnableGravity(bool Active);
	void AddForce(Vector2 force);
	void SetMass(float mass);
	Vector2 GetPosition();
	Transform* GetTransform();
	static void SetGravity(Vector2 GravityDirection, float GravityValue);
	bool IsActive();
	bool SetActive(bool active);
	Rect* GetCollider();
	void MakeCollider(Vector2 offset, float width, float height);
private:
	friend class GameObject;
	friend class PhysicsMgr;
	Vector2 Velocity;
	GameObject* Owner;
	Rect* Collider;
	bool UseGravity;
	float mass;
	void Update();
	bool Active;

	


};
#endif // !RIGIDBODY_H
