#pragma once
#include "DLLEvent.h"

// ��ʬ��ͷ�¼���
// @param �ܵ�ͷ�˺��Ľ�ʬ�Ļ�ַ���˺���ǩ
// @return �Ƿ�������������˺�
class ZombieDropHeadEvent : public DLLEvent
{
public:
	ZombieDropHeadEvent();
};

ZombieDropHeadEvent::ZombieDropHeadEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onZombieDropHead");
	hookAddress = 0x529A30;
	rawlen = 6;
	BYTE code[] = {
		PUSH_PTR_ESP_ADD_V(0x28),
		PUSH_PTR_ESP_ADD_V(0x28),
		INVOKE(procAddress),
		ADD_ESP(8),

		TEST_AL_AL,
		JNZ(4),
		POPAD,
		RETN(8)
	};
	start(STRING(code));
}
