#pragma once
#include "DLLEvent.h"

// ֲ�����Ը����¼���
// ʱ�������ڱ��������ԡ�
// @param �����¼���ֲ�
// @return �Ƿ����󲿷�ԭ�����ԡ���Ϊ���񡱣���ֻ�������ֺ�һ����ֲ������ԡ�
class PlantUpdateAbilityEvent : public DLLEvent
{
public:
	PlantUpdateAbilityEvent();
};

PlantUpdateAbilityEvent::PlantUpdateAbilityEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantUpdateAbility");
	hookAddress = 0x463254;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_EDI,
		INVOKE(procAddress),
		ADD_ESP(4),
		TEST_AL_AL,
		JNZ(8),

		POPAD,
		MOV_ECX(0x4633EE),
		JMP_REG32(REG_ECX),

		POPAD,
		INVOKE(0x453840),
		MOV_ECX(0x463259),
		JMP_REG32(REG_ECX),		
	};
	start(STRING(code));
}
#pragma once
