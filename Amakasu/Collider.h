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
	//�ŏ��ɌĂԂ�@�����蔻��̒l��o�^����
	void SetCollisionObj(VECTOR vec, float lenge);

	
	//������
	//void ResetCollisionObj();

	////While�ŌĂԂ�@�����蔻��̌v�Z
	//int CalculateCollision();

};
