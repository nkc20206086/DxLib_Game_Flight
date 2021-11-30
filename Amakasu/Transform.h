#pragma once
#include"Compornent.h"
#include"DxLib.h"
class Transform:public Compornent
{
public:
	inline Transform();
	inline ~Transform();
	VECTOR position;
	VECTOR rotation;
	VECTOR scale;
};
Transform::Transform()
{
	compornentname = CompornentType::Transform;
	position = VGet(0, 0, 0);
	rotation = VGet(0, 0, 0);
	scale = VGet(0, 0, 0);
}
Transform::~Transform()
{
	delete(this);
}