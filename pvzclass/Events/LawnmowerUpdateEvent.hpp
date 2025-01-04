#pragma once
#include "DLLEvent.h"

// С�Ƴ������¼���
// ʱ��������ԭ��������в�����
// @param �����¼���С�Ƴ��Ļ�ַ��
// @return �Ƿ��������ԭ����¡�
class LawnmowerUpdateEvent : public DLLEvent
{
public:
	LawnmowerUpdateEvent();
};

LawnmowerUpdateEvent::LawnmowerUpdateEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onLawnmowerUpdate");
	hookAddress = 0x4586E0;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_PTR_ESP_ADD_V(0x24),
		INVOKE(procAddress),
		ADD_ESP(4),

		TEST_AL_AL,
		JNZ(4),
		POPAD,
		RETN(4)
	};
	start(STRING(code));
}