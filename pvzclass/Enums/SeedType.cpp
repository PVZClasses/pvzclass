#include "SeedType.h"

const char* SeedType::ToString(SeedType cardt)
{
	switch (cardt)
	{
	case SeedType::None:
		return "CardTypeNone";
	case SeedType::Peashooter:
		return "Peashooter";
	case SeedType::Sunflower:
		return "Sunflower";
	case SeedType::CherryBomb:
		return "CherryBomb";
	case SeedType::Wallnut:
		return "Wallnut_Plant";
	case SeedType::PotatoMine:
		return "PotatoMine";
	case SeedType::SnowPea:
		return "SnowPea";
	case SeedType::Chomper:
		return "Chomper";
	case SeedType::Repeater:
		return "Repeater";
	case SeedType::Puffshroom:
		return "Puffshroom";
	case SeedType::Sunshroom:
		return "Sunshroom";
	case SeedType::Fumeshroom:
		return "Fumeshroom";
	case SeedType::CraveBuster:
		return "CraveBuster";
	case SeedType::Hypnoshroom:
		return "Hypnoshroom";
	case SeedType::Scaredyshroom:
		return "Scaredyshroom";
	case SeedType::Iceshroom:
		return "Iceshroom";
	case SeedType::Doomshroom:
		return "Doomshroom";
	case SeedType::LilyPad:
		return "LilyPad";
	case SeedType::Squash:
		return "Squash";
	case SeedType::Threepeater:
		return "Threepeater";
	case SeedType::TangleKelp:
		return "TangleKelp";
	case SeedType::Jalapeno:
		return "Jalapeno";
	case SeedType::Spickweed:
		return "Spickweed";
	case SeedType::Torchwood:
		return "Torchwood";
	case SeedType::Tallnut:
		return "Tallnut";
	case SeedType::Seashroom:
		return "Seashroom";
	case SeedType::Plantern:
		return "Plantern";
	case SeedType::Cactus:
		return "Cactus";
	case SeedType::Blover:
		return "Blover";
	case SeedType::SplitPea:
		return "SplitPea";
	case SeedType::Starfruit:
		return "Starfruit";
	case SeedType::Pumpkin:
		return "Pumpkin";
	case SeedType::Magnetshroom:
		return "Magnetshroom";
	case SeedType::Cabbagepult:
		return "Cabbagepult";
	case SeedType::FlowerPot:
		return "FlowerPot";
	case SeedType::Kernelpult:
		return "Kernelpult";
	case SeedType::CoffeeBean:
		return "CoffeeBean";
	case SeedType::Garlic:
		return "Garlic";
	case SeedType::UmbrellaLeaf:
		return "UmbrellaLeaf";
	case SeedType::Marigold:
		return "Marigold";
	case SeedType::Melonpult:
		return "Melonpult";
	case SeedType::GatlingPea:
		return "GatlingPea";
	case SeedType::TwinSunflower:
		return "TwinSunflower";
	case SeedType::Gloomshroom:
		return "Gloomshroom";
	case SeedType::Cattail:
		return "Cattail";
	case SeedType::WinterMelon:
		return "WinterMelon";
	case SeedType::GoldMagnet:
		return "GoldMagnet";
	case SeedType::Spikerock:
		return "Spikerock";
	case SeedType::CobCannon:
		return "CobCannon";
	case SeedType::Imitater:
		return "Imitater";
	case SeedType::Explodenut:
		return "Explodenut";
	case SeedType::GiantWallnut:
		return "GiantWallnut";
	case SeedType::Sprout:
		return "Sprout";
	case SeedType::LeftRepeater:
		return "LeftRepeater";
	case SeedType::Refresh:
		return "Refresh";
	case SeedType::Crater:
		return "Crater";
	case SeedType::Sun:
		return "Sun";
	case SeedType::Diamond:
		return "Diamond";
	case SeedType::SnorkedZombie:
		return "SnorkedZombie";
	case SeedType::Trophy:
		return "Trophy";
	case SeedType::Zombie:
		return "Zombie";
	case SeedType::ConeheadZombie:
		return "ConeheadZombie";
	case SeedType::PoleVaultingZombie:
		return "PoleVaultingZombie";
	case SeedType::BucketheadZombie:
		return "BucketheadZombie";
	case SeedType::LadderZombie:
		return "LadderZombie";
	case SeedType::DiggerZombie:
		return "DiggerZombie";
	case SeedType::BungeeZombie:
		return "BungeeZombie";
	case SeedType::FootballZombie:
		return "FootballZombie";
	case SeedType::BalloonZombie:
		return "BalloonZombie";
	case SeedType::ScreenDoorZombie:
		return "ScreenDoorZombie";
	case SeedType::Zomboin:
		return "Zomboin";
	case SeedType::PogoZombie:
		return "PogoZombie";
	case SeedType::DancingZombie:
		return "DancingZombie";
	case SeedType::Gigagargantuar:
		return "Gigagargantuar";
	case SeedType::Imp:
		return "Imp";
	default:
		return "InValid_Value_Of_SeedType";
	}
}

const char* CardType::ToString(CardType cardt)
{
	return(SeedType::ToString(cardt));
}

const char* PlantType::ToString(PlantType plantt)
{
	return(SeedType::ToString(plantt));
}
