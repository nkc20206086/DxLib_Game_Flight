#pragma once
#include "GameObject.h"
#include<DxLib.h>
class Ring :public GameObject
{
public:
	bool SetRingModelHandle(const TCHAR* ModelName);
	void DrawRing();
	void SetRingPos(VECTOR vec);
private:
	int Modelhandle;
};