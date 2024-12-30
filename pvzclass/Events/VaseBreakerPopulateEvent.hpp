#pragma once
#include "DLLEvent.h"

// 砸罐模式生成罐子事件。
// 事件触发时罐子尚未生成。
// @param 触发事件的 Miscellaneous。
// @return 是否继续生成原版罐子。
class VaseBreakerPopulateEvent : public DLLEvent
{
public:
	VaseBreakerPopulateEvent();
};

VaseBreakerPopulateEvent::VaseBreakerPopulateEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onVaseBreakerPopulate");
	hookAddress = 0x4286F0;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_ESI,
		INVOKE(procAddress),
		ADD_ESP(4),
		TEST_AL_AL,
		JNZ(2),
		POPAD,
		RET,
	};
	start(STRING(code));
}