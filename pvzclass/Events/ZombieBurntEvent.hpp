#pragma once
#include "DLLEvent.h"

// ��ʬ�ܵ��ҽ��˺��¼���
// @param �����¼��Ľ�ʬ
// @return ʵ�ʽ���ҽ��˺��Ľ�ʬ�Ļ�ַ����Ϊ��ָ�룬����¼���ȡ����
class ZombieBurntEvent : public DLLEvent
{
public:
	ZombieBurntEvent();
};

ZombieBurntEvent::ZombieBurntEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onZombieBurnt");
	hookAddress = 0x532B70;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_ECX,
		INVOKE(procAddress),
		MOV_EUX_EVX(REG_ECX, REG_EAX),
		ADD_ESP(4),

		TEST_EUX_EVX(REG_ECX, REG_ECX),
		JNZ(2),
		POPAD,
		RET
	};
	start(STRING(code));
}