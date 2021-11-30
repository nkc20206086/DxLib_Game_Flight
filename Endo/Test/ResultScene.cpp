#include "ResultScene.h"

namespace Scene
{
	// リザルトでの処理

	// シーン遷移用の処理
	SceneStateMode ResultScene::GetNextScene()
	{
		static bool isHitKeyRetrun;
		bool beforeisHitKeyRetrun = isHitKeyRetrun;
		isHitKeyRetrun = CheckHitKey(KEY_INPUT_RETURN) == 1;
		if (!isHitKeyRetrun) return SceneStateMode::STAY;
		if (beforeisHitKeyRetrun) return SceneStateMode::STAY;
		return SceneStateMode::NEXT;
	}
}