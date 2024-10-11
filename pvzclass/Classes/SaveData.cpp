#include "..\PVZ.h"

void PVZ::SaveData::GetPVZUserName(char str[])
{
	Memory::ReadArray<char>(BaseAddress + 4, str, 12);
}
int PVZ::SaveData::GetChallengeRecord(PVZLevel::PVZLevel mode)
{
	return Memory::ReadMemory<int>(BaseAddress + 0x30 + (mode - 1) * 4);
}

void PVZ::SaveData::SetChallengeRecord(PVZLevel::PVZLevel mode, int val)
{
	Memory::WriteMemory<int>(BaseAddress + 0x30 + (mode - 1) * 4, val);
}

int PVZ::SaveData::GetPurchase(StoreItem::StoreItem item)
{
	return Memory::ReadMemory<int>(BaseAddress + 0x1C0 + item * 4);
}

void PVZ::SaveData::SetPurchase(StoreItem::StoreItem item, int val)
{
	Memory::WriteMemory<int>(BaseAddress + 0x1C0 + item * 4, val);
}

BOOLEAN PVZ::SaveData::HavePurpleCard(CardType::CardType purplecard)
{
	if (purplecard >= CardType::GatlingPea && purplecard <= CardType::CobCannon)
		return Memory::ReadMemory<int>(BaseAddress + 0x1C0 + (purplecard - 40) * 4);
	return false;
}

SPT<PVZ::SaveData::GardenPlant> PVZ::SaveData::GetGardenPlant(int index)
{
	if (index >= 0 && index < GardenPlantCount)
		return MKS<GardenPlant>(BaseAddress + 0x350 + index * 0x58);
	else
		return NULL;
}
