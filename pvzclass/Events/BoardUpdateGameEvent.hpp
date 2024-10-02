#pragma once
#include "DLLEvent.h"

class BoardUpdateGameEvent : public DLLEvent
{
public:
	BoardUpdateGameEvent();
};

// Board 游戏更新事件
// 参数：触发事件的 Board 的指针
// 无返回值
// 该事件的触发频率受“僵尸快跑”加速影响。
BoardUpdateGameEvent::BoardUpdateGameEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onBoardUpdateGame");
	hookAddress = 0x415926;
	rawlen = 6;
	BYTE code[] = {
		PUSH_EUX(REG_ECX),
		INVOKE(procAddress),
		ADD_ESP(4)
	};
	start(STRING(code));
}
