#pragma once
#include "DLLEvent.h"

class PlantDoSpecialEvent : public DLLEvent
{
public:
	PlantDoSpecialEvent();
};

PlantDoSpecialEvent::PlantDoSpecialEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantDoSpecial");
	hookAddress = 0x4666A0;
	rawlen = 6;
	BYTE code[] = {
		PUSH_PTR_ESP_ADD_V(0x24),
		INVOKE(procAddress),
		ADD_ESP(4),
	};
	start(STRING(code));
}
#pragma once
