#include "GameObject.h"

GameObject::GameObject()
{
	position = Vector2(0, 0);
	pivot = Vector2(0.5f, 0.5f);
	texture =new LTexture();
	mRender = NULL;
	mAnimationClips = NULL;
	currentAnimation = 0;
	NofAnimations = 0;
	tileWidth =0;
	tileHeight=0 ;

}

GameObject::~GameObject()
{
	Destroy();
}

void GameObject::Init(SDL_Renderer* Renderer)
{
	mRender = Renderer;
	UpdateMgr::Register(this ); //Register the gameobject to the various managers
	DrawMgr::Register(this);
}

void GameObject::Update()
{
	mAnimationClips[currentAnimation]->AnimationExecution();
}

void GameObject::Draw()
{
	SDL_Rect renderQuad = { position.x ,position.y ,tileWidth,tileHeight }; //This is the quad where it will be rendered
	SDL_Rect TilesetFrame; //This is the frame on the tileset that will be rendered


	TilesetFrame = *mAnimationClips[currentAnimation]->GetFrame(); //get that frame from the animation

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

bool GameObject::LoadTexture(std::string path)
{
	if (!texture->loadFrom(path, mRender))
	{
		return false;
	}
	texture->setBlendMode(SDL_BLENDMODE_BLEND);

	return true;
}

bool GameObject::LoadTexture(std::string path, int TileWidth, int TileHeight)
{
	if (!LoadTexture(path))
	{
		return false;
	}
	tileWidth = TileWidth;
	tileHeight = TileHeight;
	texture->setTile(tileWidth, tileHeight);

	return true;
}

void GameObject::Destroy()
{
	UpdateMgr::Remove(this);
	DrawMgr::Remove(this);
	mRender = NULL;
	texture->free();
}

void GameObject::Move(Vector2 dir)
{
	if (dir.x < 0)
	{
		texture->flipX  = true;
	}
	else
	{
		texture->flipX = false;
	}
	position = Vector2(position.x + dir.x, position.y + dir.y);
	//std::cout << position.x << std::endl;
}
