#pragma once
#include "DLLEvent.h"

// ��Ϸģʽ���Ը����¼���
// @param �����¼��� Challenge
// @return �Ƿ�ԭ��ģʽ�����¼���
class ChallengeUpdateEvent : public DLLEvent
{
public:
	ChallengeUpdateEvent();
};

ChallengeUpdateEvent::ChallengeUpdateEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onChallengeUpdate");
	hookAddress = 0x4246B0;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_EAX,
		INVOKE(procAddress),
		ADD_ESP(4),

		TEST_AL_AL,
		JNZ(1),
		RET
	};
	start(STRING(code));
}
