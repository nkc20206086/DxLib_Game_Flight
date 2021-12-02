#pragma once
#include "DxLib.h"
#include "MapData.h"

class MakeMap
{
private:
	int cubeHandle = 0;		// Boxのモデルハンドル
	int sphereHandle = 0;	// Sphereのモデルハンドル

	// モデルハンドルを先に全部ロードする
	void FirstTimeModelLoad()
	{
		cubeHandle = MV1LoadModel("Cube.mv1");
		sphereHandle = MV1LoadModel("Sphere.mv1");
	}

	// ハンドルを取得
	int GetObjectsHandle(ObjectType type)
	{
		int handleNum = 0;
		switch (type)
		{
		case Cube: handleNum = cubeHandle;	break;
		case Sphere: handleNum = sphereHandle; break;
		default: printfDx("モデルが登録されてない。\n"); break;
		}
		return handleNum;
	}

	// ハンドルを設定
	void SetMapObjectsHandle()
	{
		// モデルを全部ロード
		FirstTimeModelLoad();

		for (int i = 0; i < OBJECT_NUM; i++)
		{
			objects[i].modelHandle = MV1DuplicateModel(GetObjectsHandle(objects[i].modelType));
		}
	}

public:

	// Mapに配置すべきモデルを配置
	void SettingMapObjects()
	{
		// ハンドルを設定
		SetMapObjectsHandle();

		for (int i = 0; i < OBJECT_NUM; i++)
		{
			// 座標、回転、拡縮を取得
			VECTOR objectPosition = VGet(objects[i].position.x, objects[i].position.y, objects[i].position.z);
			VECTOR objectRotation = VGet(objects[i].rotation.x, objects[i].rotation.y, objects[i].rotation.z);
			VECTOR objectScale = VGet(objects[i].scale.x, objects[i].scale.y, objects[i].scale.z);

			// 座標、回転、拡縮を適用
			MV1SetPosition(objects[i].modelHandle, objectPosition);
			MV1SetRotationXYZ(objects[i].modelHandle, objectRotation);
			MV1SetScale(objects[i].modelHandle, objectScale);

			printfDx("handle = %d\n", objects[i].modelHandle);
		}
	}

	// Mapのオブジェクトを描画
	void DrawMapObjects()
	{
		for (int i = 0; i < OBJECT_NUM; i++)
		{
			int handle = objects[i].modelHandle;
			MV1DrawModel(handle);
		}
	}
};