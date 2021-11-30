#include"Player.h"
bool Player::SetPlayerModelHandle(const TCHAR* modelname)
{
	Modelhandle = MV1LoadModel(modelname);
	return true;
}
void Player::PlayerSetPos(VECTOR vec)
{
	Transform* temp = (Transform*)comp[0];

	MV1SetPosition(Modelhandle, vec);

}
//void Player::DrawPlayer()
//{
//	MV1DrawModel(Modelhandle);
//}
//void Player::PlayerPositionAdd(VECTOR vec)
//{
//	objvec = VAdd(objvec, vec);
//}