#pragma once
#include <DxLib.h>
class  TestGameObject
{
public:
	TestGameObject();
	~TestGameObject();
	void SetModel(const char* name);
	void DrawObject();
private:
	int modelhandle;
};

TestGameObject::TestGameObject()
{
}

TestGameObject::~TestGameObject()
{

}