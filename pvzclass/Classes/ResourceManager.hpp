#pragma once
#include "../PVZ.h"

namespace PVZ
{
	class BaseClass;
	class PVZApp;
	//ѡ�ؽ��档
	class ResourceManager : public BaseClass
	{
	public:
		ResourceManager(int address) : BaseClass(address) {};
		SPT<PVZApp> GetPVZApp();
	};
	SPT<ResourceManager> GetResourceManager();
}