#include "DrawMgr.h"



static std::map<int8_t, int> ListLength;
static std::map<int8_t, GameObject**> DrawList;
void DrawMgr::Init()
{
}

void DrawMgr::Register(GameObject* Go, int8_t layer)
{
	DrawList[layer] = (GameObject**)realloc(DrawList[layer], (ListLength[layer] + 1) * sizeof(GameObject*));
	DrawList[layer][ListLength[layer]] = Go;
	ListLength[layer]++;
}

void DrawMgr::Remove(GameObject* Go)
{
	int8_t layerToUpdate;
	bool found = false;
	for (int8_t layer = -128; layer < 127; layer++)
	{

		if (ListLength[layer] == 0)
		{
			continue;
		}
		for (int i = 0; i < ListLength[layer]; i++)
		{
			if (DrawList[layer][i] == Go)
			{
				//this is the layer
				found = true;
				layerToUpdate = layer;
				break;
			}
		}
		if (found)
		{
			break;
		}
	}
	if (found)
	{


		GameObject** f;
		f = (GameObject**)malloc((ListLength[layerToUpdate] - 1) * sizeof(GameObject*));
		int j = 0;
		for (int i = 0; i < ListLength[layerToUpdate]; i++)
		{
			if (DrawList[layerToUpdate][i] == Go)
			{
				continue;
			}
			else
			{
				f[j] = DrawList[layerToUpdate][i];
				j++;
			}
		}
		DrawList[layerToUpdate] = f;
		ListLength[layerToUpdate]--;
	}

}

void DrawMgr::Draw()
{
	for (int8_t layer = -128; layer < 127; layer++)
	{
		if (ListLength[layer] != 0)
		{
			for (int i = 0; i < ListLength[layer]; i++)
			{
				if (DrawList[layer][i]->isActive())
				{
					DrawList[layer][i]->Draw();
				}
			}
		}
	}
}
