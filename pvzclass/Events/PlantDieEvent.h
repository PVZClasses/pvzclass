#pragma once
#include "DLLEvent.h"

// ֲ����ʧ�¼�
// �����������¼���ֲ��
// �޷���ֵ
// ֲ����ʧԭ����ֶ�����������������ʳ��һ����ֲ����Ч���Ͽ�ֲ�������ȶ��ᴥ��
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