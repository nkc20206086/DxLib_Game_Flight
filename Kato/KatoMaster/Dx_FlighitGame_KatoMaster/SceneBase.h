#pragma once
// namespace�t����ׂ��Ȃ̂��s��
// Endo���玝���Ă���
namespace Scene
{
	enum class SceneStateMode
	{
		STAY,
		NEXT,
		BACK,
	};

	class SceneBase
	{
	public:
		virtual SceneStateMode GetNextScene();
	};
}
