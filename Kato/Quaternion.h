#pragma once
#include "DxLib.h"
#include <math.h>

typedef struct 
{
	double x;
	double y;
	double z;
	double w;
}QUATERNION;

class Quaternion
{
public:
	// ��]������\��
	QUATERNION Identity()
	{
		QUATERNION q;
		q.x = 0.0;
		q.y = 0.0;
		q.z = 0.0;
		q.w = 1.0;
		return q;
	};

	// ��]�N�H�[�^�j�I��
	// ���� Vec3 axis �� double radian ��]����
	QUATERNION RotationQuaternion(double radian, VECTOR axis)
	{
		QUATERNION q;		// �N�H�[�^�j�I��
		double normalize;	// VECTOR axis �𐳋K�����邽�߂Ɏg�p
		double s, c;		// sin cos 

		q.x = q.y = q.z = q.w = 0.0;

		// x^2 + y^2 + z^2 + w^2
		normalize = axis.x * axis.x + axis.y * axis.y + axis.z * axis.z;

		// 0�ȉ���q(Identity�l�A���Ԃ񖳉�])��Ԃ�

		if (normalize <= 0.0)	return Identity();

		// �������Ɛ��K���̏���
		normalize = 1.0 / sqrt(normalize);
		axis.x *= normalize;
		axis.y *= normalize;
		axis.z *= normalize;

		// sin(theta/2)��cos(theta/2)���v�Z
		s = sin(0.5 * radian);
		c = cos(0.5 * radian);

		q.x = s * axis.x;
		q.y = s * axis.y;
		q.z = s * axis.z;
		q.w = c;

		return q;
	};

	// �N�H�[�^�j�I�������]�s��ϊ����g�p
	MATRIX QuaternionToMatrix(QUATERNION q)
	{
		MATRIX mat = MGetIdent();

		// X��
		mat.m[0][0] = 1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z;
		mat.m[0][1] = 2.0f * q.x * q.y + 2.0f * q.w * q.z;
		mat.m[0][2] = 2.0f * q.x * q.z - 2.0f * q.w * q.y;

		// Y��
		mat.m[1][0] = 2.0f * q.x * q.y - 2.0f * q.w * q.z;
		mat.m[1][1] = 1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z;
		mat.m[1][2] = 2.0f * q.y * q.z + 2.0f * q.w * q.x;

		// Z��
		mat.m[2][0] = 2.0f * q.x * q.z + 2.0f * q.w * q.y;
		mat.m[2][1] = 2.0f * q.y * q.z - 2.0f * q.w * q.x;
		mat.m[2][2] = 1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y;

		return mat;
	};

	// �N�H�[�^�j�I�����m�̓���
	float Dot(QUATERNION q1, QUATERNION q2)
	{
		return q1.x* q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;
	};

	//float Angle(QUATERNION q1, QUATERNION q2);


private:
	const float epsilon = 0.000001f;	//	�C�v�V����(��)�ɏ��̒l
};

// �N�H�[�^�j�I�����N�H�[�^�j�I���Awiki�Ȃ�n�~���g���ςƓ��`���Ǝv���B(���Ԃ�)
// lhs * rhs != rhs * lhs
QUATERNION operator*(QUATERNION lhs, QUATERNION rhs)
{
	QUATERNION q;
	q.x = lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y;
	q.y = lhs.w * rhs.y + lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z;
	q.z = lhs.w * rhs.z + lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x;
	q.w = lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z;
	return q;
};

// �N�H�[�^�j�I����VECTOR���g����VECTOR��Ԃ�
VECTOR operator*(QUATERNION rotation, VECTOR point)
{
	float x = rotation.x * 2.0f;
	float y = rotation.y * 2.0f;
	float z = rotation.z * 2.0f;
	float xx = rotation.x * x;
	float yy = rotation.y * y;
	float zz = rotation.z * z;
	float xy = rotation.x * y;
	float xz = rotation.x * z;
	float yz = rotation.y * z;
	float wx = rotation.w * x;
	float wy = rotation.w * y;
	float wz = rotation.w * z;

	VECTOR v;
	v.x = (1.0f - (yy + zz)) * point.x + (xy - wz) * point.y + (xz + wy) * point.z;
	v.y = (xy + wz) * point.x + (1.0f - (xx + zz)) * point.y + (yz - wx) * point.z;
	v.z = (xz - wy) * point.x + (yz + wx) * point.y + (1.0f - (xx + yy)) * point.z;
	return v;
};



