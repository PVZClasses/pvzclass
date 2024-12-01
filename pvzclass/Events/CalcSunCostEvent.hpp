#pragma once
#include "DLLEvent.h"

class CalcSunCostEvent : public DLLEvent
{
public:
	CalcSunCostEvent();
};

CalcSunCostEvent::CalcSunCostEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("getCardCost");
	hookAddress = 0x467B06;
	rawlen = 6;
	BYTE code[] = {
		PUSH_EAX,
		INVOKE(procAddress),
		ADD_ESP(4),
		CMP_EUX(REG_EAX, -1),
		JE(6),
		MOV_PTR_ESP_ADD_V_EUX(REG_EAX, 0x1C),
		POPAD,
		RET
	};
	start(STRING(code));
}
