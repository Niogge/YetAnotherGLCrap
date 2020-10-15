#include "Rigidbody.h"

Vector2 Gravity = Vector2(0,9.81f);

Rigidbody::Rigidbody(GameObject * owner)
{
	Velocity = Vector2(0, 0);
	Owner = owner;
	UseGravity = true;
	mass = 1;
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

void Rigidbody::SetGravity(Vector2 GravityDirection, float GravityValue)
{
	Gravity = GravityDirection * GravityValue;
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

