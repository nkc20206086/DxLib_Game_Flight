#pragma once
#include <vector>
#include <map>
#include "GameObject.h"
#include<DxLib.h>
#include"ColliderSet.h"

class Collider :public Compornent
{
private:

public:
	std::vector<int> HitObjDataNum;
	ColliderSet thisCollision;
	//Å‰‚ÉŒÄ‚Ô‚â‚Â@“–‚½‚è”»’è‚Ì’l‚ğ“o˜^‚·‚é
	void SetCollisionSetting(VECTOR vec, float lenge);

};
