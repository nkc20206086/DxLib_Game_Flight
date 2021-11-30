#pragma once
#include<DxLib.h>
#include<vector>
#include<typeinfo>

#include"Transform.h"
#include"Compornent.h"
#include"CompornentType.h"
#include"NullComponent.h"

//�R���|�[�l���g�̖��O�@���ꂵ���v�����񂩂���
//�����ŃR���C�_�[��m�肽���Ȃ�

class GameObject
{
public:
	GameObject();

	//�w�肳�ꂽ�R���|�[�l���g���Z�b�g
	int AddCompornent(CompornentType target);
	//�`��֌W
	bool SetModelHandle(const TCHAR* ModelName);
	void DrawObject();

	//�R���|�[�l���g�����p�̔z��
	Compornent* comp[3];

	std::vector<GameObject> HitObj;

	//�����̎����Ă���R���|�[�l���g�𑗂����
	template<typename T>
	T& GetCompornent() {
		for (int i = 0; i < 3; i++)
		{
			if (typeid(T) == typeid(comp[i]) ) {
				return (T&)comp[i];
			}
		}
		return (T&)comp[0];
		//�����ꍇ�@�G���[�Ԃ�����
		
	}


private:
	//�����蔻��Ǘ��p�ԍ�
	//int collisionNum;
//	bool ishit;
	int modelhandle;

	//Transform _transform;
};
