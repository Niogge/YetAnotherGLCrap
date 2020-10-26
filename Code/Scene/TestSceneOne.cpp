#include "TestSceneOne.h"

TestSceneOne::TestSceneOne()
{
}

TestSceneOne::~TestSceneOne()
{
}

void TestSceneOne::InitScene()
{
	charGO = new GameObject();
	CMovement* movementComponent = new CMovement();
	movementComponent->SetSpeed(100.);
	charGO->AddComponent(movementComponent);
	charGO->Init(SceneMgr::GetCurrentGame()->GetRenderer());
	charGO->RB = new Rigidbody(charGO);
	charGO->RB->EnableGravity(false);
	charGO->transform->position = Vector2(60, 40);

	charGO->RB->MakeCollider(Vector2(0, 0), 20, 20);
	charGO->tag = "Player";
	charGO->UpdateLayer(2);
	charGO->DrawLayer(2);
	//movementComponent = nullptr;


	for (int i = 0; i < 4; i++)
	{

		Blocks[i] = new GameObject();
		Blocks[i]->Init(SceneMgr::GetCurrentGame()->GetRenderer());
		Blocks[i]->transform->position = Vector2(90 * i + 180, 40);
		Blocks[i]->RB = new Rigidbody(Blocks[i]);
		Blocks[i]->RB->EnableGravity(false);
		Blocks[i]->RB->MakeCollider(Vector2(0, 0), 60, 60);
		Blocks[i]->tag = "Block";
		Blocks[i]->DrawLayer(1);
		Blocks[i]->transform->Rotate(15 * i);

	}

	LoadSceneMedia();
	
}

void TestSceneOne::UpdateScene()
{
}

void TestSceneOne::ExitScene()
{
	charGO->Destroy();
	charGO = nullptr;
	for (int i = 0; i < 4; i++)
	{
		Blocks[i]->Destroy();
		Blocks[i] = nullptr;
	}
}

bool TestSceneOne::LoadSceneMedia()
{
	bool success = true;
	if (!charGO->LoadTexture("Tikki", 80, 80))
	{
		printf("Failed to load Tikki' texture image!\n");
		success = false;
	}
	else
	{


		charGO->AddAnimation(0, 0, 2, 0, 4, "idle");
		charGO->AddAnimation(0, 1, 3, 1, 4, "walk");
		charGO->AddAnimation(0, 2, 4, 2, 4, "die");


	}
	for (int i = 0; i < 4; i++)
	{

		if (!Blocks[i]->LoadTexture("Block"))
		{
			printf("Failed to load Block texture image!\n");
			success = false;
		}
	}

	return success;
}
