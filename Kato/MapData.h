#pragma once
#include "DxLib.h"

// �}�b�v�I�u�W�F�N�g�̃��f���̎��
enum ObjectType
{
	Cube = 0,
	Sphere = 1,
	Count,
};

// �}�b�v�I�u�W�F�N�g�̍\����
typedef struct
{
	int modelHandle;			// ���f���n���h��
	ObjectType modelType;		// ���f���̎��
	VECTOR position;			// ���f���̍��W
	VECTOR rotation;			// ���f���̉�]
	VECTOR scale;				// ���f���̊g�k
}MAP_OBJECT;




// �}�b�v�I�u�W�F�N�g�̑���
static const int OBJECT_NUM = 9;

MAP_OBJECT objects[OBJECT_NUM] =
{
	{0, Cube, VGet(1052.0f, 472.0f, 146.0f), VGet(0.0f, 0.0f, 0.0f), VGet(2.0f, 2.0f, 2.0f)},
	{0, Sphere, VGet(74.0f, 398.0f, -436.0f), VGet(0.0f, 0.0f, 0.0f), VGet(2.0f, 2.0f, 2.0f)},
	{0, Sphere, VGet(398.0f, -270.0f, -488.0f), VGet(0.0f, 0.0f, 0.0f), VGet(1.0f, 1.0f, 1.0f)},
	{0, Sphere, VGet(-294.0f, -196.0f, 360.0f), VGet(0.0f, 0.0f, 0.0f), VGet(2.0f, 2.0f, 2.0f)},
	{0, Cube, VGet(-680.0f, -104.0f, -52.0f), VGet(0.0f, 0.0f, 0.0f), VGet(1.0f, 1.0f, 1.0f)},

	{0, Cube, VGet(-520.0f, 74.0f, 310.0f), VGet(0.0f, 0.0f, 0.0f), VGet(1.0f, 1.0f, 1.0f)},
	{0, Cube, VGet(-212.0f, -240.0f, -308.0f), VGet(0.0f, 0.0f, 0.0f), VGet(1.0f, 1.0f, 1.0f)},
	{0, Cube, VGet(150.0f, 246.0f, 582.0f), VGet(0.0f, 0.0f, 0.0f), VGet(1.0f, 1.0f, 1.0f)},
	{0, Cube, VGet(550.0f, 220.0f, -92.0f), VGet(0.0f, 0.0f, 0.0f), VGet(1.0f, 1.0f, 1.0f)},
};