#include"ring.h"

bool Ring::SetRingModelHandle(const TCHAR* ModelName)
{
	Modelhandle = MV1LoadModel(ModelName);
	return true;
}
void Ring::DrawRing()
{
	MV1DrawModel(Modelhandle);
}
void Ring::SetRingPos(VECTOR vec)
{
	//objvec = vec;
	MV1SetPosition(Modelhandle, vec);

}