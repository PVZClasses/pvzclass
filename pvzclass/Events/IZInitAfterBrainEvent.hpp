#pragma once
#include "DLLEvent.h"

// IZ �ؿ���ʼ���¼�
// ��ʱ������������ɣ���ֲ����δ���á�
// �����������¼��� Challenge
// ����ֵ���Ƿ����ɹؿ�Ĭ�����ɵ�ֲ��
class IZInitAfterBrainEvent : public DLLEvent
{
public:
	IZInitAfterBrainEvent();
};

IZInitAfterBrainEvent::IZInitAfterBrainEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onIZInitAfterBrain");
	hookAddress = 0x42A981;
	rawlen = 6;
	BYTE code[] = { PUSH_EDI, INVOKE(procAddress), ADD_ESP(4), TEST_AL_AL, JNZ(8), POPAD, MOV_EDX(0x42B277), 0xFF, 0XE2};
	start(STRING(code));
}
#pragma once
