#pragma once
#include "DLLEvent.h"

// ֲ�ﱻ�����¼���
// @param ����Ϊ�������¼���ֲ���ʳ��ֲ��Ľ�ʬ��
// @return �Ƿ��������ԭ��Ľ�����̡�
class PlantEatenEvent : public DLLEvent
{
public:
	PlantEatenEvent();
};

PlantEatenEvent::PlantEatenEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantEaten");
	hookAddress = 0x52FD3D;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_EBP,
		PUSH_ESI,
		INVOKE(procAddress),
		ADD_ESP(8),

		TEST_AL_AL,
		JNZ(6),
		POPAD,
		PUSHDWORD(0x52FDEE),
		RET
	};
	start(STRING(code));
}