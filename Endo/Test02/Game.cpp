#include <DxLib.h>
#include "GameObject.h"

// ��ʃT�C�Y
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// �V�[���J�ڗpENUM
enum class SCENE : unsigned int
{
	NONE = 0,
	TITLE,
	GAME,
	RESULT,

	EXIT,
	NUM,
};


// �^�C�g���V�[���N���X
class Title : public GameObject
{
public:
	Title()
	{

	}

	void Init() override
	{

	}

	void Update() override
	{

	}

};

// �Q�[���I�[�o�[�V�[���N���X
class GameOver : public GameObject
{
public:
	GameOver()
	{

	}

	void Init() override
	{

	}

	void Update() override
	{

	}

};

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ɕύX

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	// ��ʃT�C�Y�̐ݒ�



	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);		// �_�u���o�b�t�@���[�h

	SCENE scene = SCENE::TITLE;

	while (ProcessMessage() == 0)	// �Q�[���̃��C�����[�v
	{

	}

	WaitKey();				// �L�[���͑҂�

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}