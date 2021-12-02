#pragma once
// namespace付けるべきなのか不明
// Endoから持ってきた
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
