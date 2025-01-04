#pragma once
#include "DLLEvent.h"

// �ҹ�ģʽ���ɹ����¼���
// �¼�����ʱ������δ���ɡ�
// @param �����¼��� Miscellaneous��
// @return �Ƿ��������ԭ����ӡ�
class VaseBreakerPopulateEvent : public DLLEvent
{
public:
	VaseBreakerPopulateEvent();
};

VaseBreakerPopulateEvent::VaseBreakerPopulateEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onVaseBreakerPopulate");
	hookAddress = 0x4286F0;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_ESI,
		INVOKE(procAddress),
		ADD_ESP(4),
		TEST_AL_AL,
		JNZ(2),
		POPAD,
		RET,
	};
	start(STRING(code));
}