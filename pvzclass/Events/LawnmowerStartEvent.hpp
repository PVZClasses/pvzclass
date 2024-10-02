#pragma once
#include "DLLEvent.h"

class LawnmowerStartEvent : public DLLEvent
{
public:
	LawnmowerStartEvent();
};

LawnmowerStartEvent::LawnmowerStartEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onLawnmowerStart");
	hookAddress = 0x458DB0;
	rawlen = 6;
	BYTE code[] = {
		PUSH_ESI,
		INVOKE(procAddress),
		ADD_ESP(4)
	};
	start(STRING(code));
}
