#include "Math.h"
#include <iostream>
#include <math.h>

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2::Magnitude()
{
	return sqrt(x * x + y * y);
}

float Vector2::SignedMagnitude()
{
	float mag = sqrt(x * x + y * y);
	if (x < 0 || y < 0)
	{
		mag = -mag;
	}
	return mag;
}

void Vector2::Normalize()
{
	float magnitude = Magnitude();
	if (magnitude != 0.)
	{
		x = x / magnitude;
		y = y / magnitude;
	}
}

Vector2 Vector2::Normalized()
{
	Vector2 toNormalize = Vector2(x, y);
	toNormalize.Normalize();

	return toNormalize;
}

float Vector2::DotProduct(Vector2 A, Vector2 B)
{
	return (A.x * B.x + A.y * B.y);
}

Vector2 Vector2::Rotate(float angle, Vector2 toRotate, Vector2 center)
{
	Vector2 actualVector = toRotate - center;
	actualVector = toRotate*Mat2x2::RotationMatrix(angle);
	actualVector = actualVector + center;
	return actualVector;
}

Vector2 Vector2::operator*(float B)
{
	return Vector2(this->x * B, this->y * B);
}

Vector2 Vector2::operator/(float B)
{
	return Vector2(this->x / B, this->y / B);
}

Vector2 Vector2::operator+(Vector2 B)
{
	return Vector2(this->x + B.x, this->y + B.y);
}

void Vector2::operator+=(Vector2 B)
{
	this->x += B.x;
	this->y += B.y;
}

Vector2 Vector2::operator-(Vector2 B)
{
	return Vector2(this->x - B.x, this->y - B.y);
}

Vector2 Vector2::operator*(Mat2x2 B)
{
	return Vector2(x * B.GetValue(0,0) + y * B.GetValue(0,1), x*B.GetValue(1,0) + y*B.GetValue(1,1));
}

Mat2x2::Mat2x2()
{
	matrix[0][0] = 0;
	matrix[0][1] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 0;
}

Mat2x2::Mat2x2(float x00, float x01, float x10, float x11)
{
	matrix[0][0] = x00;
	matrix[0][1] = x01;
	matrix[1][0] = x10;
	matrix[1][1] = x11;
}

Mat2x2::Mat2x2(float mat[2][2])
{
	matrix[0][0] = mat[0][0];
	matrix[0][1] = mat[0][1];
	matrix[1][0] = mat[1][0];
	matrix[1][1] = mat[1][1];
}

float Mat2x2::GetValue(int i, int j)
{
	if (i >= 0 && i <= 1 && j >= 0 && j <= 1)
	{
		return matrix[i][j];
	}
	return 404.404f;
}

Mat2x2 Mat2x2::Inverse()
{
	float det = this->Determinant();
	if (det != 0)
	{
		Mat2x2 inv = Mat2x2(matrix[1][1], -matrix[0][1], -matrix[1][0], matrix[0][0]);
		return inv / (this->Determinant());

	}
	return Mat2x2();
}

void Mat2x2::Invert()
{
	float det = this->Determinant();
	if (det != 0)
	{
		float t = matrix[0][0];
		matrix[0][0] = matrix[1][1]/det;
		matrix[1][1] = t/det;
		matrix[0][1] = -matrix[0][1] / det;
		matrix[1][0] = -matrix[1][0] / det;
	}

}

Mat2x2 Mat2x2::Transposed()
{
	return Mat2x2(matrix[0][0], matrix[1][0], matrix[0][1], matrix[1][1]);
}

void Mat2x2::Transpose()
{
	float t = matrix[0][1];
	matrix[0][1] = matrix[1][0];
	matrix[1][0] = t;
}

float Mat2x2::Determinant()
{
	return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

void Mat2x2::printMatrix()
{
	std::cout << "|" << matrix[0][0] << " " << matrix[0][1] << "|" << std::endl;
	std::cout << "|" << matrix[1][0] << " " << matrix[1][1] << "|" << std::endl;
}

Mat2x2 Mat2x2::RotationMatrix(float angle)
{
	return Mat2x2(cos(angle), -sin(angle), sin(angle), cos(angle));
}

Mat2x2 Mat2x2::operator/(float B)
{
	if (B != 0)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				matrix[i][j] = matrix[i][j] / B;
			}
		}

		return Mat2x2(matrix);
	}
	return Mat2x2();
}

Mat2x2 Mat2x2::operator*(float B)
{

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matrix[i][j] = matrix[i][j] * B;
		}
	}

	return Mat2x2(matrix);
}

Mat2x2 Mat2x2::operator*(Mat2x2 B)
{
	float newMatrix[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2;k++)
		{
			newMatrix[i][k] = 0;
			for (int j = 0; j < 2; j++)
			{
				newMatrix[i][k] += matrix[i][j] * B.GetValue(j, k);
			}
		}
	}
	return Mat2x2(newMatrix);
}

Vector2 Mat2x2::operator*(Vector2 B)
{
	return B*(*this);
}
