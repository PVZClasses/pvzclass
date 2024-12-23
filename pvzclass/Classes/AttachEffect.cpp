#include "../PVZ.h"

SPT<PVZ::Matrix3> PVZ::AttachEffect::GetOffset()
{
	return(MKS<PVZ::Matrix3>(this->BaseAddress + 8));
}