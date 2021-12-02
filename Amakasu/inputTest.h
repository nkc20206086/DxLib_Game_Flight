#pragma once
#include<DxLib.h>
constexpr int KEY_MAX = 256;
using namespace DxLib;
class MyInput
{
private:
	char key[KEY_MAX];
	char oldkey[KEY_MAX];
public:
	MyInput();
	~MyInput();
	void SetInputState();
	void SetInputStateOld();
	bool GetKey(int v_key);
	bool GetKeyDown(int v_key);
	bool GetKeyUp(int v_key);

};

