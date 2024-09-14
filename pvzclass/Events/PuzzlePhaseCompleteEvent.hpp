#pragma once
#include "DLLEvent.h"

// 解谜关卡完成事件
// 参数：触发事件时的 Challenge
// 无返回值
class PuzzlePhaseCompleteEvent : public DLLEvent
{
public:
	PuzzlePhaseCompleteEvent();
};

PuzzlePhaseCompleteEvent::PuzzlePhaseCompleteEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPuzzlePhaseComplete");
	hookAddress = 0x429980;
	rawlen = 6;
	BYTE code[] = { PUSH_ECX, INVOKE(procAddress), ADD_ESP(4) };
	start(STRING(code));
}