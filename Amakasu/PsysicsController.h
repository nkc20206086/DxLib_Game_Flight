#pragma once
#include "Collider.h"
#include"GameObject.h"
#include"ColliderSet.h"
#include"DxLib.h"
class Psysics
{
public:
	Psysics();
	~Psysics();

	//�����蔻�������I�u�W�F�N�g��ۑ����Ă���
	std::map<int,Collider&>CollisionDic;
	std::map<int,GameObject&>CollisionGameObjectDic;

	
	//���C�����[�v�ōŏ��ɌĂԁB�@�����蔻�肷��z��o�^����
	void SetCollisionObj(GameObject& obj);
	//GameObject& GetCollisionObj(int id);
	void DelateCollision(GameObject& obj);
	//�����蔻����v�Z����
	void CalculateCollision();

	
	int ColCount;
private:
	ColliderSet mainCol;
	ColliderSet sabuCol;

	VECTOR MainTrans;
	VECTOR SabuTrans;

	
};

Psysics::Psysics()
{
	MainTrans = VGet(0, 0, 0);
	SabuTrans = VGet(0, 0, 0);
	ColCount = 0;
	
	mainCol.colvec = VGet(0, 0, 0);
	mainCol.id = 0;
	mainCol.lange = 0;
	
	sabuCol.colvec = VGet(0, 0, 0);
	sabuCol.id = 0;
	sabuCol.lange = 0;

	
	//CollisionGameObjectDic = { {0,nullptr} };
}

Psysics::~Psysics()
{
	delete(this);
}