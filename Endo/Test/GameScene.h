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

		// SceneBaseを介して継承
		SceneStateMode GetNextScene() override;

	private:
		// 変数等はここで宣言

	};

	GameScene::GameScene()
	{
		// GameSceneのコンストラクタ
	}

	GameScene::~GameScene()
	{
		// GameSceneのデストラクタ
	}

}
