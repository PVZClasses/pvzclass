#pragma once
#include "DLLEvent.h"

// 植物被碾压事件。
// @param 触发事件的植物。
// @return 更新后被碾压的植物。返回空指针时该事件被取消。
class PlantSquishEvent : public DLLEvent
{
public:
	PlantSquishEvent();
};

PlantSquishEvent::PlantSquishEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantSquish");
	hookAddress = 0x462B80;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_PTR_ESP_ADD_V(0x24),
		INVOKE(procAddress),
		ADD_ESP(4),
		TEST_EUX_EVX(REG_EAX, REG_EAX),
		JNZ(4),
		POPAD,
		RETN(4),
		MOV_PTR_ESP_ADD_V_EUX(REG_EAX, 0x24)
	};
	start(STRING(code));
}