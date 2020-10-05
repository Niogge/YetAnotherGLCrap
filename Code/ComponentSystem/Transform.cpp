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
