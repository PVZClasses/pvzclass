#include "..\PVZ.h"

MusicType::MusicType PVZ::Music::__get_Type()
{
	return Memory::ReadMemory<MusicType::MusicType>(BaseAddress + 8);
}

void PVZ::Music::__set_Type(MusicType::MusicType value)
{
	__asm__Music__set_Type[1] = value;
	SETARG(__asm__Music__set_Type, 6) = BaseAddress;
	Memory::Execute(STRING(__asm__Music__set_Type));
}