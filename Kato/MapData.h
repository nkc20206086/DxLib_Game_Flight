#pragma once
#include "DxLib.h"

// マップオブジェクトのモデルの種類
enum ObjectType
{
	Cube = 0,
	Sphere = 1,
	Count,
};

// マップオブジェクトの構造体
typedef struct
{
	int modelHandle;			// モデルハンドル
	ObjectType modelType;		// モデルの種類
	VECTOR position;			// モデルの座標
	VECTOR rotation;			// モデルの回転
	VECTOR scale;				// モデルの拡縮
}MAP_OBJECT;




// マップオブジェクトの総数
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