#include <DxLib.h>
#include "GameObject.h"

// 画面サイズ
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// シーン遷移用ENUM
enum class SCENE : unsigned int
{
	NONE = 0,
	TITLE,
	GAME,
	RESULT,

	EXIT,
	NUM,
};


// タイトルシーンクラス
class Title : public GameObject
{
public:
	Title()
	{

	}

	void Init() override
	{

	}

	void Update() override
	{

	}

};

// ゲームオーバーシーンクラス
class GameOver : public GameObject
{
public:
	GameOver()
	{

	}

	void Init() override
	{

	}

	void Update() override
	{

	}

};

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);		// ウィンドウモードに変更

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	// 画面サイズの設定



	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);		// ダブルバッファモード

	SCENE scene = SCENE::TITLE;

	while (ProcessMessage() == 0)	// ゲームのメインループ
	{

	}

	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}