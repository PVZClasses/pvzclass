#pragma once
#include "DLLEvent.h"

// ������Ʒ�Ƴ��¼���
// @param �����¼��ĳ�����Ʒ��
// @return �Ƿ��Ƴ�����Ʒ��
class GriditemDieEvent : public DLLEvent
{
public:
	GriditemDieEvent();
};

GriditemDieEvent::GriditemDieEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onGriditemDie");
	hookAddress = 0x44D000;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_ESI,
		INVOKE(procAddress),
		ADD_ESP(4),

		TEST_AL_AL,
		JNZ(2),
		POPAD,
		RET
	};
	start(STRING(code));
}