﻿#pragma once
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

// Deprecated
namespace CardType
{
	typedef SeedType::SeedType CardType;
}
namespace PlantType
{
	typedef SeedType::SeedType PlantType;
}