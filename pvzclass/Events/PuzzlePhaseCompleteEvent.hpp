#pragma once
#include "DLLEvent.h"

// ���չؿ�����¼�
// �����������¼�ʱ�� Challenge
// �޷���ֵ
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