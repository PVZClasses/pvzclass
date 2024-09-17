#pragma once
#include "DLLEvent.h"

class IZLevelStartAfterEvent : public DLLEvent
{
public:
	IZLevelStartAfterEvent();
};

IZLevelStartAfterEvent::IZLevelStartAfterEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onIZLevelStartAfter");
	hookAddress = 0x42B286;
	rawlen = 7;
	BYTE code[] = { PUSH_EDX, INVOKE(procAddress), ADD_ESP(4) };
	start(STRING(code));
}
