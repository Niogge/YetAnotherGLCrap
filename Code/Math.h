#pragma once
#ifndef MATH_H
#include<cmath>

struct Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	float x;
	float y;
	float Magnitude();
	void Normalize();
	Vector2 Normalized();
	static float DotProduct(Vector2 A, Vector2 B);

	Vector2 operator* (float B);

};
#endif // !MATH_H