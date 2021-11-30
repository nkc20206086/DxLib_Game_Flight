#pragma once
#include<DxLib.h>
constexpr int KEY_MAX = 256;
using namespace DxLib;
class MyInput
{
private:
	//GameButtonE button;
	char key[KEY_MAX];
	char oldkey[KEY_MAX];
public:
	//MyInput(GameButtonE button);
	MyInput();
	~MyInput();
	//GameButtonE ReturnButton(char keystate[256]) { return button; };
	void SetInputState();
	void SetInputStateOld();
	bool GetKey(int v_key/*[KEY_MAX]*/);
	bool GetKeyDown(int v_key);
	bool GetKeyUp(int v_key);

};
enum GameButtonE
{
	WKEY, SKEY, AKEY, DKEY, EMPTY
};
//MyInput::MyInput(GameButtonE buttonInput)
//{
//	button = buttonInput;
//}
//MyInput::ReturnButton(char keystate[256])
//{
//	GameButtonE inputkeyNum;
//	if (keystate[KEY_INPUT_A])
//	{
//		inputkeyNum = EMPTY;
//	}
//	return button;
//}