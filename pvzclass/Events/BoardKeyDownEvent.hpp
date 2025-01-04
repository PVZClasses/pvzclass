#pragma once
#include "DLLEvent.h"

// �ؿ��ڼ��̰����¼���
// ���ȼ�����ԭ���¼���
// @param ����Ϊ�������¼��� Board�������� KeyCode��
// @return �Ƿ��������ԭ���¼���
class BoardKeyDownEvent : public DLLEvent
{
public:
	BoardKeyDownEvent();
};

BoardKeyDownEvent::BoardKeyDownEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onBoardKeyDown");
	hookAddress = 0x41B820;
	rawlen = 6;
	BYTE code[] =
	{
		PUSH_PTR_ESP_ADD_V(0x24),
		PUSH_ECX,
		INVOKE(procAddress),
		ADD_ESP(0x08)
	};
	start(STRING(code));
}