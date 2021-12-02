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
		// 変数等はここで宣言

	};

	TitleScene::TitleScene()
	{
		printfDx("タイトルシーンのコンストラクタ\n");
	}

	TitleScene::~TitleScene()
	{
		printfDx("タイトルシーンのデストラクタ\n");
	}
}