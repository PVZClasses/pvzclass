﻿#include "../PVZ.h"

PVZ::Lawn::Lawn(int baseaddress)
{
	BaseAddress = baseaddress;
};

LawnType::LawnType PVZ::Lawn::GetGridType(int row, int column)
{
	if (row >= 0 && row < 6 && column >= 0 && column < 9)
		return Memory::ReadMemory<LawnType::LawnType>(BaseAddress + 0x168 + 4 * (6 * column + row));
	return LawnType::None;
};

void PVZ::Lawn::SetGridType(int row, int column, LawnType::LawnType type)
{
	if (row >= 0 && row < 6 && column >= 0 && column < 9)
		Memory::WriteMemory<LawnType::LawnType>(BaseAddress + 0x168 + 4 * (6 * column + row), type);

};

RouteType::RouteType PVZ::Lawn::GetRouteType(int route)
{
	if (route >= 0 && route < 6)
		return Memory::ReadMemory<RouteType::RouteType>(BaseAddress + 0x5D8 + 4 * route);
	return RouteType::None;
};

void PVZ::Lawn::SetRouteType(int route, RouteType::RouteType type)
{
	if (route >= 0 && route < 6)
		Memory::WriteMemory<RouteType::RouteType>(BaseAddress + 0x5D8 + 4 * route, type);
};

bool PVZ::Lawn::Plantable(int row, int column, SeedType::SeedType type)
{
	SETARG(__asm__Plantable, 1) = row;
	SETARG(__asm__Plantable, 6) = type;
	__asm__Plantable[11] = (byte)column;
	SETARG(__asm__Plantable, 13) = PVZBASEADDRESS;
	SETARG(__asm__Plantable, 31) = Memory::Variable;
	return(Memory::Execute(STRING(__asm__Plantable)) == 0);
}