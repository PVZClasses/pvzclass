#pragma once
#include "DLLEvent.h"

// 物品被点击事件。
// 已收集的物品可以再次触发此事件，注意过滤。
// @param 依次为：触发事件的物品、点击次数。
// @return 是否继续结算原版过程。
class CoinMouseDownEvent : public DLLEvent
{
public:
	CoinMouseDownEvent();
};

CoinMouseDownEvent::CoinMouseDownEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onCoinMouseDown");
	hookAddress = 0x432C47;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_PTR_ESP_ADD_V(0x7C),
		PUSH_ESI,
		INVOKE(procAddress),
		ADD_ESP(8),

		TEST_AL_AL,
		JNZ(8),
		POPAD,
		MOV_ECX(0x432DBA),
		JMP_REG32(REG_ECX)
	};
	start(STRING(code));
}