#include "PhysicsComponent.h"


PhysicsComponent::PhysicsComponent(Vec2D pos, Vec2D siz, Vec2D sped, bool collid)
{
	position = pos;
	size = siz;
	speed = sped;
	collidable = collid;

	hasCollision = false;

	componentType = COMP_PHYSICS;
}


PhysicsComponent::~PhysicsComponent()
{
}


void PhysicsComponent::Update()
{
	if (!hasCollision)
	{
		position = position + speed;
	}

}

void PhysicsComponent::Init()
{
	isAlive = true;
}


bool PhysicsComponent::isCollided(PhysicsComponent* obj2)
{
	if (collidable && isAlive)
	{
		Vec2D obj2Position = obj2->GetPosition();
		Vec2D obj2Size = obj2->GetSize();
		float x1, x2, y1, y2, w1, w2, h1, h2;

		x1 = position.x;
		y1 = position.y;
		x2 = obj2Position.x;
		y2 = obj2Position.y;

		w1 = x1 + size.x;
		h1 = y1 + size.y;
		w2 = x2 + obj2Size.x;
		h2 = y2 + obj2Size.y;

		if (w1 > x2 || w2 < x1 && y1 < h2 || y2 < h1)
		{
			hasCollision = true;
		} else
		{
			hasCollision = false;
		}
	} else  // Object is not collidable or is still not init
	{
		hasCollision = false;
	}

	return hasCollision;
}


Vec2D PhysicsComponent::GetPosition()
{
	return position;
}


Vec2D PhysicsComponent::GetSize()
{
	return size;
}


Vec2D PhysicsComponent::GetSpeed()
{
	return speed;
}

/*
	TODO:

	Add a way to see if you want to change the
	speed to X (actual function), increase it 
	by X or decrease it by X.
*/
void PhysicsComponent::SetSpeed(Vec2D speed)
{
	this->speed = speed;
}
