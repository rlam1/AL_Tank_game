#include "ComponentManager.h"


ComponentManager::ComponentManager()
{
	active = false;
}


ComponentManager::~ComponentManager()
{
}


void ComponentManager::Update()
{
	for (const auto& comp : componentList)
	{
		comp->Update();
	}
}


bool ComponentManager::AddComponent(ComponentBase* component)
{
	if (!active)
	{
		active = true;
		
		componentList.push_back(component);
		return true;
	} else
	{
		int newCompType = component->GetComponentType();

		for (const auto& i : componentList)
		{
			if (newCompType == i->GetComponentType())
				return false;
		}

		// There is no comp of that type already on the manager
		componentList.push_back(component);
		return true;
	}
}


ComponentBase* ComponentManager::GetComponentByType(int componentType)
{
	if (active)
	{
		for (const auto& i : componentList)
		{
			if (i->GetComponentType() == componentType)
				return i;
		}

		//Component of that type was not found
		return nullptr;

	} else
		return nullptr;
}
