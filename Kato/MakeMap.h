#pragma once
#include "DxLib.h"
#include "MapData.h"

class MakeMap
{
private:
	int cubeHandle = 0;		// Box�̃��f���n���h��
	int sphereHandle = 0;	// Sphere�̃��f���n���h��

	// ���f���n���h�����ɑS�����[�h����
	void FirstTimeModelLoad()
	{
		cubeHandle = MV1LoadModel("Cube.mv1");
		sphereHandle = MV1LoadModel("Sphere.mv1");
	}

	// �n���h�����擾
	int GetObjectsHandle(ObjectType type)
	{
		int handleNum = 0;
		switch (type)
		{
		case Cube: handleNum = cubeHandle;	break;
		case Sphere: handleNum = sphereHandle; break;
		default: printfDx("���f�����o�^����ĂȂ��B\n"); break;
		}
		return handleNum;
	}

	// �n���h����ݒ�
	void SetMapObjectsHandle()
	{
		// ���f����S�����[�h
		FirstTimeModelLoad();

		for (int i = 0; i < OBJECT_NUM; i++)
		{
			objects[i].modelHandle = MV1DuplicateModel(GetObjectsHandle(objects[i].modelType));
		}
	}

public:

	// Map�ɔz�u���ׂ����f����z�u
	void SettingMapObjects()
	{
		// �n���h����ݒ�
		SetMapObjectsHandle();

		for (int i = 0; i < OBJECT_NUM; i++)
		{
			// ���W�A��]�A�g�k���擾
			VECTOR objectPosition = VGet(objects[i].position.x, objects[i].position.y, objects[i].position.z);
			VECTOR objectRotation = VGet(objects[i].rotation.x, objects[i].rotation.y, objects[i].rotation.z);
			VECTOR objectScale = VGet(objects[i].scale.x, objects[i].scale.y, objects[i].scale.z);

			// ���W�A��]�A�g�k��K�p
			MV1SetPosition(objects[i].modelHandle, objectPosition);
			MV1SetRotationXYZ(objects[i].modelHandle, objectRotation);
			MV1SetScale(objects[i].modelHandle, objectScale);

			printfDx("handle = %d\n", objects[i].modelHandle);
		}
	}

	// Map�̃I�u�W�F�N�g��`��
	void DrawMapObjects()
	{
		for (int i = 0; i < OBJECT_NUM; i++)
		{
			int handle = objects[i].modelHandle;
			MV1DrawModel(handle);
		}
	}
};