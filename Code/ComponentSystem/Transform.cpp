#include "Transform.h"

Transform::Transform(float x, float y, GameObject* go)
{
	position = Vector2(x, y);
	gameObject = go;
	Rotation = 0;
	parent = nullptr;
}

Transform::~Transform()
{
	gameObject = nullptr;
}

void Transform::Start()
{
}

void Transform::Update()
{
	if (parent != nullptr)
	{
		position = parent->position + relativePosition;
		Rotation = parent->Rotation + relativeRotation;
	}
}

void Transform::OnDraw()
{
}

void Transform::OnDetach()
{
}

void Transform::OnCollision(Rect* other)
{
}


float Transform::Rotate(float angle)
{
	Rotation = angle;
	return angle;
}

Vector2 Transform::Up()
{
	return Vector2::Rotate(Rotation, Vector2(0, -1));
	
}

Vector2 Transform::Forward()
{
	return Vector2::Rotate(Rotation, Vector2(1,0));;
}

void Transform::SetParent(Transform* p)
{
	parent = p;
	relativePosition = position - parent->position;
	relativeRotation = Rotation - parent->Rotation;
}

void Transform::SetParent(Transform* p, Vector2 pos, float angle)
{
	parent = p;
	relativePosition = pos;
	relativeRotation = angle;
}

Transform* Transform::GetParent()
{
	return parent;
}

void Transform::DetachParent()
{
	parent = nullptr;
}
