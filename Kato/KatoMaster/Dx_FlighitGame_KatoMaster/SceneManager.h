#pragma once
#include "SceneBase.h"
#include <DxLib.h>

namespace Scene
{
	// ゲーム中に存在するシーンのENUMとシーン数のカウント用のENUM
	enum class SceneType
	{
		TITLE = 0,
		TUTORIAL,
		GAME,
		CLEAR,
		GAMEOVER,
		COUNT,
	};

	class SceneManager
	{
	public:
		inline SceneManager();
		inline ~SceneManager();

		// ゲームループを回すための主要関数
		bool SceneProcess();
		void SetDraw_Screen(const bool& clear);		// 謎。まだわからん

	private:
		// 現在のシーンのステート
		SceneType state;
		// シーンの配列
		SceneBase* scenes[(int)SceneType::COUNT];
	};

	SceneManager::SceneManager()
	{
		state = SceneType::TITLE;
	}

	SceneManager::~SceneManager()
	{
		for (int i = 0; i < (int)SceneType::COUNT; i++)
		{
			delete scenes[i];
		}
	}
}