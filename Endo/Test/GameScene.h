#pragma once
#include <DxLib.h>
#include "SceneBase.h"

namespace Scene
{
	class GameScene : public SceneBase
	{
	public:
		inline GameScene();
		inline ~GameScene();

		// SceneBase����Čp��
		SceneStateMode GetNextScene() override;

	private:
		// �ϐ����͂����Ő錾

	};

	GameScene::GameScene()
	{
		// GameScene�̃R���X�g���N�^
	}

	GameScene::~GameScene()
	{
		// GameScene�̃f�X�g���N�^
	}

}
