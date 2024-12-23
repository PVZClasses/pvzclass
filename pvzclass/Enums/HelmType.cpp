#include "HelmType.h"

const char* HelmType::ToString(HelmType zombieat1)
{
	switch (zombieat1)
	{
	case HelmType::None:
		return "ZombieAccessoriesType1None";
	case HelmType::RoadCone:
		return "RoadCone";
	case HelmType::Bucket:
		return "Bucket";
	case HelmType::FootballCap:
		return "FootballCap";
	case HelmType::MinerHat:
		return "MinerHat";
	case HelmType::Sled:
		return "Sled";
	case HelmType::Wallnut:
		return "Wallnut";
	case HelmType::Tallnut:
		return "Tallnut";
	default:
		return "InValid_Value_Of_ZombieAccessoriesType1None";
	}
}