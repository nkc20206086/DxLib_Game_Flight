#include "SceneManager.h"

namespace Scene
{
	// �V�[���S�̂ł̏���(�V�[���̕ύX���ʏ�����\���A�J�����̐ݒ蓙���s��)
	bool SceneManager::SceneProcess()
	{
		ClearDrawScreen();
		ScreenFlip();


		// ���̃V�[���֑J�ڂ��邩�̔��ʂ�����
		// ���ꂾ�Ɖ��Ԗڂ̃V�[���ɍs�������I�I�Ƃ��ł��Ȃ��C������c�킩��񂯂�
		switch (scenes[(int)state]->GetNextScene())
		{
		case SceneStateMode::STAY:
			// �������Ȃ�
			break;

		case SceneStateMode::NEXT:
			state = (SceneType)(((int)state + 1) % (int)SceneType::COUNT);
			break;

		case SceneStateMode::BACK:
			state = (SceneType)(((int)state - 1 + (int)SceneType::COUNT) % (int)SceneType::COUNT);
			break;
		default:
			break;
		}

		// ��
		bool isHitKeyEscape = false;
		static bool beforeIsHitKeyEscape = isHitKeyEscape;
		isHitKeyEscape = CheckHitKey(KEY_INPUT_ESCAPE) == 1;
		if (isHitKeyEscape && beforeIsHitKeyEscape) return true;
		return false;
	}
}