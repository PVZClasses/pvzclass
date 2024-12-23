#include "../PVZ.h"

PVZ::TrackInstance::TrackInstance(int idoraddress) : BaseClass(0)
{
	if (idoraddress >= 1024)
		this->BaseAddress = idoraddress;
	else
		this->BaseAddress = Memory::ReadPointer(0x6A9EC0, 0x820, 0xC, 0) + idoraddress * 0x30C;	
}

SPT<PVZ::AttachmentID> PVZ::TrackInstance::GetAttachmentID()
{
	return MKS<PVZ::AttachmentID>(BaseAddress + 0x40);
}

SPT<PVZ::Attachment> PVZ::TrackInstance::GetAttachment()
{
	int ID = Memory::ReadMemory<int>(BaseAddress + 0x40);
	return (((ID & 0xFFFF0000) == 0) ? nullptr : MKS<PVZ::Attachment>(ID & 0x00FFFF));
}
