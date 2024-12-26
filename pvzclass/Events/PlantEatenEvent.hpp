#pragma once
#include "DLLEvent.h"

// 植物被啃死事件。
// @param 依次为：触发事件的植物、啃食该植物的僵尸。
// @return 是否跳过原版的结算过程（即不被啃死）。
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
		ADD_ESP(8)
	};
	start(STRING(code));
}