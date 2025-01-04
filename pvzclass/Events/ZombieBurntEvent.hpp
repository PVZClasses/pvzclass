#pragma once
#include "DLLEvent.h"

// 僵尸受到灰烬伤害事件。
// @param 触发事件的僵尸
// @return 实际结算灰烬伤害的僵尸的基址。若为空指针，则该事件被取消。
class ZombieBurntEvent : public DLLEvent
{
public:
	ZombieBurntEvent();
};

ZombieBurntEvent::ZombieBurntEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onZombieBurnt");
	hookAddress = 0x532B70;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_ECX,
		INVOKE(procAddress),
		MOV_EUX_EVX(REG_ECX, REG_EAX),
		ADD_ESP(4),

		TEST_EUX_EVX(REG_ECX, REG_ECX),
		JNZ(2),
		POPAD,
		RET
	};
	start(STRING(code));
}