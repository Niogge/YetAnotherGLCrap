#include "Rigidbody.h"

Vector2 Gravity = Vector2(0,9.81f);

Rigidbody::Rigidbody(GameObject * owner)
{
	Velocity = Vector2(0, 0);
	Owner = owner;
	UseGravity = true;
	mass = 1;
	Active = true;
	PhysicsMgr::Register(this);
}

Rigidbody::~Rigidbody()
{
	Owner = nullptr;

}

bool Rigidbody::EnableGravity(bool Active)
{
	UseGravity = Active;
	return UseGravity;
}

void Rigidbody::AddForce(Vector2 force)
{
	Velocity += (force / mass) * Time::GetDeltaTime();
}

void Rigidbody::SetMass(float mass)
{
	this->mass = mass;
}

Vector2 Rigidbody::GetPosition()
{
	return Owner->transform->position;
}

Transform* Rigidbody::GetTransform()
{
	return Owner->transform;
}

void Rigidbody::SetGravity(Vector2 GravityDirection, float GravityValue)
{
	Gravity = GravityDirection * GravityValue;
}

bool Rigidbody::IsActive()
{
	return Active;
}

bool Rigidbody::SetActive(bool active)
{
	Active = active;
	return active;
}

Rect* Rigidbody::GetCollider()
{
	return Collider;
}

void Rigidbody::MakeCollider(Vector2 offset, float width, float height)
{
	Collider = new Rect(offset, this, width, height);
}

void Rigidbody::Update()
{
	if (UseGravity)
	{
		this->AddForce(Gravity * mass);
	}

	Owner->transform->position += Velocity * Time::GetDeltaTime();
	
	//std::cout << " " << Velocity.x << " / " << Velocity.y << std::endl;

}

