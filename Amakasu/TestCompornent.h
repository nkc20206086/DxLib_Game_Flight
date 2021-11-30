#pragma once
#include "TestTransform.h"
#include "TestCollider.h"
class TestCompornent
{
public:
	TestCompornent();
	~TestCompornent();

	TestTransform transform;
	TestTransform GetTransform() { return transform; };

private:

};

TestCompornent::TestCompornent()
{
}

TestCompornent::~TestCompornent()
{
}