#pragma once
#include "DLLEvent.h"

// 植物因生命值小于 0 被移除事件。
// @param 触发事件的植物。
// @return 该植物是否被移除。
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