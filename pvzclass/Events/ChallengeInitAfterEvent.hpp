#pragma once
#include "DLLEvent.h"

// 关卡初始化后的事件。
// 无返回值
// @param 触发事件的 Miscellaneous
class ChallengeInitAfterEvent : public DLLEvent
{
public:
	ChallengeInitAfterEvent();
};

ChallengeInitAfterEvent::ChallengeInitAfterEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onChallengeInitAfter");
	hookAddress = 0x41F6D8;
	rawlen = 5;
	BYTE code[] = { PUSH_EDI, INVOKE(procAddress), ADD_ESP(4) };
	start(STRING(code));
}
