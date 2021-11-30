#pragma once
#include<DxLib.h>
#include<vector>
#include<typeinfo>

#include"Transform.h"
#include"Compornent.h"
#include"CompornentType.h"
#include"NullComponent.h"

//コンポーネントの名前　これしか思いつかんかった
//ここでコライダーを知りたくない

class GameObject
{
public:
	GameObject();

	//指定されたコンポーネントをセット
	int AddCompornent(CompornentType target);
	//描画関係
	bool SetModelHandle(const TCHAR* ModelName);
	void DrawObject();

	//コンポーネントを持つ用の配列
	Compornent* comp[3];

	std::vector<GameObject> HitObj;

	//自分の持っているコンポーネントを送りつける
	template<typename T>
	T& GetCompornent() {
		for (int i = 0; i < 3; i++)
		{
			if (typeid(T) == typeid(comp[i]) ) {
				return (T&)comp[i];
			}
		}
		return (T&)comp[0];
		//無い場合　エラー返したい
		
	}


private:
	//当たり判定管理用番号
	//int collisionNum;
//	bool ishit;
	int modelhandle;

	//Transform _transform;
};
