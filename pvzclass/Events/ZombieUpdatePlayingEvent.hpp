#pragma once
#include "DLLEvent.h"

// Zombie ��ɫ�ĸ��£������ᡢ���Ͷ���ʱҲ����㡣
// ʱ��������ԭ��ĸ��¡�
// ���������µ� Zombie
// �޷���ֵ
class ZombieUpdatePlayingEvent : public DLLEvent
{
public:
	ZombieUpdatePlayingEvent();
};

ZombieUpdatePlayingEvent::ZombieUpdatePlayingEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onZombieUpdatePlaying");
	hookAddress = 0x52B340;
	rawlen = 6;
	BYTE code[] = { PUSH_EDI, INVOKE(procAddress), ADD_ESP(4) };
	start(STRING(code));
}
