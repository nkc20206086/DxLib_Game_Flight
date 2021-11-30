#pragma once
#include"GameObject.h"
#include<DxLib.h>
using namespace std;
class  Player: public GameObject
{
public:
	inline Player();
	inline ~ Player();
	bool SetPlayerModelHandle(const TCHAR* ModelName);
	void DrawPlayer();
	void PlayerSetPos(VECTOR vector);
	void PlayerPositionAdd(VECTOR vec);
private:
	int Modelhandle;
	
};

 Player:: Player()
{
	 Modelhandle = 0;
	 //絶対トランスフォーム持っていて欲しい
	 Compornent* temp = new Transform();
	 comp[0] = temp;
	 delete(temp);
}

 Player::~ Player()
{
	 delete(this);
}