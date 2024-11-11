#include "../PVZ.h"

byte __asm_TodScaleRotateTransformMatrix[] =
{
	PUSHDWORD(0),
	PUSHDWORD(0),
	PUSHDWORD(0),
	PUSHDWORD(0),
	PUSHDWORD(0),
	MOV_ESI(0),
	INVOKE(0x5125D0),
	ADD_ESP(0x14),
	RET
};

void PVZ::Matrix3::ScaleRotateTransformMatrix(float x, float y, float rad, float ScaleX, float ScaleY)
{
	SETARGFLOAT(__asm_TodScaleRotateTransformMatrix, 1) = ScaleY;
	SETARGFLOAT(__asm_TodScaleRotateTransformMatrix, 6) = ScaleX;
	SETARGFLOAT(__asm_TodScaleRotateTransformMatrix, 11) = rad;
	SETARGFLOAT(__asm_TodScaleRotateTransformMatrix, 16) = y;
	SETARGFLOAT(__asm_TodScaleRotateTransformMatrix, 21) = x;
	SETARG(__asm_TodScaleRotateTransformMatrix, 26) = this->BaseAddress;
	PVZ::Memory::Execute(STRING(__asm_TodScaleRotateTransformMatrix));
}