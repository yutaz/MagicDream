//�g�p�w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"CObjBullet.h"
#include"GameL\HitBoxManager.h"

//�g�p�l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//Init
void CObjBullet::Init()
{
	m_vx = 0.0f;

	//�����蔻��p��HITBOX�쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}
//Action
void CObjBullet::Action()
{
	m_vx += 1.0f;

    m_x+= m_vx;


	//�e�̓����蔻��iHITBOX)�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);//HitBox�̈ʒu��e�̈ʒu�ɍX�V

	//�G�ƐڐG������e�폜
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{

	}

}

//Draw�i�ʏ�e�̕`��j
void CObjBullet::Draw()
{
	//�`��J���[��� R   G    B     A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�̐؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;//��̈ʒu
	src.m_left = 0.0f;//���̈ʒu
	src.m_right = 0.0f;//�E�܂ł̈ʒu
	src.m_bottom = 0.0f;//���̈ʒu

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;//��
	dst.m_left = 0.0f;//��
	dst.m_right = 0.0f;//�E
	dst.m_bottom = 0.0f;//��

	//0�Ԗڂɓo�^�����O���t�B�b�N��src,dst,c�̏������ɕ`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}