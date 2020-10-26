#pragma once
#ifndef MATH_H
#include<cmath>
/*
For now there's only vector2 struct, will probably add stuff later

Vector2 is nothing weird, still need to overload some operators but atm is fine 
*/
struct Mat2x2;
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
	Vector2 operator*(Mat2x2 B);
};
struct Mat2x2
{
public:
	Mat2x2();
	Mat2x2(float x00, float x01, float x10, float x11);
	Mat2x2(float mat[2][2]);
	float GetValue(int i, int j);
	Mat2x2 Inverse();
	void Invert();
	Mat2x2 Transposed();
	void Transpose();
	float Determinant();
	void printMatrix();
	static Mat2x2 RotationMatrix(float angle);


	Mat2x2 operator/ (float B);
	Mat2x2 operator* (float B);
	Mat2x2 operator* (Mat2x2 B);
	Vector2 operator* (Vector2 B);
private:
	float matrix[2][2];

};
#endif // !MATH_H