#pragma once
#include "DLLEvent.h"

// Zombie 角色的更新，被冻结、黄油定身时也会结算。
// 时机上先于原版的更新。
// 参数：更新的 Zombie
// 无返回值
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
