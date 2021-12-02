#pragma once
#include <vector>
#include <map>
#include "GameObject.h"
#include<DxLib.h>
#include"ColliderSet.h"

class Collider:public Compornent
{
private:

public:
	std::vector<int> HitObjDataNum;
	ColliderSet thisCollision;
	//最初に呼ぶやつ　当たり判定の値を登録する
	void SetCollisionObj(VECTOR vec, float lenge);

	
	//初期化
	//void ResetCollisionObj();

	////Whileで呼ぶやつ　当たり判定の計算
	//int CalculateCollision();

};
