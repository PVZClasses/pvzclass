#pragma once
#include "DLLEvent.h"

class IZLevelCompleteEvent : public DLLEvent
{
public:
	IZLevelCompleteEvent();
};

IZLevelCompleteEvent::IZLevelCompleteEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onIZLevelComplete");
	hookAddress = 0x42B8FC;
	rawlen = 7;
	BYTE code[] = { PUSH_ECX, INVOKE(procAddress), ADD_ESP(4) };
	start(STRING(code));
}
