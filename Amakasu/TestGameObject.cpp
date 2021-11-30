#include"TestGameObject.h"
void TestGameObject::SetModel(const char* modelname)
{
	modelhandle= MV1LoadModel(modelname);
}

void TestGameObject::DrawObject()
{
	MV1DrawModel(modelhandle);
}

