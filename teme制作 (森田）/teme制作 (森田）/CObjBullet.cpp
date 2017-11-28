//使用ヘッダー
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"CObjBullet.h"
#include"GameL\HitBoxManager.h"

//使用ネームスペース
using namespace GameL;

//コンストラクタ
CObjBullet::CObjBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//Init
void CObjBullet::Init()
{
	m_vx = 0.0f;

	//当たり判定用のHITBOX作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}
//Action
void CObjBullet::Action()
{
	m_vx += 1.0f;

    m_x+= m_vx;


	//弾の当たり判定（HITBOX)更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);//HitBoxの位置を弾の位置に更新

	//敵と接触したら弾削除
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{

	}

}

//Draw（通常弾の描画）
void CObjBullet::Draw()
{
	//描画カラー情報 R   G    B     A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元の切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;//上の位置
	src.m_left = 0.0f;//左の位置
	src.m_right = 0.0f;//右までの位置
	src.m_bottom = 0.0f;//下の位置

	//表示位置の設定
	dst.m_top = 0.0f;//上
	dst.m_left = 0.0f;//左
	dst.m_right = 0.0f;//右
	dst.m_bottom = 0.0f;//下

	//0番目に登録したグラフィックをsrc,dst,cの情報を元に描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}