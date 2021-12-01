#include <DxLib.h>
#include <memory>
#include "headerTest.h"
#include "inputTest.h"
#include "Player.h"
#include "ring.h"
#include "Collider.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	unsigned int Cr;
	Cr = GetColor(255, 255, 255);
	MyInput input = MyInput();
	Player player = Player();
	Ring ring = Ring();

	Collider colliider = Collider();

	if (DxLib_Init() == -1)        // �c�w���C�u��������������
	{
		return -1;         // �G���[���N�����璼���ɏI��
	}
	auto draw = std::make_unique<DxDraw>();//�X�}�[�g�|�C���^�@�@C#�Ɠ����悤�ɏ���ɃK�x�[�W�R���N�V�������Ă����
	{
		//int ModelHandle;
		int LightHandle;


		char keyState[256];
		char oldKeyState[256];

		for (int i = 0; i < 256; i++)//������
		{
			oldKeyState[i] = 0;
		}

		float boxX = 0, boxY = 0;
		VECTOR vec = VGet(0, 0, 0);
		VECTOR ringVec = VGet(0, 300, 0);
		//�RD���f���̓ǂݍ���
		player.SetModelHandle("Player.mv1");

		ring.SetModelHandle("Player.mv1");

		SetCameraPositionAndTarget_UpVecY(VGet(0, 0, -1000), VGet(0, 0, 0));


		// ���ʂ��킩��Ղ��悤�ɕW�����C�g�𖳌���
		SetLightEnable(FALSE);

		//�������Ƀ��C�g�쐬
		LightHandle = CreateDirLightHandle(VGet(-1.0f, -1.0f, 1.0f));

	
		//player.PlayerSetPos(vec);

		

		while (ProcessMessage() == 0)
		{
			ClearDrawScreen();
			//GetHitKeyStateAll(keyState);
			input.SetInputState();

		
#pragma region �C���v�b�g�֘A
			if (input.GetKey(KEY_INPUT_A))
			{
				vec.x -= 10.0f;
			}

			if (input.GetKey(KEY_INPUT_D))
			{
				vec.x += 10.0f;
			}

			if (input.GetKey(KEY_INPUT_S))
			{
				vec.y -= 10.0f;
			}

			if (input.GetKey(KEY_INPUT_W))
			{
				vec.y += 10.0f;
			}
			if (input.GetKeyDown(KEY_INPUT_UP))
			{
				vec.y += 100.0f;

			}
			if (input.GetKeyDown(KEY_INPUT_DOWN))
			{
				vec.y -= 100.0f;
			}
			if (input.GetKeyDown(KEY_INPUT_RIGHT))
			{
				vec.x += 100.0f;
			}
			if (input.GetKeyUp(KEY_INPUT_LEFT))
			{
				vec.x -= 100.0f;
			}

#pragma endregion
			/*if (input.GetKeyDown(KEY_INPUT_SPACE))
			{
				player.HitObj.push_back(ring);
			}*/
			if (input.GetKeyDown(KEY_INPUT_RETURN))
			{
				player.GetCompornent<Transform>().position = VGet(0, 0, 0);
			}
			
			player.PlayerSetPos(vec);
		
			player.DrawObject();
			
			//player.DrawPlayer();
			ScreenFlip();
			input.SetInputStateOld();
		}
		//���f���n���h���̍폜
		//MV1DeleteModel(ModelHandle);


		//WaitKey();
	}


	return 0;              // �\�t�g�̏I�� 
}