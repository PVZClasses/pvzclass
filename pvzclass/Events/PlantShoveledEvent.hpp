#pragma once
#include "DLLEvent.h"

// 植物被铲除事件。
// @param 触发事件的植物
// @return 实际被产出的植物的基址。若为空指针，则该事件被取消。
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