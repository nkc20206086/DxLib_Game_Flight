#include <math.h>
#include <DxLib.h>
#include"primitive.h"

#if 0



static const float ROTATE_SPEED = DX_PI_F / 90.0f;//��]�X�s�[�h
static const float TRANSFORM_SPEED = 25.0f;//�ړ��X�s�[�h


int ColHit(VECTOR ColPos, VECTOR EneColPos, float ColRad, float EneColRad )
{

	if ((EneColPos.x - ColPos.x) * (EneColPos.x - ColPos.x) +
		(EneColPos.y - ColPos.y) * (EneColPos.y - ColPos.y) +
		(EneColPos.z - ColPos.z) * (EneColPos.z - ColPos.z) <=
		(ColRad + EneColRad) * (ColRad + EneColRad))
	{
		return 1;
	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	float angleX = 0.f, angleY = 0.f, angleZ = 0.f;
	VECTOR Pos = VGet(0.0f, 0.0f, 0.0f);
	VECTOR EnePos = VGet(200.0f, 200.0f, 0.0f);
	float PLRad = 10.0f;
	float EneRad = 15.0f;

	int CheckHit = 0;


	//�J�����̉��s�̕`��͈�
	SetCameraNearFar(0.1f, 1000.0f);

	//�L�[�{�[�h�̉��������i�[���邽�߂̔z��
	char keystate[256];

	//�E�B���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	int ModelHandle = MV1LoadModel("Player.mv1");
	int ModelHandle2 = MV1LoadModel("Player.mv1");
	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, -1000), VGet(0, 0, 0));
	//���C�����[�v
	while (ProcessMessage() == 0)
	{


		//�Q�[���̏����͊�{�����ŉ�

		//��ʂ�����
		ClearDrawScreen();


		//���݂̃L�[�{�[�h�̏�Ԃ����ׂĎ擾
		GetHitKeyStateAll(keystate);

		//���͏���
		if (CheckHitKey(KEY_INPUT_X) > 0)
		{
			//X�L�[�������Ȃ��獶�E�L�[��������X����]
			if (CheckHitKey(KEY_INPUT_RIGHT) > 0)
			{
				angleX += ROTATE_SPEED;
			}

			if (CheckHitKey(KEY_INPUT_LEFT) > 0)
			{
				angleX -= ROTATE_SPEED;
			}

		}

		if (CheckHitKey(KEY_INPUT_Y) > 0)
		{
			//Y�L�[�������Ȃ��獶�E�L�[��������Y����]
			if (CheckHitKey(KEY_INPUT_RIGHT) > 0)
			{
				angleY += ROTATE_SPEED;
			}

			if (CheckHitKey(KEY_INPUT_LEFT) > 0)
			{
				angleY -= ROTATE_SPEED;
			}

		}

		if (CheckHitKey(KEY_INPUT_Z) > 0)
		{
			//Z�L�[�������Ȃ��獶�E�L�[��������Z����]
			if (CheckHitKey(KEY_INPUT_RIGHT) > 0)
			{
				angleZ += ROTATE_SPEED;
			}

			if (CheckHitKey(KEY_INPUT_LEFT) > 0)
			{
				angleZ -= ROTATE_SPEED;
			}
		}

		if (CheckHitKey(KEY_INPUT_W) > 0)
		{
			Pos.y += TRANSFORM_SPEED;
			
		}

		if (CheckHitKey(KEY_INPUT_S) > 0)
		{
			Pos.y -= TRANSFORM_SPEED;
			
		}

		if (CheckHitKey(KEY_INPUT_D) > 0)
		{
			Pos.x += TRANSFORM_SPEED;
			
		}

		if (CheckHitKey(KEY_INPUT_A) > 0)
		{
			Pos.x -= TRANSFORM_SPEED;
			
		}


		//�����蔻��𔻒f(1�Ȃ瓖����A0�Ȃ瓖���Ă��Ȃ�)
		CheckHit = ColHit(Pos, EnePos, PLRad, EneRad);

		if ( CheckHit > 0 )
		{
			Pos = VGet(0.0f, 0.0f,0.0f);
		}


		//---------------------------	
		//�`�揈��
		//---------------------------	

		//3D�̐}�`���f��ʒu�Ɉړ�
		MV1SetPosition(ModelHandle, Pos);
		MV1SetPosition(ModelHandle2, EnePos);

		//�������̉�]�p�x���Z�b�g
		MV1SetRotationXYZ(ModelHandle, VGet(angleX, angleY, angleZ));

		//3D�̎O�p�`��`��
		MV1DrawModel(ModelHandle);
		MV1DrawModel(ModelHandle2);

		//��ʂ�؂�ւ���
		ScreenFlip();
	}

	WaitKey();

	DxLib_End();

	return 0;
}
#endif // 0