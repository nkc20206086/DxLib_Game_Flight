#include <math.h>
#include <DxLib.h>
#include"primitive.h"

#if 0



static const float ROTATE_SPEED = DX_PI_F / 90.0f;//回転スピード
static const float TRANSFORM_SPEED = 25.0f;//移動スピード


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


	//カメラの奥行の描画範囲
	SetCameraNearFar(0.1f, 1000.0f);

	//キーボードの押下情報を格納するための配列
	char keystate[256];

	//ウィンドウモードに変更
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	int ModelHandle = MV1LoadModel("Player.mv1");
	int ModelHandle2 = MV1LoadModel("Player.mv1");
	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, -1000), VGet(0, 0, 0));
	//メインループ
	while (ProcessMessage() == 0)
	{


		//ゲームの処理は基本ここで回す

		//画面を消す
		ClearDrawScreen();


		//現在のキーボードの状態をすべて取得
		GetHitKeyStateAll(keystate);

		//入力処理
		if (CheckHitKey(KEY_INPUT_X) > 0)
		{
			//Xキーを押しながら左右キーを押すとX軸回転
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
			//Yキーを押しながら左右キーを押すとY軸回転
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
			//Zキーを押しながら左右キーを押すとZ軸回転
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


		//当たり判定を判断(1なら当たり、0なら当っていない)
		CheckHit = ColHit(Pos, EnePos, PLRad, EneRad);

		if ( CheckHit > 0 )
		{
			Pos = VGet(0.0f, 0.0f,0.0f);
		}


		//---------------------------	
		//描画処理
		//---------------------------	

		//3Dの図形を映る位置に移動
		MV1SetPosition(ModelHandle, Pos);
		MV1SetPosition(ModelHandle2, EnePos);

		//第二引数の回転角度をセット
		MV1SetRotationXYZ(ModelHandle, VGet(angleX, angleY, angleZ));

		//3Dの三角形を描画
		MV1DrawModel(ModelHandle);
		MV1DrawModel(ModelHandle2);

		//画面を切り替える
		ScreenFlip();
	}

	WaitKey();

	DxLib_End();

	return 0;
}
#endif // 0