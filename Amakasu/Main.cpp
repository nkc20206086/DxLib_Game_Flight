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

	if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
	{
		return -1;         // エラーが起きたら直ちに終了
	}
	auto draw = std::make_unique<DxDraw>();//スマートポインタ　　C#と同じように勝手にガベージコレクションしてくれる
	{
		//int ModelHandle;
		int LightHandle;


		char keyState[256];
		char oldKeyState[256];

		for (int i = 0; i < 256; i++)//初期化
		{
			oldKeyState[i] = 0;
		}

		float boxX = 0, boxY = 0;
		VECTOR vec = VGet(0, 0, 0);
		VECTOR ringVec = VGet(0, 300, 0);
		//３Dモデルの読み込み
		player.SetModelHandle("Player.mv1");

		ring.SetModelHandle("Player.mv1");

		SetCameraPositionAndTarget_UpVecY(VGet(0, 0, -1000), VGet(0, 0, 0));


		// 効果がわかり易いように標準ライトを無効化
		SetLightEnable(FALSE);

		//ｘじくにライト作成
		LightHandle = CreateDirLightHandle(VGet(-1.0f, -1.0f, 1.0f));

	
		//player.PlayerSetPos(vec);

		

		while (ProcessMessage() == 0)
		{
			ClearDrawScreen();
			//GetHitKeyStateAll(keyState);
			input.SetInputState();

		
#pragma region インプット関連
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
		//モデルハンドルの削除
		//MV1DeleteModel(ModelHandle);


		//WaitKey();
	}


	return 0;              // ソフトの終了 
}