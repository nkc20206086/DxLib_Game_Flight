#include"GameObject.h"

GameObject::GameObject()
{
	//Compornent�z��̏�����
	for (int i = 0; i < sizeof(comp) / sizeof(*comp); i++)
	{
		comp[i] = nullptr;
	}

	Compornent* TempNull = new NullCompornent();
	comp[0] = TempNull;

	//��΃g�����X�t�H�[�������Ă��ė~����
	Compornent* tempT = new Transform();
	comp[1] = tempT;
	modelhandle = 0;
}

bool GameObject::SetModelHandle(const TCHAR* modelname)
{
	if (modelhandle == NULL)
	{
		modelhandle = MV1LoadModel(modelname);
		return true;
	}
	return false;

}
void GameObject::DrawObject()
{
	Transform* temp = (Transform*)comp[0];
	MV1SetPosition(modelhandle, temp->position);
	MV1DrawModel(modelhandle);
	delete(temp);
}
int GameObject::AddCompornent(CompornentType target)
{
	//���łɎ����Ă��Ȃ����m�F
	for (int i = 0; i < sizeof(comp); i++)
	{
		if (target == comp[i]->compornentname)
		{
			return -1;
		}
	}
	//�����ꍇ����
	Compornent* temp = NULL;
	switch (target)
	{
	case CompornentType::Transform:

		temp = new Transform();
		comp[0] = temp;
		break;
	case CompornentType::CurcleCollider:
		temp = new Compornent();
		comp[1] = temp;
		break;
	}
	delete(temp);
	return 1;
}
