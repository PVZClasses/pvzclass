#pragma once
#include "DLLEvent.h"

// Zombie ��Ϊ�����ĸ��¡�
// ʱ��������ԭ��ĸ��¡�
// ���������µ� Zombie
// �޷���ֵ
class ZombieUpdateActionEvent : public DLLEvent
{
public:
	ZombieUpdateActionEvent();
};

ZombieUpdateActionEvent::ZombieUpdateActionEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onZombieUpdateAction");
	hookAddress = 0x52B112;
	rawlen = 6;
	BYTE code[] = { PUSH_EAX, INVOKE(procAddress), ADD_ESP(4) };
	start(STRING(code));
}
