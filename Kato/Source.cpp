#include "DxLib.h"
#include <cmath>
#include "Quaternion.h"
#include <iostream>
#include <charconv>
#include "Vector.h"
#include "Transform.h"
#include "ShowGrid.h"
#include "MakeMap.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int playerModelHandle;		// プレイヤーのモデルハンドル
	VECTOR playerPosition;		// プレイヤーの座標
	char keyState[256];
	char oldKeyState[256] = {0};
	VECTOR cameraStartPosition = VGet(0, 1000, -1000);		// カメラの初期位置
	VECTOR cameraStartLookAtPosition = VGet(0, 0, 1000);	// カメラが最初に見てる場所
	const float MOVE_SPEED = 10.0f;		// 移動速度
	QUATERNION Q;		// クォータニオンの構造体
	Quaternion q;		// クォータニオン
	MATRIX mat;			// 行列
	MATRIX matRot;		// 回転行列
	MATRIX matTrans;	// 平行移動行列
	float yaw, pitch, roll;		// 回転
	yaw = pitch = roll = 0.0f;	// 回転初期化
	VECTOR xAxis, yAxis, zAxis;

	Vector Vector;		// 自作のVector。UnityのVector3.zeroを再現するために作成
	Transform Transform;		// 自作のTransform。UnityのTransform.forwardを再現するために作成
	VECTOR dir;

	MakeMap _makeMap;		// マップ作成用

	//デバッグ用===================
	ShowGrid _showGrid;		// デバッグ用のグリッド線
	//=============================


	ChangeWindowMode(TRUE);

	// ＤＸライブラリの初期化
	if (DxLib_Init() < 0)
	{
		// エラーが発生したら直ちに終了
		return -1;
	}
	
	// プレイヤーのモデルハンドル作成
	playerModelHandle = MV1LoadModel("Plane.mv1");

	// カメラ設定
	SetCameraPositionAndTarget_UpVecY(cameraStartPosition, cameraStartLookAtPosition);

	// モデルの位置を初期化
	playerPosition = VGet(0.0f, 0.0f, 0.0f);
	dir = Vector.Zero();

	// モデルの回転や行列を初期化
	Q = q.Identity();
	CreateIdentityMatrix(&mat);
	CreateIdentityMatrix(&matRot);
	CreateIdentityMatrix(&matTrans);

	// 画面に映る位置にプレイヤーを移動
	MV1SetPosition(playerModelHandle, playerPosition);

	// Mapに配置すべきモデルを配置
	_makeMap.SettingMapObjects();

	// デバッグ用===============================
	// グリッド線の色を設定
	_showGrid.SetGridColor(255, 0, 255);
	//==========================================




	// =============================================================
	// メインループ
	// =============================================================
	while (ProcessMessage() == 0)
	{
		// 画面をクリア
		ClearDrawScreen();
		GetHitKeyStateAll(keyState);

		// 回転リセット
		if (keyState[KEY_INPUT_R] == 1)
		{
			mat = MGetIdent();
			matRot = MGetIdent();
			playerPosition = Vector.Zero();
			Q = q.Identity();
		}


		//yaw回転
		bool yawFlag = false;
		if (keyState[KEY_INPUT_LEFT] == 1)
		{
			yaw = -0.1f;
			yawFlag = true;
		}
		
		if (keyState[KEY_INPUT_RIGHT] == 1)
		{
			yaw = 0.1f;
			yawFlag = true;
		}
		
		if (!yawFlag)
		{
			yaw = 0.0f;
		}

		//pitch回転
		bool pitchFlag = false;
		if (keyState[KEY_INPUT_UP] == 1)
		{
			pitch = -0.1f;
			pitchFlag = true;

		}

		if (keyState[KEY_INPUT_DOWN] == 1)
		{
			pitch = 0.1f;
			pitchFlag = true;
		}

		if (!pitchFlag)
		{
			pitch = 0.0f;
		}

		//roll回転
		bool rollFlag = false;
		if (keyState[KEY_INPUT_Z] == 1)
		{
			roll = 0.1f;
			rollFlag = true;
		}

		if (keyState[KEY_INPUT_X] == 1)
		{
			roll = -0.1f;
			rollFlag = true;
		}

		if (!rollFlag)
		{
			roll = 0.0f;
		}

		// 自動で前に進む
		// キー入力から変更
		dir = Transform.Forward(Q, Vector.Forward());
		/*if (keyState[KEY_INPUT_W] == 1)
		{
			dir = Transform.Forward(Q, Vector.Forward());
		}
		else
		{
			dir = Vector.Zero();
		}*/

		

		mat = MGetScale(VGet(1.0, 1.0, 1.0));

		// roll
		zAxis = VGet(mat.m[2][0], mat.m[2][1], mat.m[2][2]);
		Q = Q * q.RotationQuaternion(roll, zAxis);

		// pitch
		xAxis = VGet(mat.m[0][0], mat.m[0][1], mat.m[0][2]);
		Q = Q * q.RotationQuaternion(pitch, xAxis);

		// yaw
		yAxis = VGet(mat.m[1][0], mat.m[1][1], mat.m[1][2]);
		Q = Q * q.RotationQuaternion(yaw, yAxis);

		// 回転設定
		matRot = q.QuaternionToMatrix(Q);
		mat = MMult(mat, matRot);

		// 座標設定
		playerPosition = VAdd(playerPosition, dir * MOVE_SPEED);
		matTrans = MGetTranslate(playerPosition);
		mat = MMult(mat, matTrans);

		// 行列を設定
		MV1SetMatrix(playerModelHandle, mat);




		// カメラの位置
		VECTOR cameraPosition;
		VECTOR cameraLookAtPosition;

		cameraLookAtPosition = VAdd(playerPosition, cameraStartLookAtPosition);
		cameraPosition = VAdd(cameraStartPosition, playerPosition);
		

		SetCameraPositionAndTarget_UpVecY(cameraPosition, cameraLookAtPosition);

		// ３Ｄモデルの描画
		MV1DrawModel(playerModelHandle);

		// マップの描画
		_makeMap.DrawMapObjects();
		

		// デバッグ用地面を作成
		_showGrid.MakeGrid(TRUE, 20, 5000.0f);

		// ESCキーで終わる
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}

		// 裏画面の内容を表画面に反映
		ScreenFlip();

		for (int i = 0; i < 256; i++)
		{
			oldKeyState[i] = keyState[i];
		}
	}

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}