#pragma once
#include "DLLEvent.h"

// ֲ�ﱻ͵���¼���
// �޷���ֵ
// @param ����Ϊ�������¼���ֲ���ʳ��ֲ��Ľ�ʬ��
class PlantStolenEvent : public DLLEvent
{
public:
	PlantStolenEvent();
};

PlantStolenEvent::PlantStolenEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantStolen");
	hookAddress = 0x5304B6;
	rawlen = 7;
	BYTE code[] =
	{
		PUSH_EAX,
		INVOKE(procAddress),
		ADD_ESP(4),
	};
	start(STRING(code));
}