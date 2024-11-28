#pragma once
namespace HelmType
{

	enum HelmType
	{
		None,
		RoadCone,
		Bucket,
		FootballCap,
		MinerHat,
		Sled,
		Wallnut,
		Tallnut,
	};

	extern const char* ToString(HelmType zombieat1);

}

#define ZombieAccessoriesType1 HelmType