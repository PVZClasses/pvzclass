#pragma once
#include "DLLEvent.h"

// ���ۿ��Ʊ���ѡ�¼���
// ʱ��������ԭ���ָ�
// @param �����¼��Ŀ��ۿ��ơ�
// @return �Ƿ��������ԭ���ָ�
class SeedPacketMouseDownEvent : public DLLEvent
{
public:
	SeedPacketMouseDownEvent();
};

SeedPacketMouseDownEvent::SeedPacketMouseDownEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantAddProjectile");
	hookAddress = 0x4672B5;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_EBP,
		INVOKE(procAddress),
		ADD_ESP(4),

		TEST_AL_AL,
		JNZ(8),
		POPAD,
		MOV_ECX(0x488EA6),
		JMP_REG32(REG_ECX)
	};
	start(STRING(code));
}