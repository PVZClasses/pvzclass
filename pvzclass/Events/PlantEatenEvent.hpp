#pragma once
#include "DLLEvent.h"

// 植物被啃死事件。
// @param 依次为：触发事件的植物、啃食该植物的僵尸。
// @return 是否继续结算原版的结算过程。
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