#pragma once
#include "DLLEvent.h"

// 僵尸掉落物品事件。
// 已掉尝试落过物品的僵尸不会再次掉落物品。
// 参数：掉落物品的僵尸的地址
// 无返回值
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
