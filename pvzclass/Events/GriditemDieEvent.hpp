#pragma once
#include "DLLEvent.h"

// 场地物品移除事件。
// @param 触发事件的场地物品。
// @return 是否移除此物品。
class GriditemDieEvent : public DLLEvent
{
public:
	GriditemDieEvent();
};

GriditemDieEvent::GriditemDieEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onGriditemDie");
	hookAddress = 0x44D000;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_ESI,
		INVOKE(procAddress),
		ADD_ESP(4),

		TEST_AL_AL,
		JNZ(2),
		POPAD,
		RET
	};
	start(STRING(code));
}