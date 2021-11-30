#include "SceneManager.h"

namespace Scene
{
	// �V�[���S�̂ł̏���(�V�[���̕ύX���ʏ�����\���A�J�����̐ݒ蓙���s��)
	bool SceneManager::SceneProcess()
	{
		ClearDrawScreen();
		ScreenFlip();

		// ���̃V�[���֑J�ڂ��邩�̔��ʂ�����
		switch (scenes[(int)state]->GetNextScene())
		{
		case SceneStateMode::STAY:
			//�@�������Ȃ�
			break;
		case SceneStateMode::NEXT:
			// �V�[����enum����i�߂�(�V�[����ύX)
			// �V�[����COUNT�ȏ�ɂȂ����Ƃ��A�V�[�����J��Ԃ�
			state = (SceneType) (((int)state + 1) % (int)SceneType::COUNT);
			break;
		case SceneStateMode::BACK:
			// �V�[����enum����߂�(�V�[����ύX)
			// �V�[����0�����ɂȂ����Ƃ��A�V�[�����J��Ԃ�
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