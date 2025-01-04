#pragma once
#include "DLLEvent.h"

// ֲ�������Ʒ�¼���
// @param �����¼���ֲ��
// @return �Ƿ��������ԭ����Ʒ��
class PlantProduceEvent : public DLLEvent
{
public:
	PlantProduceEvent();
};

PlantProduceEvent::PlantProduceEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantProduce");
	hookAddress = 0x45FAA7;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_EDI,
		INVOKE(procAddress),
		ADD_ESP(4),

		TEST_AL_AL,
		JNZ(8),
		POPAD,
		MOV_EAX(0x45FB64),
		JMP_REG32(REG_EAX)
	};
	start(STRING(code));
}