#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#define RECT_H
#include "..\CoreInclude.h"

class Shape
{
private:
	Vector2 relativePosition;
protected:
	Rigidbody* rigidBody;
public:
	Shape(Vector2 offset, Rigidbody* rb);
	Vector2 GetPosition();
	Transform* GetTransform();
	virtual bool Contains(Vector2 point) = 0;
	std::string GetTag();
};

#endif // !SHAPE_H
