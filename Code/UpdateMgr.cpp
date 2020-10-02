#include "UpdateMgr.h"

static std::map<int8_t, int> ListLength;
static std::map<int8_t, GameObject**> UpdateList;

void UpdateMgr::Init()
{

}

void UpdateMgr::Register(GameObject* Go, int8_t layer)
{
	int lsl = ListLength[layer];
	UpdateList[layer] = (GameObject**)realloc(UpdateList[layer], (lsl + 1) * sizeof(GameObject*));
	UpdateList[layer][lsl] = Go;
	ListLength[layer]++;
}

void UpdateMgr::Remove(GameObject* Go)
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
			if (UpdateList[layer][i] == Go)
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
			if (UpdateList[layerToUpdate][i] == Go)
			{
				
				continue;
			}
			else
			{
				f[j] = UpdateList[layerToUpdate][i];
				j++;
			}
		}
		UpdateList[layerToUpdate] = f;
		ListLength[layerToUpdate]--;

	}

}

void UpdateMgr::Update()
{
	for (int8_t layer = -128; layer < 127; layer++)
	{
		if (ListLength[layer] != 0)
		{
			for (int i = 0; i < ListLength[layer]; i++)
			{
				if (UpdateList[layer][i]->isActive())
				{
					UpdateList[layer][i]->Update();
				}
			}

		}
	}
}
