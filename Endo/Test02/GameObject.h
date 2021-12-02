#pragma once
#include <DxLib.h>
#include <vector>

// Objectのリスト
class GameObject;	// ゲームオブジェクトクラスの定義
std::vector<GameObject*>objects;	// stdのベクター型

// オブジェクトの作成
template<typename T>	// 関数テンプレートのTを宣言

T& createGameObject()
{
	objects.push_back(new T());
	auto* obj = (T*)objects[objects.size() - 1];

	obj->Init();
	return *obj;

}

// ゲームオブジェクトの取得
template <typename T>
T* GetGameObject()
{
	for (auto* obj : objects)
	{
		T* ptr = dynamic_cast<T*>(obj);
		if (ptr)
		{
			return (T*)obj;
		}
	}
	return nullptr;
}

// 現在存在しているオブジェクトを取得する
template <typename T>
std::vector<T*> GetGameObjects()
{
	std::vector<T*> objs;
	for (auto* obj : objects)
	{
		T* ptr = dynamic_cast<T*>(obj);
		if (ptr)
		{
			objs.push_back(ptr);
		}
	}
	return objs;
}

// 現在の存在しているオブジェクト数の確認
size_t CountGameObjects()
{
	return objects.size();
}

//基底のオブジェクトクラス
class GameObject
{
public:
	GameObject()
	{

	}

	virtual ~GameObject()
	{

	}

	// imgを隠ぺいするために用意
	void Load(const TCHAR* name)
	{
		img = LoadGraph(name);
		// imageのサイズを取得
		int size_x, size_y;
		GetImageSize_File(name, &size_x, &size_y);
		size.x = (float)size_x;
		size.y = (float)size_y;

	}

	virtual void Init()
	{

	}

	// 更新
	virtual void Update()
	{
		pos.x += move.x;
		pos.y += move.y;
	}

	//キャラ表示
	virtual void Draw()
	{
		if (alpha < 1.0f)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(255 * alpha));
			DrawGraphF(pos.x, pos.y, img, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else
		{
			DrawGraphF(pos.x, pos.y, img, TRUE);
		}
	}

	//終了時に呼ぶとキャラを消す
	void Exit()
	{
		// TODO: 同じものを使用したら開放しないようにする
		DeleteGraph(img);
	}

	//消去
	void TheEnd() { is_end = true; };

	// 位置
	VECTOR pos = { 0.0f,0.0f };
	// 移動量
	VECTOR move = { 0.0f,0.0f };
	// キャラサイズ
	VECTOR size = { 0.0f,0.0f };

	// 内部用
	bool _isEnd() { return is_end; }

protected:
	// LoadGraphのイメージが入る
	int img = -1;
	// 半透明度
	float alpha = 1.0f;

	// 終了しているか
	bool is_end = false;

};

// 全オブジェクトの更新と描画と生存確認(消去処理)
void processGameObjects()
{
	for (auto& obj : objects)
		obj->Update();

	for (auto& obj : objects)
		obj->Draw();

	// 終了フラグが立っている場合は削除
	for (int i = (int)objects.size() - 1 ; i >= 0; --i)
	{
		if (objects[i]->_isEnd())
		{
			delete objects[i];
			objects.erase(objects.begin() + i);
		}
	}

}

// 全オブジェクト消去(基本的に終了時に呼ぶ)
void DeleteGameObjects()
{
	for (auto* obj : objects)
	{
		delete obj;
	}
	objects.clear();
}