#pragma once
#include "ComponentBase.h"

#include "Sprite.h"

class RenderComponent :
	public ComponentBase {
public:
	RenderComponent();
	virtual ~RenderComponent();

	virtual void Update();
	virtual void Init();
private:
	Sprite renderObject;
	Vec2D position;
	Vec2D renderSize;
	Vec2D clipOrigin;

	void GetPosition();
};

