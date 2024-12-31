#pragma once
#include "DLLEvent.h"

// 植物被偷走事件。
// 无返回值
// @param 依次为：触发事件的植物、啃食该植物的僵尸。
class PlantStolenEvent : public DLLEvent
{
public:
	PlantStolenEvent();
};

PlantStolenEvent::PlantStolenEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantStolen");
	hookAddress = 0x5304B6;
	rawlen = 7;
	BYTE code[] =
	{
		PUSH_EAX,
		INVOKE(procAddress),
		ADD_ESP(4),
	};
	start(STRING(code));
}