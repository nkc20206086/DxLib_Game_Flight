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
	std::vector<int> HitObjDataNum;
	ColliderSet thisCollision;
	//�ŏ��ɌĂԂ�@�����蔻��̒l��o�^����
	void SetCollisionSetting(VECTOR vec, float lenge);

};
