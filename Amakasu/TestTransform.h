#pragma once
#include <DxLib.h>
#include"TestGameObject.h"
class TestTransform
{
public:
	TestTransform();
	~TestTransform();

private:
	VECTOR position;
	VECTOR rotation;
	VECTOR scale;
};

TestTransform::TestTransform()
{
}

TestTransform::~TestTransform()
{
}