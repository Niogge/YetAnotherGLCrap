#include "DrawMgr.h"



static int ListLength;
static GameObject** DrawList;

void DrawMgr::Init()
{
	DrawList = nullptr;
	ListLength = 0;
}

void DrawMgr::Register(GameObject* Go)
{
	DrawList = (GameObject**)realloc(DrawList, (ListLength + 1) * sizeof(GameObject*));
	DrawList[ListLength] = Go;
	ListLength++;
}

void DrawMgr::Remove(GameObject* Go)
{
	GameObject** f;
	f = (GameObject**)malloc((ListLength - 1) * sizeof(GameObject*));
	int j = 0;
	for (int i = 0; i < ListLength; i++)
	{
		if (DrawList[i] == Go)
		{
			continue;
		}
		else
		{
			f[j] = DrawList[i];
			j++;
		}
	}
	DrawList = f;
	ListLength--;
}

void DrawMgr::Draw()
{
	for (int i = 0; i < ListLength; i++)
	{
		DrawList[i]->Draw();
	}
}
