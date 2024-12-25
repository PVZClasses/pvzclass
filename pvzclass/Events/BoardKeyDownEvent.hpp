#pragma once
#include "DLLEvent.h"

// 关卡内键盘按键事件。
// 优先级高于原版事件。
// @param 依次为：触发事件的 Board，按键的 KeyCode。
// @return 是否继续结算原版事件。
class BoardKeyDownEvent : public DLLEvent
{
public:
	BoardKeyDownEvent();
};

BoardKeyDownEvent::BoardKeyDownEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onBoardKeyDown");
	hookAddress = 0x41B820;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_PTR_ESP_ADD_V(0x24),
		PUSH_ECX,
		INVOKE(procAddress),
		ADD_ESP(0x08)
	};
	start(STRING(code));
}