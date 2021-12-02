#pragma once
// namespace•t‚¯‚é‚×‚«‚È‚Ì‚©•s–¾
// Endo‚©‚ç‚Á‚Ä‚«‚½
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
