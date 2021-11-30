#include"GameObject.h"

GameObject::GameObject()
{
	//Compornent配列の初期化
	for (int i = 0; i < sizeof(comp) / sizeof(*comp); i++)
	{
		comp[i] = nullptr;
	}

	Compornent* TempNull = new NullCompornent();
	comp[0] = TempNull;

	//絶対トランスフォーム持っていて欲しい
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
	//すでに持っていないか確認
	for (int i = 0; i < sizeof(comp); i++)
	{
		if (target == comp[i]->compornentname)
		{
			return -1;
		}
	}
	//無い場合生成
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
