#pragma once
#include "DLLEvent.h"

// ��ʯ����תת���У�һ���ƶ�������ƥ��ʱ�������¼���
// ���������Ͻǵ����������Ͻǵ�����
// ����ֵ���Ƿ�ܾ��˴��ƶ���
class BegTwistFailMoveEvent : public DLLEvent
{
public:
	BegTwistFailMoveEvent();
};

BegTwistFailMoveEvent::BegTwistFailMoveEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onBegTwistFailMove");
	hookAddress = 0x42053C;
	rawlen = 7;
	BYTE code[]	 = { PUSH_ESI, PUSH_PTR_ESP_ADD_V(0x3C), INVOKE(procAddress), ADD_ESP(8),
		TEST_AL_AL, JNZ(8), POPAD, MOV_ESI(0x420602), JMP_REG32(REG_ESI)};
	start(STRING(code));
}
#pragma once
