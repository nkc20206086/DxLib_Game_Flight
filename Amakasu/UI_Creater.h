#pragma once
#include<map>
#include <vector>
#include <string>

using namespace std;
struct MyVec3//UIを配置するポジション
{
	float x;
	float y;
	float z;
};
struct UICore
{
	int spritehandle;
	MyVec3 pos = MyVec3();
};
struct UITextCore
{
	float size;
	string text;
	MyVec3 pos = MyVec3();
};
struct UIGroupCore
{
	int orderInlayer;

	vector<UICore> childUi;//ここに子供のUI達が入る配列がいる
	vector<UITextCore> childText;
};

class UI_Create
{
public:
	inline UI_Create() { _uihandleCount = 0; };
	int CreateUIGroupHandle(int orderInlayer = 0) ;//最初に呼ぶ。UIのグループIDを作成。
	bool UIAdd(int handle, int spritehandle, MyVec3 position);//UIを追加する
	bool UIAdd(int handle,string str, float size, MyVec3 position);
	bool DrowUI();
private:
	int _uihandleCount;
	map<int, UIGroupCore> UIDic;//UIのグループが入ったディクショナリ intはUIのグループハンドル
	//vector<map<int, UIGroupCore>> allUi;

	//最悪　はよ消してくれ　汚点

	vector<UIGroupCore> drawGroupm10;
	vector<UIGroupCore> drawGroupm9;
	vector<UIGroupCore> drawGroupm8;
	vector<UIGroupCore> drawGroupm7;
	vector<UIGroupCore> drawGroupm6;
	vector<UIGroupCore> drawGroupm5;
	vector<UIGroupCore> drawGroupm4;
	vector<UIGroupCore> drawGroupm3;
	vector<UIGroupCore> drawGroupm2;
	vector<UIGroupCore> drawGroupm1;
	vector<UIGroupCore> drawGroup0;
	vector<UIGroupCore> drawGroup1;
	vector<UIGroupCore> drawGroup2;
	vector<UIGroupCore> drawGroup3;
	vector<UIGroupCore> drawGroup4;
	vector<UIGroupCore> drawGroup5;
	vector<UIGroupCore> drawGroup6;
	vector<UIGroupCore> drawGroup7;
	vector<UIGroupCore> drawGroup8;
	vector<UIGroupCore> drawGroup9;
	vector<UIGroupCore> drawGroup10;

	//これはバケモンだからリスト作る
	//vector<>
};


