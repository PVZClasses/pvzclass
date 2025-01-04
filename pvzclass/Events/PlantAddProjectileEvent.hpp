#pragma once
#include "DLLEvent.h"

// ֲ�﷢���ӵ��¼���
// ʱ���������ӵ����������趨�������ӵ��ٶȸĶ���
// @param ����Ϊ�������¼���ֲ����ɵ��ӵ����ӵ�Ŀ�꽩ʬ�Ļ�ַ��
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
		PUSH_PTR_ESP_ADD_V(0x54),
		PUSH_EAX,
		PUSH_EBP,
		INVOKE(procAddress),
		ADD_ESP(0x0C),

		TEST_AL_AL,
		JNZ(6),
		POPAD,
		PUSHDWORD(0x52FDEE),
		RET
	};
	start(STRING(code));
}