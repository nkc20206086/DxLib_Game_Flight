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

		// SceneBaseより継承
		SceneStateMode GetNextScene() override;

	private:
		// 変数等はここで宣言
	};

	ResultScene::ResultScene()
	{
		// ResultSceneのコンストラクタ
	}

	ResultScene::~ResultScene()
	{
		// ResultSceneのデストラクタ
	}
}
