#pragma once
#include "SceneBase.h"
#include <DxLib.h>

namespace Scene
{
	// �Q�[�����ɑ��݂���V�[����ENUM�ƃV�[�����̃J�E���g�p��ENUM
	enum class SceneType
	{
		TITLE = 0,
		GAME,
		RESULT,
		COUNT,
	};

	class SceneManager
	{
	public:
		inline SceneManager();
		inline ~SceneManager();
		// �Q�[�����[�v���񂷂��߂̎�v�֐�
		bool SceneProcess();
		void SetDraw_Screen(const bool& clear);

	private:
		// ���݂̃V�[���̃X�e�[�g
		SceneType state;
		// �V�[���̔z��
		SceneBase* scenes[(int)SceneType::COUNT];

	};

	SceneManager::SceneManager()
	{
		state = SceneType::GAME;
	}

	SceneManager::~SceneManager()
	{
		for (int i = 0; i < (int)SceneType::COUNT; i++)
		{
			delete scenes[i];
		}
	}



}
