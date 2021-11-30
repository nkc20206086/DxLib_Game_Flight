#include "DxLib.h"
#include <cmath>
#include "Quaternion.h"
#include <iostream>
#include <charconv>
#include "Vector.h"
#include "Transform.h"
#include "ShowGrid.h"
#include "MakeMap.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int playerModelHandle;		// �v���C���[�̃��f���n���h��
	VECTOR playerPosition;		// �v���C���[�̍��W
	char keyState[256];
	char oldKeyState[256] = {0};
	VECTOR cameraStartPosition = VGet(0, 1000, -1000);		// �J�����̏����ʒu
	VECTOR cameraStartLookAtPosition = VGet(0, 0, 1000);	// �J�������ŏ��Ɍ��Ă�ꏊ
	const float MOVE_SPEED = 10.0f;		// �ړ����x
	QUATERNION Q;		// �N�H�[�^�j�I���̍\����
	Quaternion q;		// �N�H�[�^�j�I��
	MATRIX mat;			// �s��
	MATRIX matRot;		// ��]�s��
	MATRIX matTrans;	// ���s�ړ��s��
	float yaw, pitch, roll;		// ��]
	yaw = pitch = roll = 0.0f;	// ��]������
	VECTOR xAxis, yAxis, zAxis;

	Vector Vector;		// �����Vector�BUnity��Vector3.zero���Č����邽�߂ɍ쐬
	Transform Transform;		// �����Transform�BUnity��Transform.forward���Č����邽�߂ɍ쐬
	VECTOR dir;

	MakeMap _makeMap;		// �}�b�v�쐬�p

	//�f�o�b�O�p===================
	ShowGrid _showGrid;		// �f�o�b�O�p�̃O���b�h��
	//=============================


	ChangeWindowMode(TRUE);

	// �c�w���C�u�����̏�����
	if (DxLib_Init() < 0)
	{
		// �G���[�����������璼���ɏI��
		return -1;
	}
	
	// �v���C���[�̃��f���n���h���쐬
	playerModelHandle = MV1LoadModel("Plane.mv1");

	// �J�����ݒ�
	SetCameraPositionAndTarget_UpVecY(cameraStartPosition, cameraStartLookAtPosition);

	// ���f���̈ʒu��������
	playerPosition = VGet(0.0f, 0.0f, 0.0f);
	dir = Vector.Zero();

	// ���f���̉�]��s���������
	Q = q.Identity();
	CreateIdentityMatrix(&mat);
	CreateIdentityMatrix(&matRot);
	CreateIdentityMatrix(&matTrans);

	// ��ʂɉf��ʒu�Ƀv���C���[���ړ�
	MV1SetPosition(playerModelHandle, playerPosition);

	// Map�ɔz�u���ׂ����f����z�u
	_makeMap.SettingMapObjects();

	// �f�o�b�O�p===============================
	// �O���b�h���̐F��ݒ�
	_showGrid.SetGridColor(255, 0, 255);
	//==========================================




	// =============================================================
	// ���C�����[�v
	// =============================================================
	while (ProcessMessage() == 0)
	{
		// ��ʂ��N���A
		ClearDrawScreen();
		GetHitKeyStateAll(keyState);

		// ��]���Z�b�g
		if (keyState[KEY_INPUT_R] == 1)
		{
			mat = MGetIdent();
			matRot = MGetIdent();
			playerPosition = Vector.Zero();
			Q = q.Identity();
		}


		//yaw��]
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

		//pitch��]
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

		//roll��]
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

		// �����őO�ɐi��
		// �L�[���͂���ύX
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

		// ��]�ݒ�
		matRot = q.QuaternionToMatrix(Q);
		mat = MMult(mat, matRot);

		// ���W�ݒ�
		playerPosition = VAdd(playerPosition, dir * MOVE_SPEED);
		matTrans = MGetTranslate(playerPosition);
		mat = MMult(mat, matTrans);

		// �s���ݒ�
		MV1SetMatrix(playerModelHandle, mat);




		// �J�����̈ʒu
		VECTOR cameraPosition;
		VECTOR cameraLookAtPosition;

		cameraLookAtPosition = VAdd(playerPosition, cameraStartLookAtPosition);
		cameraPosition = VAdd(cameraStartPosition, playerPosition);
		

		SetCameraPositionAndTarget_UpVecY(cameraPosition, cameraLookAtPosition);

		// �R�c���f���̕`��
		MV1DrawModel(playerModelHandle);

		// �}�b�v�̕`��
		_makeMap.DrawMapObjects();
		

		// �f�o�b�O�p�n�ʂ��쐬
		_showGrid.MakeGrid(TRUE, 20, 5000.0f);

		// ESC�L�[�ŏI���
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

		for (int i = 0; i < 256; i++)
		{
			oldKeyState[i] = keyState[i];
		}
	}

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}