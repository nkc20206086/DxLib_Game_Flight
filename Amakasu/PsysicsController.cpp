#include"PsysicsController.h"

void Psysics::SetCollisionObj(GameObject& obj)
{
	//�����蔻�肷��I�u�W�F�N�g�̃R���C�_�[�ݒ���擾
	Collider* ptr = &obj.GetCompornent<Collider>();
	
	//�o�^����Ă��Ȃ������ꍇ�쐬
	if (CollisionDic.find(ptr->thisCollision.id) != CollisionDic.end())
	{
		//�����蔻�肷��I�u�W�F�N�g��id��ݒ�
		ptr->thisCollision.id = ColCount;

		//�v�Z�p�ɓo�^
		CollisionDic[ColCount] = ptr;
		CollisionDic.insert(std::pair<int, Collider*>(ColCount, ptr));
		//���������I�u�W�F�N�g��Ԃ����߂ɃI�u�W�F�N�g��o�^
		CollisionGameObjectDic[ColCount] = &obj;
		CollisionGameObjectDic.insert(std::pair<int, GameObject*>(ColCount, &obj));
		ColCount++;
	}
}
GameObject& Psysics::GetCollisionObj(int id)
{
	return  *CollisionGameObjectDic[id];

}
void Psysics::DelateCollision(GameObject& obj)
{

	Collider& ptr = obj.GetCompornent<Collider&>();
	//���������Q�[���I�u�W�F�N�g��ID���擾
	int num = ptr.thisCollision.id;
	CollisionDic.erase(num);
	CollisionGameObjectDic.erase(num);
}
void Psysics::CalculateCollision()
{
	//�v�Z�O�ɃI�u�W�F�N�g�̓����蔻��t���O�����Z�b�g����
	for (unsigned int i = 0; CollisionDic.size() >= i; i++)
	{
		CollisionDic[i]->HitObjDataNum.clear();
	}

	for (int i = CollisionDic.size(); i > 0; --i)
	{
		//��ׂ�I�u�W�F�N�g
		mainCol = CollisionDic[i]->thisCollision;

		for (int j = 0; j < i; ++j)
		{
			sabuCol = CollisionDic[j]->thisCollision;
			//�����蔻��v�Z
			if
				(
					(sabuCol.colvec.x - mainCol.colvec.x) *
					(sabuCol.colvec.x - mainCol.colvec.x)
					+
					(sabuCol.colvec.y - mainCol.colvec.y) *
					(sabuCol.colvec.y - mainCol.colvec.y)
					+
					(sabuCol.colvec.z - mainCol.colvec.z) *
					(sabuCol.colvec.z - mainCol.colvec.z)
					<=
					sabuCol.lange + mainCol.lange
					*
					sabuCol.lange + mainCol.lange
					)
			{
				//Collision�Ŏ󂯎�肽������Gameobject�o�^���Ă�������
				CollisionGameObjectDic[j]->HitObj.push_back(CollisionGameObjectDic[i]);

				CollisionGameObjectDic[i]->HitObj.push_back(CollisionGameObjectDic[j]);
			}

		}
	}
}