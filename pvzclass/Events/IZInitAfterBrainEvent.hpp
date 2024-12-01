#pragma once
#include "DLLEvent.h"

// IZ 关卡初始化事件
// 此时脑子生成已完成，但植物尚未放置。
// 参数：触发事件的 Challenge
// 返回值：是否生成关卡默认生成的植物
class IZInitAfterBrainEvent : public DLLEvent
{
public:
	IZInitAfterBrainEvent();
};

IZInitAfterBrainEvent::IZInitAfterBrainEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onIZInitAfterBrain");
	hookAddress = 0x42A981;
	rawlen = 6;
	BYTE code[] = { PUSH_EDI, INVOKE(procAddress), ADD_ESP(4), TEST_AL_AL, JNZ(8), POPAD, MOV_EDX(0x42B277), 0xFF, 0XE2};
	start(STRING(code));
}
#pragma once
