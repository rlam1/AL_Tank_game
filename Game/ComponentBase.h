#pragma once
#include "Vec.h"
#include "componentType.h"

class ComponentBase {
public:
	ComponentBase();
	virtual ~ComponentBase();
	virtual void Update() = 0;
	virtual void Init() = 0;

	bool IsAlive();
	int GetComponentType();
protected:
	int componentType;
	bool isAlive;
};

