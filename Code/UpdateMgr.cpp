#include "UpdateMgr.h"

static int ListLength;
static GameObject** UpdateList;

void UpdateMgr::Init()
{
	UpdateList = nullptr;
	ListLength= 0;
}

void UpdateMgr::Register(GameObject * Go)
{
	UpdateList = (GameObject**) realloc(UpdateList, (ListLength + 1) * sizeof(GameObject*));
	UpdateList[ListLength] = Go;
	ListLength++;
}

void UpdateMgr::Remove(GameObject* Go)
{
	GameObject** f;
	f = (GameObject**) malloc((ListLength - 1) * sizeof(GameObject * ));
	int j = 0;
	for (int i = 0; i < ListLength; i++)
	{
		if (UpdateList[i] == Go)
		{
			continue;
		}
		else
		{
			f[j] = UpdateList[i];
			j++;
		}
	}
	UpdateList = f;
	ListLength--;
}

void UpdateMgr::Update()
{
	for (int i = 0; i < ListLength; i++)
	{
		UpdateList[i]->Update();
	}
}
