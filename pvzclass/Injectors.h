#pragma once
#include "PVZ.h"

class Injector
{
	private:
		DWORD ReplaceRange, ReplacePos;
	public:
		DWORD InjectPos, InjLen;
		Injector()
		{
			ReplacePos = ReplaceRange = InjectPos = InjLen = 0;
			return;
		}
		Injector(unsigned int OriPTR, int OriLen, byte* ASMCode, int CodeLen, bool dropOri = false)
		{
			ReplacePos = OriPTR;
			ReplaceRange = OriLen;
			InjectPos = PVZ::Memory::AllocMemory();
			InjLen = CodeLen;

			byte tmp[1024];
			PVZ::Memory::ReadArray<byte>(ReplacePos, tmp, OriLen);
			byte jmpout[6] =
			{
				PUSHDWORD(InjectPos),
				RET
			};
			PVZ::Memory::WriteArray<byte>(OriPTR, STRING(jmpout));
			for (register int i = 0, tmpl = OriLen - 6; i < tmpl; i++)
				PVZ::Memory::WriteMemory<byte>(OriPTR + i + 6, NOP);

			PVZ::Memory::WriteArray<byte>(InjectPos, ASMCode, CodeLen);
			byte jmpback[6] =
			{
				PUSHDWORD(OriPTR + OriLen),
				RET
			};
			if (dropOri)
			{
				PVZ::Memory::WriteArray<byte>(InjectPos + InjLen, STRING(jmpback));
				InjLen += 6;
				PVZ::Memory::WriteArray<byte>(InjectPos + InjLen, tmp, OriLen);
			}
			else
			{
				PVZ::Memory::WriteArray<byte>(InjectPos + InjLen, tmp, OriLen);
				PVZ::Memory::WriteArray<byte>(InjectPos + InjLen + OriLen, STRING(jmpback));
			}
			
			return;
		}
		~Injector()
		{
			this->Remove();
			return;
		}
		inline void Remove()
		{
			if (InjectPos == -1)
				return;
			byte tmp[1024];
			PVZ::Memory::ReadArray<byte>(InjectPos + InjLen, tmp, ReplaceRange);
			PVZ::Memory::WriteArray<byte>(ReplacePos, tmp, ReplaceRange);
			PVZ::Memory::FreeMemory(InjectPos);
			return;
		}
};