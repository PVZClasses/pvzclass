#pragma once
#include "../PVZ.h"

namespace PVZ
{
	class BaseClass;
	class PVZApp;
	//选关界面。
	class ResourceManager : public BaseClass
	{
	public:
		ResourceManager(int address) : BaseClass(address) {};
		SPT<PVZApp> GetPVZApp();
	};
	SPT<ResourceManager> GetResourceManager();
}