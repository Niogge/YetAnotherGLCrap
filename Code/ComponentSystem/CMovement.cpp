#include "CMovement.h"

CMovement::CMovement()
{
	speed = 0.;
}

CMovement::~CMovement()
{
}

void CMovement::Start()
{
	speed = 50.;
}

void CMovement::Update()
{
	direction = Vector2(0., 0.);
	if (InputMgr::GetKey(SDL_SCANCODE_W))
	{
		direction.y = -1.;
	}
	else if (InputMgr::GetKey(SDL_SCANCODE_S))
	{
		direction.y = 1.;
	}

	if (InputMgr::GetKey(SDL_SCANCODE_A))
	{
		direction.x = -1.;
		gameObject->texture->flipX = true;

	}
	else if (InputMgr::GetKey(SDL_SCANCODE_D))
	{
		direction.x = 1.;
		gameObject->texture->flipX = false;
	}

	if (InputMgr::GetKey(SDL_SCANCODE_SPACE))
	{
		gameObject->RB->AddForce(gameObject->transform->Up() * 30);
	}

	direction.Normalize();
	if (direction.Magnitude() != 0.)
	{
		gameObject->SwitchAnimation("walk");
	}
	else
	{
		gameObject->SwitchAnimation("idle");
	}

	gameObject->transform->position += direction * speed * Time::GetDeltaTime();
}

void CMovement::OnDraw()
{
}

void CMovement::OnDetach()
{
	gameObject->SwitchAnimation("idle");
}

void CMovement::SetSpeed(float s)
{
	speed = s;
}
