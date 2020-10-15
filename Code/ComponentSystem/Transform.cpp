#include "Transform.h"

Transform::Transform(float x, float y, GameObject* go)
{
	position = Vector2(x, y);
	gameObject = go;
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
}

void Transform::OnDraw()
{
}

void Transform::OnDetach()
{
}

Vector2 Transform::Up()
{
	return Vector2(0,-1);
}

Vector2 Transform::Forward()
{
	return Vector2(1,0);
}
