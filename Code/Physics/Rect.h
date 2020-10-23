#pragma once
#ifndef RECT_H
#define RECT_H
#include "Shape.h"
#include "..\CoreInclude.h"
struct Projection
{
	Vector2 max;
	Vector2 min;
};


class Rect : Shape{
public:
	Rect(Vector2 offset, Rigidbody * rb, float width, float height);
	float GetWidth();
	float GetHeight();
	float GetHalfWidth();
	float GetHalfHeight();
	bool Contains(Vector2 point);
	bool Collides(Rect* other);
	Vector2 GetRelativeYaxis();
	Vector2 GetRelativeXaxis();
	Projection ProjectRect(Vector2 Axis);
private:
	float Width;
	float Height;
	
};

#endif // !RECT_H
