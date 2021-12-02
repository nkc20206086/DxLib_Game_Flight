#pragma once
#include "DxLib.h"

class ShowGrid
{
public:

	// �f�o�b�O�p�̃O���b�h���̐F��ݒ�
	void SetGridColor(int red, int green, int blue)
	{
		lineColor = GetColor(red, green, blue);
	}

	// �f�o�b�O�p�̃O���b�h�����쐬
	// useZBuffer : Z�o�b�t�@���g�p���邩�ǂ����B�g�����ق��������Ǝv��
	// lineNum	  : �������C���̐�
	// lineArea   : ���C���������͈�
	void MakeGrid(BOOL useZBuffer, int lineNum, float lineArea)
	{
		VECTOR Pos1;
		VECTOR Pos2;
		unsigned int _lineNum = lineNum;
		float _lineArea = lineArea;

		if (useZBuffer == TRUE)
		{
			// Z�o�b�t�@���g�p����
			SetUseZBufferFlag(TRUE);
		}

		Pos1 = VGet(-_lineArea / 2.0f, 0.0f, -_lineArea / 2.0f);
		Pos2 = VGet(-_lineArea / 2.0f, 0.0f, _lineArea / 2.0f);

		for (int i = 0; i <= _lineNum; i++)
		{
			DrawLine3D(Pos1, Pos2, lineColor);
			Pos1.x += _lineArea / _lineNum;
			Pos2.x += _lineArea / _lineNum;
		}
		Pos1 = VGet(-_lineArea / 2.0f, 0.0f, -_lineArea / 2.0f);
		Pos2 = VGet(_lineArea / 2.0f, 0.0f, -_lineArea / 2.0f);
		for (int i = 0; i <= _lineNum; i++)
		{
			DrawLine3D(Pos1, Pos2, lineColor);
			Pos1.z += _lineArea / _lineNum;
			Pos2.z += _lineArea / _lineNum;
		}

		// Z�o�b�t�@�g�p����̂��f�t�H���g�ɖ߂�
		SetUseZBufferFlag(FALSE);
	};

private:
	unsigned int lineColor = GetColor(255, 255, 255);
};

