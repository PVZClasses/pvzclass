#pragma once
#include "DLLEvent.h"

// Griditem �����¼�
// ���������µ� Griditem
// �޷���ֵ
// ʱ��������ԭ����¡�
class GriditemUpdateEvent : public DLLEvent
{
public:
	GriditemUpdateEvent();
};

GriditemUpdateEvent::GriditemUpdateEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onGriditemUpdate");
	hookAddress = 0x44E5E0;
	rawlen = 5;
	BYTE code[] = { PUSH_EAX, INVOKE(procAddress), ADD_ESP(4) };
	start(STRING(code));
}
