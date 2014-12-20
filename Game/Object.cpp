#include "Object.h"


Object::Object(Vec2D position)
{
	this->position = position;
}


Object::~Object()
{
}


void Object::Update()
{
	componentList.Update();
}


bool Object::AddComponent(ComponentBase* component)
{
	// Checks if component type is already part of
	return componentList.AddComponent(component);
}
