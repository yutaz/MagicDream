#pragma once
#include <Windows.h>

namespace GameL
{
	typedef class CMultiThread
	{
		public:
			static void Init(void(*game_sub)());
			static void Delete();
			static void End();
			static bool GetEnd();
		private:

			static unsigned __stdcall GameThread(void *p);	//�Q�[���X���b�h�p���\�b�h
			static bool   m_execution;						//�X���b�h���s�t���O
			static CRITICAL_SECTION m_cs;					//�N���e�B�J���Z�N�V����
			static HANDLE m_handoru_game;					//�Q�[���X���b�h
	}GameLoop;
};