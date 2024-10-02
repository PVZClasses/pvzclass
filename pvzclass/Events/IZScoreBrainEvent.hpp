#pragma once
#include "DLLEvent.h"

class IZScoreBrainEvent : public DLLEvent
{
public:
	IZScoreBrainEvent();
};

IZScoreBrainEvent::IZScoreBrainEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onIZScoreBrain");
	hookAddress = 0x42B8B3;
	rawlen = 6;
	BYTE code[] = {
		PUSH_EBX,
		INVOKE(procAddress),
		ADD_ESP(4)
	};
	start(STRING(code));
}
