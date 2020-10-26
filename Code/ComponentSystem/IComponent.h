#pragma once
#ifndef ICOMPONENT_H
#define ICOMPONENT_H
#include "..\CoreInclude.h"
class Rect;
class IComponent
{
private: 
	friend class GameObject;
	bool isActive = true ;
	virtual std::string getType() = 0;

public:
	virtual void Start() = 0;
	virtual void Update()=0 ;
	virtual void OnDraw()=0;
	virtual void OnDetach() = 0;
	virtual void OnCollision(Rect * other) = 0;
	GameObject* gameObject;
	virtual bool IsActive() { return isActive; };
	virtual bool SetActive(bool active) { isActive = active; return isActive; };
};

#endif // !ICOMPONENT_H
