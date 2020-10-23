#include "Shape.h"

Shape::Shape(Vector2 offset, Rigidbody* rb)
{
	rigidBody = rb;
	relativePosition = offset;
}

Vector2 Shape::GetPosition()
{
	return rigidBody->GetPosition() + relativePosition;
}
