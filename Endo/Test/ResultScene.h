#pragma once
#include <DxLib.h>
#include "SceneBase.h"

namespace Scene
{
	class ResultScene : public SceneBase
	{
	public:
		inline ResultScene();
		inline ~ResultScene();

		// SceneBase���p��
		SceneStateMode GetNextScene() override;

	private:
		// �ϐ����͂����Ő錾
	};

	ResultScene::ResultScene()
	{
		// ResultScene�̃R���X�g���N�^
	}

	ResultScene::~ResultScene()
	{
		// ResultScene�̃f�X�g���N�^
	}
}
