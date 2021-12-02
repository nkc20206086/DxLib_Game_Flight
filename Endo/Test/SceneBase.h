#pragma once

namespace Scene
{
	// �V�[���̑؍݁A�ړ��p��ENUM�N���X
	enum class SceneStateMode
	{
		STAY,
		NEXT,
		BACK,
	};


	class SceneBase
	{
	public:
		//���̃X�e�[�g�̏o�͗p�֐�
		virtual SceneStateMode GetNextScene();
	};

}
