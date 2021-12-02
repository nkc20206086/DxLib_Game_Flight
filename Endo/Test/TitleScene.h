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

		// SceneBaseを介して継承
		SceneStateMode GetNextScene() override;

	private:
		// 変数等はここで宣言

	};

	TitleScene::TitleScene()
	{
		// タイトルシーンのコンストラクタ
	}

	TitleScene::~TitleScene()
	{
		// タイトルシーンのデストラクタ
	}

}
