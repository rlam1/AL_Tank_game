#include "ComponentBase.h"


ComponentBase::ComponentBase()
{
	componentType = COMP_GENERIC;
	isAlive = false;
}


ComponentBase::~ComponentBase()
{
}


bool ComponentBase::IsAlive()
{
	return isAlive;
}


int ComponentBase::GetComponentType()
{
	return componentType;
}
