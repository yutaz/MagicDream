#pragma once
//使用ヘッダー
#include"GameL\SceneObjManager.h"
//使用ネームスペース
using namespace GameL;


//オブジェクト：通常弾
class CObjBullet :public CObj
{
public:
	CObjBullet(float x, float y);//コンストラクタ
	~CObjBullet(){}
	void Init();//イニット
	void Action();//アクション
	void Draw();//ドロー

private:
	float m_x; //弾のX方向の位置用の変数
	float m_y;//弾のY方向の位置用の変数
	float m_vx;//弾のX方向の速度用の変数

};

