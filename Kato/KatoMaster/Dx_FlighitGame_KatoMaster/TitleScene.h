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

		SceneStateMode GetNextScene() override;

	private:
		// �ϐ����͂����Ő錾

	};

	TitleScene::TitleScene()
	{
		printfDx("�^�C�g���V�[���̃R���X�g���N�^\n");
	}

	TitleScene::~TitleScene()
	{
		printfDx("�^�C�g���V�[���̃f�X�g���N�^\n");
	}
}