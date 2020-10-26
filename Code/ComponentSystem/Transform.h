#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "..\CoreInclude.h"

class GameObject;
class Transform : public IComponent
{
public:
	Transform(float x, float y, GameObject * go);
	~Transform();
	Vector2 position;
	float Rotation;
	virtual void Start();
	virtual void Update();
	virtual void OnDraw();
	virtual void OnDetach();
	virtual void OnCollision(Rect * other);
	float Rotate(float angle);
	Vector2 Up();
	Vector2 Forward();
	void SetParent(Transform* p);
	void SetParent(Transform* p, Vector2 pos, float angle);
	Transform* GetParent();
	void DetachParent();
private:
	virtual std::string getType() { return typeid(this).name(); }
	Transform* parent;
	Vector2 relativePosition;
	float relativeRotation;
};

#endif // !TRANSFORM_H
