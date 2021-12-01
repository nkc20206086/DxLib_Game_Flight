#pragma once
#include"Compornent.h"
#include"DxLib.h"
class Transform :public Compornent
{
public:
	inline Transform();
	inline ~Transform();
	inline void AddPos(float x, float y, float z);
	inline void AddRotate(float x, float y, float z);
	inline void AddScale(float x, float y, float z);

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
void Transform::AddPos(float x, float y, float z)
{
	position.x += x;
	position.y += y;
	position.z += z;
}
void Transform::AddRotate(float x, float y, float z)
{
	rotation.x += x;
	rotation.y += y;
	rotation.z += z;
}
void Transform::AddScale(float x, float y, float z)
{
	scale.x += x;
	scale.y += y;
	scale.z += z;
}