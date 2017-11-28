#include <process.h>
#include "MultiThread.h"


using namespace GameL;

bool			 CMultiThread::m_execution;		//�X���b�h���s�t���O
CRITICAL_SECTION CMultiThread::m_cs;			//�N���e�B�J���Z�N�V����
HANDLE			 CMultiThread::m_handoru_game;	//�Q�[���X���b�h

bool CMultiThread::GetEnd()
{
	return m_execution;	
}

//������
void CMultiThread::Init( void(*game_sub)() )
{
	m_handoru_game =nullptr;
	m_execution	   =true;

	//�N���e�B�J���Z�N�V�����N��
	InitializeCriticalSection(&m_cs);

	//�X���b�h�N��
	m_handoru_game = (HANDLE)_beginthreadex(NULL, 0, GameThread ,(void *)game_sub , 0, NULL);
	
}

//�폜
void CMultiThread::Delete()
{
	//�X���b�h�I���t���O�𗧂Ă�
	End();
	//�X���b�h�I���m�F
	WaitForSingleObject(m_handoru_game , INFINITE);
    //�X���b�h�I��
	CloseHandle(m_handoru_game);
	//�N���e�B�J���Z�N�V�����I��
	DeleteCriticalSection(&m_cs);

}

//�Q�[���X���b�h��~���\�b�h
void CMultiThread::End()
{
	EnterCriticalSection(&m_cs);
	m_execution=false;
	LeaveCriticalSection(&m_cs);
}

//�Q�[���X���b�h�p���\�b�h
unsigned __stdcall CMultiThread::GameThread(void *p)
{
	void (*sub)() = (void(*)()) p;
	
	//�Q�[�����[�v
	while(m_execution)
	{
		sub();
	}

    _endthreadex(0);
    return 0;
}