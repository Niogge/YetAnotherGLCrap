#pragma once
#ifndef CMOVEMENT_H
#define CMOVEMENT_H

#include"..\CoreInclude.h"

class CMovement : public IComponent
{
public:
	CMovement();
	~CMovement();
	virtual void Start();
	virtual void Update();
	virtual void OnDraw();
	virtual void OnDetach();
	virtual void OnCollision(Rect* other);
	void SetSpeed(float s);
private:
	virtual std::string getType() { return typeid(this).name(); }
	Vector2 direction;
	float speed;
	int childCount;
};


#endif // !CMOVEMENT_H
