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
	virtual void Start();
	virtual void Update();
	virtual void OnDraw();
private:
	virtual std::string getType() { return typeid(this).name(); }
};

#endif // !TRANSFORM_H
