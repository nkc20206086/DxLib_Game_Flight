//#include"UI_Creater.h"
//#include<DxLib.h>
//int UI_Create::CreateUIGroupHandle(int _orderInlayer)
//{
//	UIGroupCore uiGcore = UIGroupCore();
//	uiGcore.orderInlayer = _orderInlayer;
//	_uihandleCount++;
//	UIDic[_uihandleCount] = uiGcore;
//
//	return _uihandleCount;
//}
//bool UI_Create::UIAdd(int _handle, int _spritehandle, MyVec3 position)
//{
//	auto itr = UIDic.find(_handle);
//	if (itr == UIDic.end()) return false;//そのハンドルが無かったらfalseを返してリターン
//
//	UICore uicore = UICore();
//	uicore.spritehandle = _spritehandle;
//	uicore.pos = position;
//
//	//auto temp=UIDic
//	return true;
//}
//bool UI_Create::UIAdd(int handle, string text, float size, MyVec3 position)
//{
//	UITextCore textcore = UITextCore();
//	textcore.text = text;
//	textcore.size = size;
//	textcore.pos = position;
//	return true;
//}
//
////実際に描画
//bool UI_Create::DrowUI()
//{
//	for (int i = 0; i < (signed)UIDic.size(); i++)
//	{
//		switch (UIDic[i + 1].orderInlayer)
//		{
//		case -10:
//			drawGroupm10[i] = UIDic[i + 1];
//			break;
//		case -9:
//			drawGroupm9[i] = UIDic[i + 1];
//			break;
//		case -8:
//			drawGroupm8[i] = UIDic[i + 1];
//			break;
//		case -7:
//			drawGroupm7[i] = UIDic[i + 1];
//			break;
//		case -6:
//			drawGroupm6[i] = UIDic[i + 1];
//			break;
//		case -5:
//			drawGroupm5[i] = UIDic[i + 1];
//			break;
//		case -4:
//			drawGroupm4[i] = UIDic[i + 1];
//			break;
//		case -3:
//			drawGroupm3[i] = UIDic[i + 1];
//			break;
//		case -2:
//			drawGroupm2[i] = UIDic[i + 1];
//			break;
//		case -1:
//			drawGroupm1[i] = UIDic[i + 1];
//			break;
//		case 0:
//			drawGroup0[i] = UIDic[i + 1];
//			break;
//		case 1:
//			drawGroup1[i] = UIDic[i + 1];
//			break;
//		case 2:
//			drawGroup2[i] = UIDic[i + 1];
//			break;
//		case 3:
//			drawGroup3[i] = UIDic[i + 1];
//			break;
//		case 4:
//			drawGroup4[i] = UIDic[i + 1];
//			break;
//		case 5:
//			drawGroup5[i] = UIDic[i + 1];
//			break;
//		case 6:
//			drawGroup6[i] = UIDic[i + 1];
//			break;
//		case 7:
//			drawGroup7[i] = UIDic[i + 1];
//			break;
//		case 8:
//			drawGroup8[i] = UIDic[i + 1];
//			break;
//		case 9:
//			drawGroup9[i] = UIDic[i + 1];
//			break;
//		case 10:
//			drawGroup10[i] = UIDic[i + 1];
//			break;
//		}
//	}
//	return true;
//}