#pragma once
#include "DLLEvent.h"

class ZombieInitAfterEvent : public DLLEvent
{
public:
	ZombieInitAfterEvent();
};

ZombieInitAfterEvent::ZombieInitAfterEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onZombieInitAfter");
	hookAddress = 0x524035;
	rawlen = 5;
	BYTE code[] = {
		PUSH_EDI,
		INVOKE(procAddress),
		ADD_ESP(4)
	};
	start(STRING(code));
}
