#pragma once
#include<map>
#include <vector>
#include <string>

using namespace std;
struct MyVec3//UI��z�u����|�W�V����
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

	vector<UICore> childUi;//�����Ɏq����UI�B������z�񂪂���
	vector<UITextCore> childText;
};

class UI_Create
{
public:
	inline UI_Create() { _uihandleCount = 0; };
	int CreateUIGroupHandle(int orderInlayer = 0) ;//�ŏ��ɌĂԁBUI�̃O���[�vID���쐬�B
	bool UIAdd(int handle, int spritehandle, MyVec3 position);//UI��ǉ�����
	bool UIAdd(int handle,string str, float size, MyVec3 position);
	bool DrowUI();
private:
	int _uihandleCount;
	map<int, UIGroupCore> UIDic;//UI�̃O���[�v���������f�B�N�V���i�� int��UI�̃O���[�v�n���h��
	//vector<map<int, UIGroupCore>> allUi;

	//�ň��@�͂�����Ă���@���_

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

	//����̓o�P���������烊�X�g���
	//vector<>
};


