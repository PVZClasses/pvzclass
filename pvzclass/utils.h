#pragma once
#include "Enums/SeedType.h"
#include "PVZ.h"
#include <vector>
#include <stack>

namespace Utils
{
	typedef PVZ::Memory Memory;
#define Read(x) (Memory::ReadMemory<int>(x))
#define Write(x,y) (Memory::WriteMemory<int>(x,y))
	inline int GetPlantCost(SeedType::SeedType type)
	{
		int address = 0x69F2C0 + 0x24 * type;
		return Read(address);
	}
	inline void SetPlantCost(SeedType::SeedType type, int cost)
	{
		int address = 0x69F2C0 + 0x24 * type;
		Write(address, cost);
	}
	inline int GetPlantCooldown(SeedType::SeedType type)
	{
		int address = 0x69F2C4 + 0x24 * type;
		return Read(address);
	}
	inline void SetPlantCooldown(SeedType::SeedType type, int cooldown)
	{
		int address = 0x69F2C4 + 0x24 * type;
		Write(address, cooldown);
	}
	inline int GetPlantSpeed(SeedType::SeedType type)
	{
		int address = 0x69F2CC + 0x24 * type;
		return Read(address);
	}
	inline void SetPlantSpeed(SeedType::SeedType type, int speed)
	{
		int address = 0x69F2CC + 0x24 * type;
		Write(address, speed);
	}
	inline void SetSunValue(int sun)
	{
		Write(0x4309F0, sun);
		Write(0x41B9B8, sun);
	}
	inline bool isvalid(const char* s, int l, int r)
	{
		int top = 0;
		for (int i = l; i < r; i++)
		{
			if (s[i] == '[')
				top++;
			if (s[i] == ']')
			{
				if (top <= 0)
					return 0;
				top--;
			}
		}
		return top == 0;
	}
	//O(n)
	inline int GetAddress(const char* s, int l = 0, int r = -1)
	{
		if (r == -1)
			r = std::strlen(s);
		if (!isvalid(s, l, r))
			return -1;
		std::stack<int> st;
		int ptr = 0, tmp = 0;
		for (int i = l; i < r; i++)
		{
			if (s[i] == '+')
			{
				ptr += tmp;
				tmp = 0;
			}
			if (s[i] == '[')
			{
				st.push(ptr);
				ptr = 0;
			}
			if (s[i] == ']')
			{
				tmp = Read(ptr+tmp);
				ptr = st.top();
				st.pop();
			}
			if (std::isupper(s[i]))
				tmp = tmp * 16 + s[i] - 'A';
			if (std::islower(s[i]))
				tmp = tmp * 16 + s[i] - 'a';
			if (std::isdigit(s[i]))
				tmp = tmp * 16 + s[i] - '0';
		}
		ptr += tmp;
		return(ptr);
	}
#undef Read(x)
#undef Write(x,y)
}