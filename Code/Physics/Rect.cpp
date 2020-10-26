#include "Rect.h"

Rect::Rect(Vector2 offset, Rigidbody* rb, float width, float height) : Shape(offset, rb)
{
	Width = width;
	Height = height;

}

float Rect::GetWidth()
{
	return Width;
}

float Rect::GetHeight()
{
	return Height;
}

float Rect::GetHalfWidth()
{
	return Width*0.5f;
}

float Rect::GetHalfHeight()
{
	return Height*0.5f;
}

bool Rect::Contains(Vector2 point)
{
	return point.x >= GetPosition().x - Width*0.5f && point.x <= GetPosition().x + Width * 0.5f &&
		point.y <= GetPosition().y + Height * 0.5f && point.y >= GetPosition().y - Height * 0.5f;
}

Vector2 Rect::GetRelativeYaxis()
{
	Vector2 TopPoint = GetPosition() - rigidBody->GetTransform()->Up() * GetHalfHeight();
	Vector2 BottomPoint = GetPosition() + rigidBody->GetTransform()->Up() * GetHalfHeight();
	
	return (TopPoint - BottomPoint).Normalized();
}

Vector2 Rect::GetRelativeXaxis()
{
	Vector2 RightPoint = GetPosition() + rigidBody->GetTransform()->Forward() * GetHalfWidth();
	Vector2 LeftPoint = GetPosition() - rigidBody->GetTransform()->Forward() * GetHalfWidth();

	return (RightPoint - LeftPoint).Normalized();
}

Projection Rect::ProjectRect(Vector2 Axis)
{
	float minMagnitude = 10000.;
	float maxMagnitude = -10000.;
	Projection pr = Projection();
	Vector2 Points[]{
		GetPosition() + rigidBody->GetTransform()->Forward() * GetHalfWidth() + rigidBody->GetTransform()->Up()*GetHalfHeight(),
		GetPosition() - rigidBody->GetTransform()->Forward() * GetHalfWidth() + rigidBody->GetTransform()->Up()*GetHalfHeight(),
		GetPosition() + rigidBody->GetTransform()->Forward() * GetHalfWidth() - rigidBody->GetTransform()->Up()*GetHalfHeight(),
		GetPosition() - rigidBody->GetTransform()->Forward() * GetHalfWidth() - rigidBody->GetTransform()->Up()*GetHalfHeight(),
	};
	for (int i = 0; i < 4; i++)
	{
		float projection = Vector2::DotProduct(Points[i], Axis);
		if(projection > maxMagnitude){
			maxMagnitude = projection;
			pr.max =  projection;
		}
		if (projection < minMagnitude)
		{
			minMagnitude = projection;
			pr.min =  projection;
		}
	}
	return pr;
}





bool Rect::Collides(Rect* other)
{
	Vector2 axes[] = { this->GetRelativeXaxis(), this->GetRelativeYaxis(), other->GetRelativeXaxis(), other->GetRelativeYaxis() };
	for (int i = 0; i < 4; i++)
	{
		Vector2 axis = axes[i];
		Projection ThisRect = this->ProjectRect(axis);
		Projection OtherRect = other->ProjectRect(axis);

		if (ThisRect.min < OtherRect.min)
		{
			if (ThisRect.max < OtherRect.min)//No collision
			{
				return false;
			}
		}
		else if(ThisRect.min > OtherRect.min)
		{
			if (OtherRect.max < ThisRect.min)// No Collision
			{
				return false;
			}
		}
	}
	return true;
}

