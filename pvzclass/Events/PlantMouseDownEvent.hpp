#pragma once
#include "DLLEvent.h"

// 植物被点击事件。
// 只有主键和中键点击会触发事件。
// 优先级低于原版的玉米炮选中。
// @param 依次为：触发事件的植物、点击时的鼠标 Y 坐标、点击时的鼠标 X 坐标。
class PlantMouseDownEvent : public DLLEvent
{
public:
	PlantMouseDownEvent();
};

PlantMouseDownEvent::PlantMouseDownEvent()
{
	int procAddress = PVZ::Memory::GetProcAddress("onPlantMouseDown");
	hookAddress = 0x466413;
	rawlen = 5;
	BYTE code[] =
	{
		PUSH_PTR_ESP_ADD_V(0x2C),
		PUSH_PTR_ESP_ADD_V(0x2C),
		PUSH_ESI,
		INVOKE(procAddress),
		ADD_ESP(0x0C)
	};
	start(STRING(code));
}