#pragma once
namespace SeedType
{

	enum SeedType
	{
		None = -1,
		Peashooter,
		Sunflower,
		CherryBomb,
		Wallnut,
		PotatoMine,
		SnowPea,
		Chomper,
		Repeater,
		Puffshroom,
		Sunshroom,
		Fumeshroom,
		CraveBuster,
		Hypnoshroom,
		Scaredyshroom,
		Iceshroom,
		Doomshroom,
		LilyPad,
		Squash,
		Threepeater,
		TangleKelp,
		Jalapeno,
		Spickweed,
		Torchwood,
		Tallnut,
		Seashroom,
		Plantern,
		Cactus,
		Blover,
		SplitPea,
		Starfruit,
		Pumpkin,
		Magnetshroom,
		Cabbagepult,
		FlowerPot,
		Kernelpult,
		CoffeeBean,
		Garlic,
		UmbrellaLeaf,
		Marigold,
		Melonpult,
		GatlingPea,
		TwinSunflower,
		Gloomshroom,
		Cattail,
		WinterMelon,
		GoldMagnet,
		Spikerock,
		CobCannon,
		Imitater,
		Explodenut,
		GiantWallnut,
		Sprout,
		LeftRepeater,
		Refresh = 54,
		Crater,
		Sun,
		Diamond,
		SnorkedZombie,
		Trophy,
		Zombie,
		ConeheadZombie,
		PoleVaultingZombie,
		BucketheadZombie,
		LadderZombie,
		DiggerZombie,
		BungeeZombie,
		FootballZombie,
		BalloonZombie,
		ScreenDoorZombie,
		Zomboin,
		PogoZombie,
		DancingZombie,
		Gigagargantuar,
		Imp,
	};

	extern const char* ToString(SeedType cardt);

}

namespace CardType
{
	// Deprecated
	typedef SeedType::SeedType CardType;
	const char* ToString(CardType cardt)
	{
		return(SeedType::ToString(cardt));
	}
}
namespace PlantType
{
	// Deprecated
	typedef SeedType::SeedType PlantType;
	const char* ToString(PlantType plantt)
	{
		return(SeedType::ToString(plantt));
	}
}