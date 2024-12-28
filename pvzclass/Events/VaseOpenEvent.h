#pragma once
#include "DLLEvent.h"

// 开罐事件。
// 时机上优先级高于开罐的其他操作。
// @param 依次为：触发事件的 Miscellaneous、触发该事件的罐子基址。
// @return 是否继续结算罐子被砸开的事件。返回“否”会阻止罐子被敲开。
class VaseOpenEvent : public DLLEvent
{
public:
	VaseOpenEvent();
};

VaseOpenEvent::VaseOpenEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onVaseOpen");
	hookAddress = 0x429AC0;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_PTR_ESP_ADD_V(0x28),
		PUSH_PTR_ESP_ADD_V(0x28),
		INVOKE(procAddress),
		ADD_ESP(8),

		TEST_AL_AL,
		JNZ(3),
		RETN(8)
	};
	start(STRING(code));
}