#pragma once
#include "DLLEvent.h"

// 植物消失事件
// 参数：触发事件的植物
// 无返回值
// 植物消失原因多种多样：被铲掉、被啃食、一次性植物生效、紫卡植物升级等都会触发
class PlantDieEvent : public DLLEvent
{
protected:
	const char* proc_name = "onPlantDie";
public:
	PlantDieEvent();
};

PlantDieEvent::PlantDieEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress(this->proc_name);
	hookAddress = 0x4679B9;
	rawlen = 7;
	BYTE code[] = { PUSH_EBP, INVOKE(procAddress), ADD_ESP(4) };
	start(STRING(code));
}

// Deprecated
class PlantRemoveEvent : public PlantDieEvent
{
protected:
	const char* proc_name = "onPlantRemove";
public:
	PlantRemoveEvent();
};

PlantRemoveEvent::PlantRemoveEvent() : PlantDieEvent() {}