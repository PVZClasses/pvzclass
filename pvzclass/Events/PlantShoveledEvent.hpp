#pragma once
#include "DLLEvent.h"

// ֲ�ﱻ�����¼���
// @param �����¼���ֲ��
// @return ʵ�ʱ�������ֲ��Ļ�ַ����Ϊ��ָ�룬����¼���ȡ����
class PlantShoveledEvent : public DLLEvent
{
public:
	PlantShoveledEvent();
};

PlantShoveledEvent::PlantShoveledEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantShoveled");
	hookAddress = 0x4111C8;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_EBP,
		INVOKE(procAddress),
		MOV_EUX_EVX(REG_EBP, REG_EAX),
		ADD_ESP(4),

		TEST_EUX_EVX(REG_EBP, REG_EBP),
		JNZ(8),
		POPAD,
		MOV_EAX(0x411268),
		JMP_REG32(REG_EAX)
	};
	start(STRING(code));
}