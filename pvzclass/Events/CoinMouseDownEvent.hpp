#pragma once
#include "DLLEvent.h"

// ��Ʒ������¼���
// ���ռ�����Ʒ�����ٴδ������¼���ע����ˡ�
// @param ����Ϊ�������¼�����Ʒ�����������
// @return �Ƿ��������ԭ����̡�
class CoinMouseDownEvent : public DLLEvent
{
public:
	CoinMouseDownEvent();
};

CoinMouseDownEvent::CoinMouseDownEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onCoinMouseDown");
	hookAddress = 0x432C47;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_PTR_ESP_ADD_V(0x7C),
		PUSH_ESI,
		INVOKE(procAddress),
		ADD_ESP(8),

		TEST_AL_AL,
		JNZ(8),
		POPAD,
		MOV_ECX(0x432DBA),
		JMP_REG32(REG_ECX)
	};
	start(STRING(code));
}