#pragma once
#include <vector>
#include <map>
#include "GameObject.h"
#include<DxLib.h>
#include"ColliderSet.h"

class Collider :public Compornent
{
private:

public:
	std::vector<GameObject*> HitObjDataNum;
	ColliderSet thisCollision;
	//最初に呼ぶやつ　当たり判定の値を登録する
	void SetCollisionSetting(VECTOR vec, float lenge);

};
