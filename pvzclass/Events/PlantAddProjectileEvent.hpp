#pragma once
#include "DLLEvent.h"

// ֲ�﷢���ӵ��¼���
// ʱ���������ӵ����������趨�������ӵ��ٶȸĶ���
// @param ����Ϊ�������¼���ֲ����ɵ��ӵ���
// @return �Ƿ��������ԭ��ĵ�����
class PlantAddProjectileEvent : public DLLEvent
{
public:
	PlantAddProjectileEvent();
};

PlantAddProjectileEvent::PlantAddProjectileEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantAddProjectile");
	hookAddress = 0x4672B5;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_EAX,
		PUSH_EBP,
		INVOKE(procAddress),
		ADD_ESP(8),

		TEST_AL_AL,
		JNZ(6),
		POPAD,
		PUSHDWORD(0x52FDEE),
		RET
	};
	start(STRING(code));
}