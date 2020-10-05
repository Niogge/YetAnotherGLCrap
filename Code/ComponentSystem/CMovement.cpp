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
	}
	else if (InputMgr::GetKey(SDL_SCANCODE_D))
	{
		direction.x = 1.;
	}


	direction.Normalize();


	gameObject->transform->position += direction * speed * Time::GetDeltaTime();
}

void CMovement::OnDraw()
{
}

void CMovement::SetSpeed(float s)
{
	speed = s;
}
