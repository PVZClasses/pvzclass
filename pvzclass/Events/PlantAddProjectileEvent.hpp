#pragma once
#include "DLLEvent.h"

// 植物发射子弹事件。
// 时机上先于子弹索敌类型设定和特殊子弹速度改动。
// @param 依次为：触发事件的植物、生成的子弹、子弹目标僵尸的基址。
// @return 是否继续结算原版的调整。
class PlantAddProjectileEvent : public DLLEvent
{
public:
	PlantAddProjectileEvent();
};

PlantAddProjectileEvent::PlantAddProjectileEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantAddProjectile");
	hookAddress = 0x4672B5;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_PTR_ESP_ADD_V(0x54),
		PUSH_EAX,
		PUSH_EBP,
		INVOKE(procAddress),
		ADD_ESP(0x0C),

		TEST_AL_AL,
		JNZ(6),
		POPAD,
		PUSHDWORD(0x52FDEE),
		RET
	};
	start(STRING(code));
}