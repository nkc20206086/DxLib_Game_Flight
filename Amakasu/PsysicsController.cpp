#include"PsysicsController.h"

void Psysics::SetCollisionObj(GameObject& obj)
{
	//当たり判定するオブジェクトのコライダー設定を取得
	Collider* ptr = &obj.GetCompornent<Collider>();
	
	//登録されていなかった場合作成
	if (CollisionDic.find(ptr->thisCollision.id) != CollisionDic.end())
	{
		//当たり判定するオブジェクトにidを設定
		ptr->thisCollision.id = ColCount;

		//計算用に登録
		CollisionDic[ColCount] = ptr;
		CollisionDic.insert(std::pair<int, Collider*>(ColCount, ptr));
		//当たったオブジェクトを返すためにオブジェクトを登録
		CollisionGameObjectDic[ColCount] = &obj;
		CollisionGameObjectDic.insert(std::pair<int, GameObject*>(ColCount, &obj));
		ColCount++;
	}
}
GameObject& Psysics::GetCollisionObj(int id)
{
	return  *CollisionGameObjectDic[id];

}
void Psysics::DelateCollision(GameObject& obj)
{

	Collider& ptr = obj.GetCompornent<Collider&>();
	//消したいゲームオブジェクトのIDを取得
	int num = ptr.thisCollision.id;
	CollisionDic.erase(num);
	CollisionGameObjectDic.erase(num);
}
void Psysics::CalculateCollision()
{
	//計算前にオブジェクトの当たり判定フラグをリセットする
	for (unsigned int i = 0; CollisionDic.size() >= i; i++)
	{
		CollisionDic[i]->HitObjDataNum.clear();
	}

	for (int i = CollisionDic.size(); i > 0; --i)
	{
		//比べるオブジェクト
		mainCol = CollisionDic[i]->thisCollision;

		for (int j = 0; j < i; ++j)
		{
			sabuCol = CollisionDic[j]->thisCollision;
			//当たり判定計算
			if
				(
					(sabuCol.colvec.x - mainCol.colvec.x) *
					(sabuCol.colvec.x - mainCol.colvec.x)
					+
					(sabuCol.colvec.y - mainCol.colvec.y) *
					(sabuCol.colvec.y - mainCol.colvec.y)
					+
					(sabuCol.colvec.z - mainCol.colvec.z) *
					(sabuCol.colvec.z - mainCol.colvec.z)
					<=
					sabuCol.lange + mainCol.lange
					*
					sabuCol.lange + mainCol.lange
					)
			{
				//Collisionで受け取りたいからGameobject登録しておきたい
				CollisionGameObjectDic[j]->HitObj.push_back(CollisionGameObjectDic[i]);

				CollisionGameObjectDic[i]->HitObj.push_back(CollisionGameObjectDic[j]);
			}

		}
	}
}