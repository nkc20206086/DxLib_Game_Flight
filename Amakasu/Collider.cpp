#include"Collider.h"

void Collider::SetCollisionObj(VECTOR vec, float lenge)
{
	thisCollision.colvec = vec;
	thisCollision.lange = lenge;
}

//void Collider::TestDoubleJudge(ColliderSet Main, ColliderSet Sub)
//{
//
//}
//void Collider::ResetCollisionObj()
//{
//	//HitObjDic.clear();
//}
#pragma region ������œ����蔻��̌v�Z���Ă��܂���

//int Collider::CalculateCollision()
//{
//	for (int i = colObjDic.size(); i > 0; --i)
//	{
//		mainObj = colObjDic[i];
//		//mx = colObjDic[i].transform.position.x;
//		mx = mainObj.transform.position.x;
//		my = mainObj.transform.position.y;
//		mz = mainObj.transform.position.z;
//		mlange = mainObj.GetColliisionSet().lange;
//		for (int j = 0; j < i; ++j)
//		{
//			sabuObj = colObjDic[j];
//			sx = colObjDic[j].transform.position.x;
//			sy = colObjDic[j].transform.position.y;
//			sz = colObjDic[j].transform.position.z;
//			sy = sabuObj.transform.position.y;
//			sz = sabuObj.transform.position.z;
//			slange = sabuObj.GetColliisionSet().lange;
//
//			////	�����蔻��̋V��
//			if (mx - sx * mx - sx + my - sy * my - sy + mz - sz * mz - sz <=
//				slange + mlange * slange + mlange) return 0;
//			{
//				mainObj.HitObj.push_back(sabuObj);
//				sabuObj.HitObj.push_back(mainObj);
//			}
//		}
//
//	}
//	return 1;
//}


#pragma endregion