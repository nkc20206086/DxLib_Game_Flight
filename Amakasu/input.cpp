#include"inputTest.h"
//������MyInput�̒�`���s��
MyInput::MyInput()//�R���X�g���N�^
{
	for (int i = 0; i < KEY_MAX; i++)
	{
		key[0] = 0;
		oldkey[0] = 0;
	}
}
MyInput::~MyInput()//�f�X�g���N�^
{
}
void MyInput::SetInputState()//������ŏ��ɌĂ�
{
	GetHitKeyStateAll(key); //key�ɃC���v�b�g�̒l������
}
void MyInput::SetInputStateOld()//�Ō�ɌĂ�
{
	for (int i = 0; i < KEY_MAX; ++i)
	{
		oldkey[i] = key[i];
	}
}

//���������C���v�b�g������Ƃ�����
bool MyInput::GetKey(int v_key/*[KEY_MAX]*/)//�����͉����ꂽ���m�F�������L�[�̔ԍ�
{
	return key[v_key] == 1 ? true : false;
}
bool MyInput::GetKeyDown(int v_key)
{
	if (key[v_key] == 0) return false;
	return (oldkey[v_key] == 0) ? true : false;
}
bool MyInput::GetKeyUp(int v_key)
{
	if (key[v_key] == 1) return false;
	return (oldkey[v_key] == 1) ? true : false;
}