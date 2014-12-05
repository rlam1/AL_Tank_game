#pragma once
#include <list>

#include "ComponentBase.h"

class ComponentManager {
public:
	ComponentManager();
	~ComponentManager();

	void Update();
	bool AddComponent(ComponentBase* component);
	ComponentBase* GetComponentByType(int componentType);

private:
	std::list<ComponentBase*> componentList;
	bool active;
};

