#pragma once
#include "DLLEvent.h"

// 游戏模式特性更新事件。
// @param 触发事件的 Challenge
// @return 是否按原版模式更新事件。
class ChallengeUpdateEvent : public DLLEvent
{
public:
	ChallengeUpdateEvent();
};

ChallengeUpdateEvent::ChallengeUpdateEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onChallengeUpdate");
	hookAddress = 0x4246B0;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_EAX,
		INVOKE(procAddress),
		ADD_ESP(4),

		TEST_AL_AL,
		JNZ(1),
		RET
	};
	start(STRING(code));
}
