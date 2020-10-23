#include "Math.h"
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
    actualVector = Vector2(actualVector.x * cos(angle) - actualVector.y * sin(angle), actualVector.x * sin(angle) + actualVector.y * cos(angle));
    actualVector = actualVector + center;
    return actualVector;
}

Vector2 Vector2::operator*(float B)
{
    return Vector2(this->x *B, this->y *B);
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

