#pragma once
#include "ComponentBase.h"

class PhysicsComponent :
	public ComponentBase {
public:
	PhysicsComponent(Vec2D pos, Vec2D siz, Vec2D sped, bool collid);
	virtual ~PhysicsComponent();

	virtual void Update() final;
	virtual void Init() final;

	bool isCollided(PhysicsComponent* obj2);

	Vec2D GetPosition();
	Vec2D GetSize();
	Vec2D GetSpeed();

	void SetSpeed(Vec2D speed);
private:
	Vec2D position;
	Vec2D size;
	Vec2D speed;
	bool collidable;
	bool hasCollision;
};

