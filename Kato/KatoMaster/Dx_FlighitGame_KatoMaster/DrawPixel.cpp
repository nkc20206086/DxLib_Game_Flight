// テスト用スクリプト
#include "DxLib.h"
#include <memory>
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	auto scenemanager = std::make_unique<Scene::SceneManager>();

	while (ProcessMessage() == 0)
	{
		// アクティブなシーンの処理を回す
		bool isfinish = scenemanager->SceneProcess();

		if (isfinish)
		{
			break;
		}
	}

	return 0;
}