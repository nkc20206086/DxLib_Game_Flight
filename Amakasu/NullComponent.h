#pragma once
#include"Compornent.h"
#include "DxLib.h"
class NullCompornent :public Compornent
{
public:
	inline void DrawTest()
	{
		DrawString(250, 240 - 32, "NullReferenceException ", 0);
	}
};