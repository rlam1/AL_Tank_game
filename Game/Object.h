#pragma once
#include <string>

#include "ComponentManager.h"

class Object {
public:
	Object(Vec2D position);
	virtual ~Object();

	virtual void Update();
	bool AddComponent(ComponentBase* component);

protected:
	Vec2D position;
	std::string configFilePath;
	ComponentManager componentList;
	std::string name;
};

