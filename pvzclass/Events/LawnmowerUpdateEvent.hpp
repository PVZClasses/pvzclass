#pragma once
#include "DLLEvent.h"

// 小推车更新事件。
// 时机上先于原版更新所有操作。
// @param 触发事件的小推车的基址。
// @return 是否继续结算原版更新。
class LawnmowerUpdateEvent : public DLLEvent
{
public:
	LawnmowerUpdateEvent();
};

LawnmowerUpdateEvent::LawnmowerUpdateEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onLawnmowerUpdate");
	hookAddress = 0x4586E0;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_PTR_ESP_ADD_V(0x24),
		INVOKE(procAddress),
		ADD_ESP(4),

		TEST_AL_AL,
		JNZ(4),
		POPAD,
		RETN(4)
	};
	start(STRING(code));
}