#pragma once

namespace Scene
{
	// シーンの滞在、移動用のENUMクラス
	enum class SceneStateMode
	{
		STAY,
		NEXT,
		BACK,
	};


	class SceneBase
	{
	public:
		//次のステートの出力用関数
		virtual SceneStateMode GetNextScene();
	};

}
