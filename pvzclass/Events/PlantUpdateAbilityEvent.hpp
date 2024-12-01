#pragma once
#include "DLLEvent.h"

// 植物特性更新事件。
// 时机上先于保龄球特性。
// @param 触发事件的植物。
// @return 是否结算大部分原版特性。若为“否”，则只结算射手和一次性植物的特性。
class PlantUpdateAbilityEvent : public DLLEvent
{
public:
	PlantUpdateAbilityEvent();
};

PlantUpdateAbilityEvent::PlantUpdateAbilityEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantUpdateAbility");
	hookAddress = 0x463254;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_EDI,
		INVOKE(procAddress),
		ADD_ESP(4),
		TEST_AL_AL,
		JNZ(8),

		POPAD,
		MOV_ECX(0x4633EE),
		JMP_REG32(REG_ECX),

		POPAD,
		INVOKE(0x453840),
		MOV_ECX(0x463259),
		JMP_REG32(REG_ECX),		
	};
	start(STRING(code));
}
#pragma once
