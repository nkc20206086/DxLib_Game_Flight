#include"inputTest.h"
//ここでMyInputの定義を行う
MyInput::MyInput()//コンストラクタ
{
	for (int i = 0; i < KEY_MAX; i++)
	{
		key[0] = 0;
		oldkey[0] = 0;
	}
}
MyInput::~MyInput()//デストラクタ
{
}
void MyInput::SetInputState()//これを最初に呼ぶ
{
	GetHitKeyStateAll(key); //keyにインプットの値を入れる
}
void MyInput::SetInputStateOld()//最後に呼ぶ
{
	for (int i = 0; i < KEY_MAX; ++i)
	{
		oldkey[i] = key[i];
	}
}

//こういうインプットがあるといいね
bool MyInput::GetKey(int v_key/*[KEY_MAX]*/)//引数は押されたか確認したいキーの番号
{
	return key[v_key] == 1 ? true : false;
}
bool MyInput::GetKeyDown(int v_key)
{
	if (key[v_key] == 0) return false;
	return (oldkey[v_key] == 0) ? true : false;
}
bool MyInput::GetKeyUp(int v_key)
{
	if (key[v_key] == 1) return false;
	return (oldkey[v_key] == 1) ? true : false;
}