#pragma once
#include "DLLEvent.h"

// 播放僵尸啃食音效的事件。
// 魅惑菇和大蒜在此时机发挥作用。
// @param 依次为：触发事件的僵尸、被其啃食的植物。
// @return 实际被啃食的植物的基址。若为空指针，取消该事件与植物的关系。
class ZombieEatSoundEvent : public DLLEvent
{
public:
	ZombieEatSoundEvent();
};

ZombieEatSoundEvent::ZombieEatSoundEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onZombieEatSound");
	hookAddress = 0x52B964;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_ESI,
		PUSH_EDI,
		INVOKE(procAddress),
		MOV_EUX_EVX(REG_ESI, REG_EAX),
		ADD_ESP(8),

		TEST_EUX_EVX(REG_ESI, REG_ESI),
		JNZ(8),
		POPAD,
		MOV_EAX(0x52BAD7),
		JMP_REG32(REG_EAX)
	};
	start(STRING(code));
}
