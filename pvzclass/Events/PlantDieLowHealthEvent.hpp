#pragma once
#include "DLLEvent.h"

// ֲ��������ֵС�� 0 ���Ƴ��¼���
// @param �����¼���ֲ�
// @return ��ֲ���Ƿ��Ƴ���
class PlantDieLowHealthEvent : public DLLEvent
{
public:
	PlantDieLowHealthEvent();
};

PlantDieLowHealthEvent::PlantDieLowHealthEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantDieLowHealth");
	hookAddress = 0x463EDD;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_EBX,
		INVOKE(procAddress),
		ADD_ESP(4),
		TEST_AL_AL,
		JE(14),

		PUSH_EBX,
		INVOKE(0x4679B0),

		POPAD,
		MOV_ECX(0x463EE3),
		JMP_REG32(REG_ECX)
	};
	start(STRING(code));
}