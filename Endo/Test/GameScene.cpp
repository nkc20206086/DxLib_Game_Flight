#include "GameScene.h"

namespace Scene
{
	// ゲームシーンでの処理

	// シーン遷移の処理
	SceneStateMode GameScene::GetNextScene()
	{
		static bool isHitKeyRetrun;
		bool beforeisHitKeyRetrun = isHitKeyRetrun;
		isHitKeyRetrun = CheckHitKey(KEY_INPUT_RETURN) == 1;
		if (!isHitKeyRetrun) return SceneStateMode::STAY;
		if (beforeisHitKeyRetrun) return SceneStateMode::STAY;
		return SceneStateMode::NEXT;
	}
}