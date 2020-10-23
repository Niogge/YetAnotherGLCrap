#pragma once
#ifndef MATH_H
#include<cmath>
/*
For now there's only vector2 struct, will probably add stuff later

Vector2 is nothing weird, still need to overload some operators but atm is fine 
*/
struct Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	float x;
	float y;
	float Magnitude();
	float SignedMagnitude();
	void Normalize();
	Vector2 Normalized();
	static float DotProduct(Vector2 A, Vector2 B);
	static Vector2 Rotate(float angle, Vector2 toRotate, Vector2 center = Vector2(0, 0));

	Vector2 operator* (float B);
	Vector2 operator/ (float B);
	Vector2 operator+ (Vector2 B);
	void operator+= (Vector2 B);
	Vector2 operator- (Vector2 B);

};

#endif // !MATH_H