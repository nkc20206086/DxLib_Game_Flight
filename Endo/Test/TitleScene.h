#pragma once
#include <DxLib.h>
#include "SceneBase.h"

namespace Scene
{
	class TitleScene : public SceneBase
	{
	public:
		inline TitleScene();
		inline ~TitleScene();

		// SceneBase����Čp��
		SceneStateMode GetNextScene() override;

	private:
		// �ϐ����͂����Ő錾

	};

	TitleScene::TitleScene()
	{
		// �^�C�g���V�[���̃R���X�g���N�^
	}

	TitleScene::~TitleScene()
	{
		// �^�C�g���V�[���̃f�X�g���N�^
	}

}
