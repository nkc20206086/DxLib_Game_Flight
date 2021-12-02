// �e�X�g�p�X�N���v�g
#include "DxLib.h"
#include <memory>
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	auto scenemanager = std::make_unique<Scene::SceneManager>();

	while (ProcessMessage() == 0)
	{
		// �A�N�e�B�u�ȃV�[���̏�������
		bool isfinish = scenemanager->SceneProcess();

		if (isfinish)
		{
			break;
		}
	}

	return 0;
}