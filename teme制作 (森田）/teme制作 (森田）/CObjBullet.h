#pragma once
//�g�p�w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p�l�[���X�y�[�X
using namespace GameL;


//�I�u�W�F�N�g�F�ʏ�e
class CObjBullet :public CObj
{
public:
	CObjBullet(float x, float y);//�R���X�g���N�^
	~CObjBullet(){}
	void Init();//�C�j�b�g
	void Action();//�A�N�V����
	void Draw();//�h���[

private:
	float m_x; //�e��X�����̈ʒu�p�̕ϐ�
	float m_y;//�e��Y�����̈ʒu�p�̕ϐ�
	float m_vx;//�e��X�����̑��x�p�̕ϐ�

};

