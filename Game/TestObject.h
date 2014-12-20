#pragma once
#include "Object.h"
class TestObject :
	public Object {
public:
	TestObject(Vec2D position) : Object(position) {} ;
	~TestObject();
};

