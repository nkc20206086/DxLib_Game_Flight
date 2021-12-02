#include "SceneManager.h"

namespace Scene
{
	// シーン全体での処理(シーンの変更や画面消去や表示、カメラの設定等を行う)
	bool SceneManager::SceneProcess()
	{
		ClearDrawScreen();
		ScreenFlip();

		// 次のシーンへ遷移するかの判別をする
		switch (scenes[(int)state]->GetNextScene())
		{
		case SceneStateMode::STAY:
			//　何もしない
			break;
		case SceneStateMode::NEXT:
			// シーンのenumを一つ進める(シーンを変更)
			// シーンがCOUNT以上になったとき、シーンを繰り返す
			state = (SceneType) (((int)state + 1) % (int)SceneType::COUNT);
			break;
		case SceneStateMode::BACK:
			// シーンのenumを一つ戻す(シーンを変更)
			// シーンが0未満になったとき、シーンを繰り返す
			state = (SceneType)(((int)state - 1 + (int)SceneType::COUNT) % (int)SceneType::COUNT);
			break;
		default:
			break;
		}

		bool isHitKeyEscape = false;
		static bool beforeIsHitKeyEscape = isHitKeyEscape;
		isHitKeyEscape = CheckHitKey(KEY_INPUT_ESCAPE) == 1;
		if (isHitKeyEscape && beforeIsHitKeyEscape) return true;
		return false;

	}


}