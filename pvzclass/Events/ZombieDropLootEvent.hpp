#pragma once
#include "DLLEvent.h"

// ��ʬ������Ʒ�¼���
// �ѵ����������Ʒ�Ľ�ʬ�����ٴε�����Ʒ��
// ������������Ʒ�Ľ�ʬ�ĵ�ַ
// �޷���ֵ
class ZombieDropLootEvent : public DLLEvent
{
public:
	ZombieDropLootEvent();
};

ZombieDropLootEvent::ZombieDropLootEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onZombieDropLoot");
	hookAddress = 0x5301C0;
	rawlen = 7;
	BYTE code[] = {
		PUSH_EBX,
		INVOKE(procAddress),
		ADD_ESP(4)
	};
	start(STRING(code));
}
