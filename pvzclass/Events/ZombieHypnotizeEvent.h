#pragma once
#include "DLLEvent.h"

// ��ʬ���Ȼ��¼�
// �����������¼��Ľ�ʬ
// ����ֵ���Ƿ������¼�����Ϊ���񡱣��˴��Ȼ󽫱�ȡ����
class ZombieHypnotizeEvent : public DLLEvent
{
public:
	ZombieHypnotizeEvent();
};

ZombieHypnotizeEvent::ZombieHypnotizeEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onZombieHypnotize");
	hookAddress = 0x52FA60;
	rawlen = 10;
	BYTE code[] = { PUSH_ESI, INVOKE(procAddress), ADD_ESP(4), TEST_AL_AL, JNZ(2), POPAD, RET};
	start(STRING(code));
}
