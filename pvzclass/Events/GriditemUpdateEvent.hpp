#pragma once
#include "DLLEvent.h"

// Griditem 更新事件
// 参数：更新的 Griditem
// 无返回值
// 时机上先于原版更新。
class GriditemUpdateEvent : public DLLEvent
{
public:
	GriditemUpdateEvent();
};

GriditemUpdateEvent::GriditemUpdateEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onGriditemUpdate");
	hookAddress = 0x44E5E0;
	rawlen = 5;
	BYTE code[] = { PUSH_EAX, INVOKE(procAddress), ADD_ESP(4) };
	start(STRING(code));
}
