#include "GameObject.h"

GameObject::GameObject()
{
	transform = new Transform(0, 0, this);
	pivot = Vector2(0.5f, 0.5f);
	texture =new LTexture();
	mRender = NULL;
	mAnimationClips = NULL;
	currentAnimation = 0;
	NofAnimations = 0;
	tileWidth =0;
	tileHeight=0 ;
	active = true;
	Components = nullptr;
	NofComponents = 0;
}

GameObject::~GameObject()
{
	Destroy();
}

void GameObject::Init(SDL_Renderer* Renderer)
{
	mRender = Renderer;
	UpdateMgr::Register(this); //Register the gameobject to the various managers
	DrawMgr::Register(this);


	transform->Start();
}

void GameObject::Update()
{
	if (NofAnimations > 0)
	{
		mAnimationClips[currentAnimation]->AnimationExecution();

	}



	transform->Update();
}

void GameObject::Draw()
{
	transform->OnDraw();


	SDL_Rect renderQuad = { transform->position.x,transform->position.y ,tileWidth,tileHeight }; //This is the quad where it will be rendered
	SDL_Rect TilesetFrame; //This is the frame on the tileset that will be rendered

	if (NofAnimations)
	{
		TilesetFrame = *mAnimationClips[currentAnimation]->GetFrame(); //get that frame from the animation

	}
	else
	{
		TilesetFrame = { 0, 0, texture->getWidth(),texture->getWidth() };
	}

	texture->render(&TilesetFrame, &renderQuad);  //and render it.


}

void GameObject::PlayAnimation()
{
	mAnimationClips[currentAnimation]->Play();
}

void GameObject::StopAnimation()
{
	mAnimationClips[currentAnimation]->Stop();

}


void GameObject::SwitchAnimation()
{
	StopAnimation();
	currentAnimation = (currentAnimation + 1) % NofAnimations;
	PlayAnimation();

}

void GameObject::AddAnimation(int startTileX, int startTileY, int EndTileX, int EndTileY, int FramesPerSecond)
{
	//OK SO. if i have to make an array of classes, i just need an array of pointers to that class.
	// IF i need to make this array dynamic, then the whole stuff is a pointer to class pointers
	//--->  Animation**, i have a dynamic array of pointers to animations 

	mAnimationClips = (Animation**)realloc(mAnimationClips, (NofAnimations + 1) * (sizeof(Animation*)));
	mAnimationClips[NofAnimations] = new Animation();
	mAnimationClips[NofAnimations]->SetAnimationClip(startTileX, startTileY, EndTileX, EndTileY, tileWidth, tileHeight, FramesPerSecond);

	NofAnimations++;
}

bool GameObject::LoadTexture(std::string TextureName)
{
	if (!texture->loadFrom(TextureName, mRender))
	{
		return false;
	}
	texture->setBlendMode(SDL_BLENDMODE_BLEND);
	tileWidth = texture->getWidth();
	tileHeight = texture->getHeight();


	return true;
}

bool GameObject::LoadTexture(std::string TextureName, int TileWidth, int TileHeight)
{
	if (!LoadTexture(TextureName))
	{
		return false;
	}
	tileWidth = TileWidth;
	tileHeight = TileHeight;
	texture->setTile(tileWidth, tileHeight);

	return true;
}

bool GameObject::isActive()
{
	return active;
}

bool GameObject::SetActive(bool activeState)
{
	active = activeState;
	return active;
}

void GameObject::Destroy()
{
	UpdateMgr::Remove(this);
	DrawMgr::Remove(this);
	mRender = NULL;
	texture->free();
}

void GameObject::UpdateLayer(int8_t layer)
{
	UpdateMgr::Remove(this);
	UpdateMgr::Register(this, layer);
}

void GameObject::DrawLayer(int8_t layer)
{
	DrawMgr::Remove(this);
	DrawMgr::Register(this, layer);
}

void GameObject::AddComponent(IComponent* Component)
{
	
	Components= (IComponent**)realloc(Components, (NofComponents +1 ) * sizeof(IComponent*));
	Components[NofComponents] = Component;
	NofComponents++;
}

void GameObject::DetachComponent(IComponent* Component)
{

	IComponent** f;
	f = (IComponent**)malloc((NofComponents) * sizeof(IComponent*));
	int j=0;
	for (int i = 0; i < NofComponents; i++)
	{
		if (Components[i] == Component)
		{
			continue;
		}
		f[j] = Components[i];
		j++;
	}
	Components = f;
	f = nullptr;
}
