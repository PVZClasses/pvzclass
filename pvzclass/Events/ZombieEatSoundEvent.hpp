#pragma once
#include "DLLEvent.h"

// ���Ž�ʬ��ʳ��Ч���¼���
// �Ȼ󹽺ʹ����ڴ�ʱ���������á�
// @param ����Ϊ�������¼��Ľ�ʬ�������ʳ��ֲ�
// @return ʵ�ʱ���ʳ��ֲ��Ļ�ַ����Ϊ��ָ�룬ȡ�����¼���ֲ��Ĺ�ϵ��
class ZombieEatSoundEvent : public DLLEvent
{
public:
	ZombieEatSoundEvent();
};

ZombieEatSoundEvent::ZombieEatSoundEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onZombieEatSound");
	hookAddress = 0x52B964;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_ESI,
		PUSH_EDI,
		INVOKE(procAddress),
		MOV_EUX_EVX(REG_ESI, REG_EAX),
		ADD_ESP(8),

		TEST_EUX_EVX(REG_ESI, REG_ESI),
		JNZ(8),
		POPAD,
		MOV_EAX(0x52BAD7),
		JMP_REG32(REG_EAX)
	};
	start(STRING(code));
}
