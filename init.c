void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	//Randomizer Starts here
	//
	//If u wanna add another loadout by yourself. Copy 1 class and change the arrays how u want to. DON'T FORGET TO ADD IT in row 1157. Make sure to put it into the right Class (male/female)!!!
	//

	void addMags(PlayerBase player, string mag_type, int count)
	{
		if (count < 1)
			return;

		EntityAI mag;

		for (int i = 0; i < count; i++) {
			mag = player.GetInventory().CreateInInventory(mag_type);
		}

		player.SetQuickBarEntityShortcut(mag, 2, true);
	}
	
	EntityAI randomMaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin","PowderedMilk","Rice","BakedBeansCan_Opened","PeachesCan_Opened","SpaghettiCan_Opened","SardinesCan_Opened","TunaCan_Opened","Apple","Tomato","GreenBellPepper","Zucchini","SlicedPumpkin","Potato","SambucusBerry","CaninaBerry","Plum","Pear","AgaricusMushroom","AmanitaMushroom","MacrolepiotaMushroom","LactariusMushroom","PsilocybeMushroom","AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","SodaCan_Kvass","WaterBottle"};
		ref TStringArray hatArray = {"BaseballCap_Blue","","","","BaseballCap_Beige","","","","BaseballCap_Black","","","","BaseballCap_Olive","","","","BaseballCap_Pink","","","","BaseballCap_Red","","","","BaseballCap_Camo","","","","BaseballCap_CMMG_Black","","","","BaseballCap_CMMG_Pink","","","","BeanieHat_Beige","","","","BeanieHat_Black","","","","BeanieHat_Blue","","","","BeanieHat_Brown","","","","BeanieHat_Green","","","","BeanieHat_Grey","","","","BeanieHat_Pink","","","","BeanieHat_Red","","","","Ushanka_Black","","","","Ushanka_Blue","","","","Ushanka_Green","","","","RadarCap_Black","","","","RadarCap_Blue","","","","RadarCap_Brown","","","","RadarCap_Green","","","","RadarCap_Red","","","","FlatCap_Black","","","","FlatCap_Blue","","","","FlatCap_Red","","","","FlatCap_Brown","","","","FlatCap_Grey","","","","FlatCap_BrownCheck","","","","FlatCap_GreyCheck","","","","FlatCap_BlackCheck","","","","ZmijovkaCap_Black","","","","ZmijovkaCap_Blue","","","","ZmijovkaCap_Brown","","","","ZmijovkaCap_Green","","","","ZmijovkaCap_Red","","","","CowboyHat_Brown","","","","CowboyHat_black","","","","CowboyHat_darkBrown","","","","CowboyHat_green","","","","SkateHelmet_Black","","","","SkateHelmet_Blue","","","","SkateHelmet_Gray","","","","SkateHelmet_Green","","","","SkateHelmet_Red","","","","WeldingMask","","","","LeatherHat_Natural","","","","LeatherHat_Beige","","","","LeatherHat_Brown","","","","LeatherHat_Black","","","","GreatHelm","","",""};
		ref TStringArray topArray = {"Sweater_Gray","Sweater_Blue","Sweater_Green","Sweater_Red","Shirt_BlueCheck","Shirt_BlueCheckBright","Shirt_GreenCheck","Shirt_RedCheck","Shirt_WhiteCheck","Shirt_PlaneBlack","TacticalShirt_Grey","TacticalShirt_Black","M65Jacket_Black","TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_OrangeWhiteStripes","TShirt_Red","TShirt_RedBlackStripes","TShirt_White","TShirt_Grey","Hoodie_Blue","Hoodie_Black","Hoodie_Brown","Hoodie_Green","Hoodie_Grey","Hoodie_Red","HikingJacket_Black","HikingJacket_Blue","HikingJacket_Red","HikingJacket_Green","Raincoat_Orange","Raincoat_Green","Raincoat_Yellow","Raincoat_Pink","Raincoat_Red","Raincoat_Blue","Raincoat_Black","TrackSuitJacket_Black","TrackSuitJacket_Blue","TrackSuitJacket_Green","TrackSuitJacket_LightBlue","TrackSuitJacket_Red","QuiltedJacket_Black","QuiltedJacket_Green","QuiltedJacket_Blue","QuiltedJacket_Red","QuiltedJacket_Grey","QuiltedJacket_Orange","QuiltedJacket_Yellow","QuiltedJacket_Violet","BomberJacket_Black","BomberJacket_Brown","BomberJacket_Blue","BomberJacket_Grey","BomberJacket_Maroon","BomberJacket_Olive","BomberJacket_SkyBlue"};
		ref TStringArray pantsArray = {"Jeans_Black","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey","Jeans_BlueDark","CargoPants_Beige","CargoPants_Black","CargoPants_Blue","CargoPants_Green","CargoPants_Grey","CanvasPants_Beige","CanvasPants_Blue","CanvasPants_Grey","CanvasPants_Red","CanvasPants_Violet","CanvasPantsMidi_Beige","CanvasPantsMidi_Blue","CanvasPantsMidi_Grey","CanvasPantsMidi_Red","CanvasPantsMidi_Violet","TrackSuitPants_Black","TrackSuitPants_Blue","TrackSuitPants_Green","TrackSuitPants_Red","TrackSuitPants_LightBlue","SlacksPants_Beige","SlacksPants_Black","SlacksPants_Blue","SlacksPants_Brown","SlacksPants_DarkGrey","SlacksPants_Khaki","SlacksPants_LightGrey","SlacksPants_White","Breeches_Pink","Breeches_Red","Breeches_White","Breeches_Green","Breeches_Browncheck","Breeches_Blue","Breeches_Blackcheck","Breeches_Black","Breeches_Beige","Breeches_Beetcheck","ShortJeans_Black","ShortJeans_Blue","ShortJeans_Brown","ShortJeans_Darkblue","ShortJeans_Green","ShortJeans_Red"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","","SportGlasses_Black","","","","SportGlasses_Green","","","","SportGlasses_Orange","","","","AviatorGlasses","","","","ThickFramesGlasses","","","","ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"AthleticShoes_Blue","AthleticShoes_Black","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey","DressShoes_Beige","DressShoes_Black","DressShoes_Brown","DressShoes_Sunburst","DressShoes_White","HikingBoots_Brown","HikingBoots_Black","HikingBootsLow_Black","HikingBootsLow_Blue","HikingBootsLow_Beige","HikingBootsLow_Grey","Wellies_Black","Wellies_Brown","Wellies_Green","Wellies_Grey","WorkingBoots_Grey","WorkingBoots_Brown","WorkingBoots_Green","WorkingBoots_Yellow","WorkingBoots_Beige","JoggingShoes_Black","JoggingShoes_Blue","JoggingShoes_Red","JoggingShoes_Violet","JoggingShoes_White","Sneakers_Black","Sneakers_Gray","Sneakers_Green","Sneakers_Red","Sneakers_White"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","","","BandanaMask_BlackPattern","","","","","","BandanaMask_PolkaPattern","","","","","","BandanaMask_GreenPattern","","","","","","BandanaMask_CamoPattern","","","","","","NioshFaceMask","","","","","","HockeyMask","","","","","","BalaclavaMask_Black","","","","","","BalaclavaMask_Blackskull","","","","","","BalaclavaMask_Beige","","","","","","BalaclavaMask_Blue","","","","","","BalaclavaMask_Green","","","","","","BalaclavaMask_Pink","","","","","","BalaclavaMask_White","","","","","","GP5GasMask","","","","",""};
		ref TStringArray lightArray = {"Chemlight_White","Chemlight_Blue","Chemlight_Green","Chemlight_White","Chemlight_Red","Chemlight_Yellow","Roadflare","Chemlight_White"};
		ref TStringArray meleeArray = {"NailedBaseballBat","Pipe","Crowbar"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		player.GetInventory().CreateInInventory("StoneKnife");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		EntityAI gun = player.GetInventory().CreateInInventory("MKII");
		addMags(player, "Mag_MKII_10Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_22");
		player.GetInventory().CreateInInventory("Ammo_22");
		player.GetInventory().CreateInInventory("Ammo_22");
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI randomFemaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin", "PowderedMilk", "Rice", "BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "SlicedPumpkin", "Potato", "SambucusBerry", "CaninaBerry", "Plum", "Pear", "AgaricusMushroom", "AmanitaMushroom", "MacrolepiotaMushroom", "LactariusMushroom", "PsilocybeMushroom", "AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"BaseballCap_Blue","","","", "BaseballCap_Beige","","","", "BaseballCap_Black","","","", "BaseballCap_Olive","","","", "BaseballCap_Pink","","","", "BaseballCap_Red","","","", "BaseballCap_Camo","","","", "BaseballCap_CMMG_Black","","","", "BaseballCap_CMMG_Pink","","","", "BeanieHat_Beige","","","", "BeanieHat_Black","","","", "BeanieHat_Blue","","","", "BeanieHat_Brown","","","", "BeanieHat_Green","","","", "BeanieHat_Grey","","","", "BeanieHat_Pink","","","", "BeanieHat_Red","","","", "Ushanka_Black","","","", "Ushanka_Blue","","","", "Ushanka_Green","","","", "RadarCap_Black","","","", "RadarCap_Blue","","","", "RadarCap_Brown","","","", "RadarCap_Green","","","", "RadarCap_Red","","","", "FlatCap_Black","","","", "FlatCap_Blue","","","", "FlatCap_Red","","","", "FlatCap_Brown","","","", "FlatCap_Grey","","","", "FlatCap_BrownCheck","","","", "FlatCap_GreyCheck","","","", "FlatCap_BlackCheck","","","", "ZmijovkaCap_Black","","","", "ZmijovkaCap_Blue","","","", "ZmijovkaCap_Brown","","","", "ZmijovkaCap_Green","","","", "ZmijovkaCap_Red","","","", "CowboyHat_Brown","","","", "CowboyHat_black","","","", "CowboyHat_darkBrown","","","", "CowboyHat_green","","","", "SkateHelmet_Black","","","", "SkateHelmet_Blue","","","", "SkateHelmet_Gray","","","", "SkateHelmet_Green","","","", "SkateHelmet_Red","","","", "WeldingMask","","","", "LeatherHat_Natural","","","", "LeatherHat_Beige","","","", "LeatherHat_Brown","","","", "LeatherHat_Black","","","", "GreatHelm","","",""}; 		
		ref TStringArray topArray = {"Sweater_Gray", "Sweater_Blue", "Sweater_Green", "Sweater_Red", "Shirt_BlueCheck", "Shirt_BlueCheckBright", "Shirt_GreenCheck", "Shirt_RedCheck", "Shirt_WhiteCheck", "Shirt_PlaneBlack", "TacticalShirt_Grey", "TacticalShirt_Black", "M65Jacket_Black", "TShirt_Beige", "TShirt_Black", "TShirt_Blue", "TShirt_Green", "TShirt_OrangeWhiteStripes", "TShirt_Red", "TShirt_RedBlackStripes", "TShirt_White", "TShirt_Grey", "Hoodie_Blue", "Hoodie_Black", "Hoodie_Brown", "Hoodie_Green", "Hoodie_Grey", "Hoodie_Red", "HikingJacket_Black", "HikingJacket_Blue", "HikingJacket_Red", "HikingJacket_Green", "Raincoat_Orange", "Raincoat_Green", "Raincoat_Yellow", "Raincoat_Pink", "Raincoat_Red", "Raincoat_Blue", "Raincoat_Black", "TrackSuitJacket_Black", "TrackSuitJacket_Blue", "TrackSuitJacket_Green", "TrackSuitJacket_LightBlue", "TrackSuitJacket_Red", "QuiltedJacket_Black", "QuiltedJacket_Green", "QuiltedJacket_Blue", "QuiltedJacket_Red", "QuiltedJacket_Grey", "QuiltedJacket_Orange", "QuiltedJacket_Yellow", "QuiltedJacket_Violet", "BomberJacket_Black", "BomberJacket_Brown", "BomberJacket_Blue", "BomberJacket_Grey", "BomberJacket_Maroon", "BomberJacket_Olive", "BomberJacket_SkyBlue", "Blouse_Blue", "Blouse_Green", "Blouse_Violet", "Blouse_White"};
		ref TStringArray pantsArray = {"ShortJeans_Black", "ShortJeans_Blue", "ShortJeans_Brown", "ShortJeans_Darkblue", "ShortJeans_Green", "ShortJeans_Red", "Skirt_Blue", "Skirt_Red", "Skirt_White", "Skirt_Yellow"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","", "SportGlasses_Black","","","", "SportGlasses_Green","","","", "SportGlasses_Orange","","","", "AviatorGlasses","","","", "ThickFramesGlasses","","","", "ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"AthleticShoes_Blue", "AthleticShoes_Black", "AthleticShoes_Brown", "AthleticShoes_Green", "AthleticShoes_Grey", "DressShoes_Beige", "DressShoes_Black", "DressShoes_Brown", "DressShoes_Sunburst", "DressShoes_White", "HikingBoots_Brown", "HikingBoots_Black", "HikingBootsLow_Black", "HikingBootsLow_Blue", "HikingBootsLow_Beige", "HikingBootsLow_Grey", "Wellies_Black", "Wellies_Brown", "Wellies_Green", "Wellies_Grey", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Green", "WorkingBoots_Yellow", "WorkingBoots_Beige", "JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey", "JoggingShoes_Black", "JoggingShoes_Blue", "JoggingShoes_Red", "JoggingShoes_Violet", "JoggingShoes_White", "Sneakers_Black", "Sneakers_Gray", "Sneakers_Green", "Sneakers_Red", "Sneakers_White"};
		ref TStringArray glovesArray = {"WorkingGloves_Black","","","", "WorkingGloves_Beige","","","", "WorkingGloves_Brown","","","", "WorkingGloves_Yellow","","","", "TacticalGloves_Beige","","","", "TacticalGloves_Black","","","", "TacticalGloves_Green","","","", "OMNOGloves_Brown","","","", "OMNOGloves_Gray","","","", "SurgicalGloves_White","","","", "SurgicalGloves_LightBlue","","","", "SurgicalGloves_Blue","","","", "SurgicalGloves_Green","","",""};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","","", "BandanaMask_BlackPattern","","","","","", "BandanaMask_PolkaPattern","","","","","", "BandanaMask_GreenPattern","","","","","", "BandanaMask_CamoPattern","","","","","", "NioshFaceMask","","","","","", "HockeyMask","","","","","", "BalaclavaMask_Black","","","","","", "BalaclavaMask_Blackskull","","","","","", "BalaclavaMask_Beige","","","","","", "BalaclavaMask_Blue","","","","","", "BalaclavaMask_Green","","","","","", "BalaclavaMask_Pink","","","","","", "BalaclavaMask_White","","","","","", "GP5GasMask","","","","",""};
		ref TStringArray lightArray = {"Chemlight_White","Chemlight_Blue","Chemlight_Green","Chemlight_White","Chemlight_Red","Chemlight_Yellow","Roadflare","Chemlight_White"};
		ref TStringArray meleeArray = {"NailedBaseballBat","Pipe","Crowbar"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		player.GetInventory().CreateInInventory("StoneKnife");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		EntityAI gun = player.GetInventory().CreateInInventory("MakarovIJ70");
		addMags(player, "Mag_IJ70_8Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_380");
		player.GetInventory().CreateInInventory("Ammo_380");
		player.GetInventory().CreateInInventory("Ammo_380");
		player.GetInventory().CreateInInventory("Ammo_380");
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI randomFemale2Class(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin", "PowderedMilk", "Rice", "BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "SlicedPumpkin", "Potato", "SambucusBerry", "CaninaBerry", "Plum", "Pear", "AgaricusMushroom", "AmanitaMushroom", "MacrolepiotaMushroom", "LactariusMushroom", "PsilocybeMushroom", "AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"BaseballCap_Blue","","","","", "BaseballCap_Beige","","","","", "BaseballCap_Black","","","","", "BaseballCap_Olive","","","","", "BaseballCap_Pink","","","","", "BaseballCap_Red","","","","", "BaseballCap_Camo","","","","", "BaseballCap_CMMG_Black","","","","", "BaseballCap_CMMG_Pink","","","","", "BeanieHat_Beige","","","","", "BeanieHat_Black","","","","", "BeanieHat_Blue","","","","", "BeanieHat_Brown","","","","", "BeanieHat_Green","","","","", "BeanieHat_Grey","","","","", "BeanieHat_Pink","","","","", "BeanieHat_Red","","","","", "Ushanka_Black","","","","", "Ushanka_Blue","","","","", "Ushanka_Green","","","","", "RadarCap_Black","","","","", "RadarCap_Blue","","","","", "RadarCap_Brown","","","","", "RadarCap_Green","","","","", "RadarCap_Red","","","","", "FlatCap_Black","","","","", "FlatCap_Blue","","","","", "FlatCap_Red","","","","", "FlatCap_Brown","","","","", "FlatCap_Grey","","","","", "FlatCap_BrownCheck","","","","", "FlatCap_GreyCheck","","","","", "FlatCap_BlackCheck","","","","", "ZmijovkaCap_Black","","","","", "ZmijovkaCap_Blue","","","","", "ZmijovkaCap_Brown","","","","", "ZmijovkaCap_Green","","","","", "ZmijovkaCap_Red","","","","", "CowboyHat_Brown","","","","", "CowboyHat_black","","","","", "CowboyHat_darkBrown","","","","", "CowboyHat_green","","","","", "SkateHelmet_Black","","","","", "SkateHelmet_Blue","","","","", "SkateHelmet_Gray","","","","", "SkateHelmet_Green","","","","", "SkateHelmet_Red","","","","", "WeldingMask","","","","", "LeatherHat_Natural","","","","", "LeatherHat_Beige","","","","", "LeatherHat_Brown","","","","", "LeatherHat_Black","","","","", "GreatHelm","","","",""};
		ref TStringArray topArray = {"MiniDress_Pink", "MiniDress_PinkChecker", "MiniDress_RedChecker", "MiniDress_WhiteChecker", "MiniDress_GreenChecker", "MiniDress_BrownChecker", "MiniDress_BlueChecker", "MiniDress_BlueWithDots"};
		ref TStringArray pantsArray = {"", ""};
		ref TStringArray vestArray  = {"ChestHolster","", "","", "","", "","", "",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","", "SportGlasses_Black","","","", "SportGlasses_Green","","","", "SportGlasses_Orange","","","", "AviatorGlasses","","","", "ThickFramesGlasses","","","", "ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"AthleticShoes_Blue", "AthleticShoes_Black", "AthleticShoes_Brown", "AthleticShoes_Green", "AthleticShoes_Grey", "DressShoes_Beige", "DressShoes_Black", "DressShoes_Brown", "DressShoes_Sunburst", "DressShoes_White", "HikingBoots_Brown", "HikingBoots_Black", "HikingBootsLow_Black", "HikingBootsLow_Blue", "HikingBootsLow_Beige", "HikingBootsLow_Grey", "Wellies_Black", "Wellies_Brown", "Wellies_Green", "Wellies_Grey", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Green", "WorkingBoots_Yellow", "WorkingBoots_Beige", "JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey", "JoggingShoes_Black", "JoggingShoes_Blue", "JoggingShoes_Red", "JoggingShoes_Violet", "JoggingShoes_White", "Sneakers_Black", "Sneakers_Gray", "Sneakers_Green", "Sneakers_Red", "Sneakers_White"};
		ref TStringArray glovesArray = {"WorkingGloves_Black","","","", "WorkingGloves_Beige","","","", "WorkingGloves_Brown","","","", "WorkingGloves_Yellow","","","", "TacticalGloves_Beige","","","", "TacticalGloves_Black","","","", "TacticalGloves_Green","","","", "OMNOGloves_Brown","","","", "OMNOGloves_Gray","","","", "SurgicalGloves_White","","","", "SurgicalGloves_LightBlue","","","", "SurgicalGloves_Blue","","","", "SurgicalGloves_Green","","",""};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","", "BandanaMask_BlackPattern","","","","", "BandanaMask_PolkaPattern","","","","", "BandanaMask_GreenPattern","","","","", "BandanaMask_CamoPattern","","","","", "NioshFaceMask","","","","", "HockeyMask","","","","","", "BalaclavaMask_Black","","","","", "BalaclavaMask_Blackskull","","","","", "BalaclavaMask_Beige","","","","", "BalaclavaMask_Blue","","","","", "BalaclavaMask_Green","","","","", "BalaclavaMask_Pink","","","","", "BalaclavaMask_White","","","","", "GP5GasMask","","","",""};
		ref TStringArray backpackArray = {"TaloonBag_Blue", "TaloonBag_Green", "TaloonBag_Orange", "TaloonBag_Violet", "ImprovisedBag", "FurImprovisedBag", "FurCourierBag", "HuntingBag", "MountainBag_Blue", "MountainBag_Green", "MountainBag_Orange", "MountainBag_Red", "ChildBag_Blue", "ChildBag_Green", "ChildBag_Red", "ChildBag_Blue", "ChildBag_Green", "ChildBag_Red", "ChildBag_Blue", "ChildBag_Green", "ChildBag_Red", "ChildBag_Blue", "ChildBag_Green", "ChildBag_Red", "CoyoteBag_Brown", "CoyoteBag_Green"};
		ref TStringArray lightArray = {"Chemlight_White","Chemlight_Blue","Chemlight_Green","Chemlight_White","Chemlight_Red","Chemlight_Yellow","Roadflare","Chemlight_White"};
		ref TStringArray meleeArray = {"NailedBaseballBat","Pipe","Crowbar"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		player.GetInventory().CreateInInventory("StoneKnife");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		EntityAI gun = player.GetInventory().CreateInInventory("Glock19");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("TLRLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_Glock_15Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_9x19");
		player.GetInventory().CreateInInventory("Ammo_9x19");
		player.GetInventory().CreateInInventory("Ammo_9x19");
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
		
	EntityAI scientistClass(PlayerBase player)
	{
		player.GetInventory().CreateInInventory("Skirt_White");
		player.GetInventory().CreateInInventory("LabCoat");
		player.GetInventory().CreateInInventory("ThinFramesGlasses");
		player.GetInventory().CreateInInventory("DressShoes_White");
		player.GetInventory().CreateInInventory("WaterBottle");
		player.GetInventory().CreateInInventory("Apple");
		player.GetInventory().CreateInInventory("BloodTestKit");
		player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("Screwdriver");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("UMP45");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("UniversalLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_UMP_25Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_45ACP");
		player.GetInventory().CreateInInventory("Ammo_45ACP");
		player.GetInventory().CreateInInventory("Ammo_45ACP");
		ItemBase melee = player.GetInventory().CreateInInventory("KitchenKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	EntityAI doctorClass(PlayerBase player)
	{
		player.GetInventory().CreateInInventory("SlacksPants_Black");
		player.GetInventory().CreateInInventory("LabCoat");
		player.GetInventory().CreateInInventory("ThinFramesGlasses");
		player.GetInventory().CreateInInventory("DressShoes_Brown");
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("WaterBottle");
		player.GetInventory().CreateInInventory("Apple");
		player.GetInventory().CreateInInventory("Thermometer");
		player.GetInventory().CreateInInventory("PainkillerTablets");
		player.GetInventory().CreateInInventory("Morphine");
		ItemBase light = player.GetInventory().CreateInInventory("Headtorch_Grey");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("Izh43Shotgun");
		addMags(player, "Ammo_12gaSlug", 5);
		player.GetInventory().CreateInInventory("Ammo_12gaPellets");
		player.GetInventory().CreateInInventory("Ammo_12gaPellets");
		player.GetInventory().CreateInInventory("Ammo_12gaPellets");
		player.GetInventory().CreateInInventory("Ammo_12gaRubberSlug");
		player.GetInventory().CreateInInventory("Ammo_12gaRubberSlug");
		ItemBase melee = player.GetInventory().CreateInInventory("SteakKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI nurseClass(PlayerBase player)
	{
		ref TStringArray hatArray = {"MedicalScrubsHat_Blue","","","","","","MedicalScrubsHat_Green","","","","","","MedicalScrubsHat_White","","","","",""};
		ref TStringArray dressArray = {"NurseDress_White","NurseDress_Blue"};
		ref TStringArray backpackArray  = {"ChildBag_Blue","SmershBag"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","ThickFramesGlasses","ThinFramesGlasses","","","","","",""};
		ref TStringArray shoesArray = {"JoggingShoes_White","Ballerinas_White","DressShoes_White","Ballerinas_White","Ballerinas_Blue","Ballerinas_Red","Ballerinas_White"};
		ref TStringArray glovesArray = {"SurgicalGloves_White","SurgicalGloves_LightBlue","SurgicalGloves_Blue","SurgicalGloves_Green"};
		ref TStringArray maskArray = {"SurgicalMask","","SurgicalMask"};
		ref TStringArray medsArray = {"PainkillerTablets","Morphine","BloodTestKit","DisinfectantAlcohol"};
		ref TStringArray meds2Array = {"TetracyclineAntibiotics","Epinephrine","Thermometer","VitaminBottle"};
		ref TStringArray meds3Array = {"BloodBagIV","BloodBagFull","BloodBagEmpty","SalineBag","SalineBagIV","StartKitIV"};
				
		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(dressArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(medsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(meds2Array.GetRandomElement());
		player.GetInventory().CreateInInventory(meds3Array.GetRandomElement());
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("WaterBottle");
		player.GetInventory().CreateInInventory("Apple");
		ItemBase light = player.GetInventory().CreateInInventory("Headtorch_Grey");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("CZ61");
		addMags(player, "Mag_CZ61_20Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_380");
		player.GetInventory().CreateInInventory("Ammo_380");
		player.GetInventory().CreateInInventory("Ammo_380");
		ItemBase melee = player.GetInventory().CreateInInventory("KitchenKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	EntityAI nurseMaleClass(PlayerBase player)
	{
		ref TStringArray hatArray = {"MedicalScrubsHat_Blue","MedicalScrubsHat_Green","MedicalScrubsHat_White"};
		ref TStringArray topArray = {"MedicalScrubsShirt_Blue","MedicalScrubsShirt_Green","MedicalScrubsShirt_White"};
		ref TStringArray pantsArray = {"MedicalScrubsPants_Blue","MedicalScrubsPants_Green","MedicalScrubsPants_White"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","ThickFramesGlasses","ThinFramesGlasses","","","","","",""};
		ref TStringArray shoesArray = {"JoggingShoes_White","DressShoes_White"};
		ref TStringArray glovesArray = {"SurgicalGloves_White","SurgicalGloves_LightBlue","SurgicalGloves_Blue","SurgicalGloves_Green"};
		ref TStringArray medsArray = {"PainkillerTablets","Morphine","BloodTestKit","DisinfectantAlcohol"};
		ref TStringArray meds2Array = {"TetracyclineAntibiotics","Epinephrine","Thermometer","VitaminBottle"};
		ref TStringArray meds3Array = {"BloodBagIV","BloodBagFull","BloodBagEmpty","SalineBag","SalineBagIV","StartKitIV"};
				
		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(medsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(meds2Array.GetRandomElement());
		player.GetInventory().CreateInInventory(meds3Array.GetRandomElement());
		player.GetInventory().CreateInInventory("SurgicalMask");
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("WaterBottle");
		player.GetInventory().CreateInInventory("Apple");
		EntityAI gun = player.GetInventory().CreateInInventory("FNX45");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("TLRLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_FNX45_15Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_45ACP");
		player.GetInventory().CreateInInventory("Ammo_45ACP");
		player.GetInventory().CreateInInventory("Ammo_45ACP");
		ItemBase melee = player.GetInventory().CreateInInventory("KitchenKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	EntityAI policemanClass(PlayerBase player)
	{
		ref TStringArray hatArray = {"DirtBikeHelmet_Police","PoliceCap","PoliceCap","PoliceCap"};
		ref TStringArray topArray = {"PoliceJacket","PoliceJacketOrel"};
		ref TStringArray pantsArray = {"PolicePants","PolicePantsOrel"};
		ref TStringArray vestArray  = {"PoliceVest","PoliceVest"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","AviatorGlasses","SportGlasses_Black","SportGlasses_Green","SportGlasses_Orange","AviatorGlasses","AviatorGlasses","AviatorGlasses",""};
		ref TStringArray shoesArray = {"DressShoes_Black","WorkingBoots_Grey"};
		ref TStringArray glovesArray = {"OMNOGloves_Brown","OMNOGloves_Gray","OMNOGloves_Brown","OMNOGloves_Gray","SurgicalGloves_Blue"};
		ref TStringArray extraArray = {"Megaphone","DisinfectantAlcohol","Lockpick"};
		ref TStringArray extra2Array = {"Roadflare","Flashlight","Chemlight_Blue"};
				
		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(extraArray.GetRandomElement());
		player.GetInventory().CreateInInventory(extra2Array.GetRandomElement());
		player.GetInventory().CreateInInventory("CombatKnife");
		player.GetInventory().CreateInInventory("Handcuffs");
		player.GetInventory().CreateInInventory("HandcuffKeys");
		player.GetInventory().CreateInInventory("PersonalRadio");
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("SodaCan_Pipsi");
		player.GetInventory().CreateInInventory("Potato");
		EntityAI gun = player.GetInventory().CreateInInventory("CZ75");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("TLRLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_CZ75_15Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_9x19");
		player.GetInventory().CreateInInventory("Ammo_9x19");
		player.GetInventory().CreateInInventory("Ammo_9x19");
		ItemBase melee = player.GetInventory().CreateInInventory("StunBaton");
		melee.GetInventory().CreateAttachment("Battery9V");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	EntityAI policewomanClass(PlayerBase player)
	{
		ref TStringArray hatArray = {"DirtBikeHelmet_Police","PoliceCap","PoliceCap","PoliceCap"};
		ref TStringArray topArray = {"PoliceJacket","PoliceJacketOrel"};
		ref TStringArray pantsArray = {"PolicePants","PolicePantsOrel","Skirt_Blue","Skirt_Blue","Skirt_Blue","Skirt_Blue"};
		ref TStringArray vestArray  = {"PoliceVest","PoliceVest"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","AviatorGlasses","SportGlasses_Black","SportGlasses_Green","SportGlasses_Orange","AviatorGlasses","AviatorGlasses","AviatorGlasses","LeatherBelt_Beige",""};
		ref TStringArray shoesArray = {"MilitaryBoots_Black","TTSKOBoots","CombatBoots_Black","HikingBootsLow_Black","HikingBoots_Black","JungleBoots_Black","WorkingBoots_Grey"};
		ref TStringArray glovesArray = {"OMNOGloves_Brown","OMNOGloves_Gray","SurgicalGloves_Blue"};
		ref TStringArray extraArray = {"Megaphone","DisinfectantAlcohol","Lockpick"};
		ref TStringArray extra2Array = {"Flashlight","Chemlight_Blue"};
				
		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(extraArray.GetRandomElement());
		player.GetInventory().CreateInInventory(extra2Array.GetRandomElement());
		player.GetInventory().CreateInInventory("CombatKnife");
		player.GetInventory().CreateInInventory("Handcuffs");
		player.GetInventory().CreateInInventory("HandcuffKeys");
		player.GetInventory().CreateInInventory("PersonalRadio");
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("SodaCan_Spite");
		player.GetInventory().CreateInInventory("Plum");
		EntityAI gun = player.GetInventory().CreateInInventory("Saiga");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("KobraOptic");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_Saiga_Drum20Rnd", 1);
		player.GetInventory().CreateInInventory("Ammo_12gaSlug");
		player.GetInventory().CreateInInventory("Ammo_12gaSlug");
		player.GetInventory().CreateInInventory("Ammo_12gaSlug");
		player.GetInventory().CreateInInventory("Ammo_12gaPellets");
		player.GetInventory().CreateInInventory("Ammo_12gaPellets");
		player.GetInventory().CreateInInventory("Ammo_12gaPellets");
		player.GetInventory().CreateInInventory("Ammo_12gaRubberSlug");
		player.GetInventory().CreateInInventory("Ammo_12gaRubberSlug");
		ItemBase melee = player.GetInventory().CreateInInventory("StunBaton");
		melee.GetInventory().CreateAttachment("Battery9V");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI soldierClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"TacticalBaconCan_Opened", "TacticalBaconCan_Opened"};
		ref TStringArray drinkArray = {"Canteen", "Canteen"};
		ref TStringArray hatArray = {"BallisticHelmet_Green", "BallisticHelmet_Black", "BallisticHelmet_UN", "ZSh3PilotHelmet", "ZSh3PilotHelmet_Green", "ZSh3PilotHelmet_Black", "MilitaryBeret_Red", "MilitaryBeret_UN", "MilitaryBeret_NZ", "MilitaryBeret_ChDKZ", "MilitaryBeret_CDF", "OfficerHat", "PilotkaCap", "TankerHelmet", "GorkaHelmet", "GorkaHelmet_Green", "GorkaHelmet_Black", "GorkaHelmetComplete", "GorkaHelmetComplete_Green", "GorkaHelmetComplete_Black", "Ssh68Helmet"};
		ref TStringArray topArray = {"TacticalShirt_Olive", "TacticalShirt_Tan", "M65Jacket_Khaki", "M65Jacket_Tan", "M65Jacket_Olive", "TTsKOJacket_Camo", "GorkaEJacket_Summer", "GorkaEJacket_Flat", "GorkaEJacket_Autumn", "GorkaEJacket_PautRev", "USMCJacket_Desert", "USMCJacket_Woodland"};
		ref TStringArray pantsArray = {"TTSKOPants", "GorkaPants_Summer", "GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "USMCPants_Desert", "USMCPants_Woodland", "BDUPants"};
		ref TStringArray vestArray  = {"SmershVest","", "BallisticVest","", "UKAssVest_Black","", "UKAssVest_Camo","", "UKAssVest_Khaki","", "UKAssVest_Olive","", "HighCapacityVest_Black","", "HighCapacityVest_Olive",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","",""};
		ref TStringArray shoesArray = {"JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"TacticalGloves_Beige","", "TacticalGloves_Black","", "TacticalGloves_Green","", "OMNOGloves_Brown","", "OMNOGloves_Gray",""};
		ref TStringArray maskArray = {"BandanaMask_CamoPattern","","","","", "BalaclavaMask_Green","","","","", "GP5GasMask","","","",""};
		ref TStringArray backpackArray = {"AssaultBag_Ttsko","", "AssaultBag_Black","", "AssaultBag_Green","", "CoyoteBag_Brown","", "CoyoteBag_Green",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("BandageDressing");
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("M4A1");
		gun.GetInventory().CreateAttachment("M4_RISHndgrd");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("UniversalLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_STANAG_30Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_556x45");
		player.GetInventory().CreateInInventory("Ammo_556x45");
		ItemBase melee = player.GetInventory().CreateInInventory("CombatKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	EntityAI firefighterClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin", "PowderedMilk", "Rice", "BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "SlicedPumpkin", "Potato", "Plum", "Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"FirefightersHelmet_Red", "FirefightersHelmet_White", "FirefightersHelmet_Yellow"};
		ref TStringArray topArray = {"TShirt_White", "FirefighterJacket_Beige", "FirefighterJacket_Black", "FirefighterJacket_Beige", "FirefighterJacket_Black", "FirefighterJacket_Beige", "FirefighterJacket_Black"};
		ref TStringArray pantsArray = {"FirefightersPants_Beige", "FirefightersPants_Black"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","",""};
		ref TStringArray shoesArray = {"Wellies_Black", "Wellies_Brown", "Wellies_Green", "Wellies_Grey", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Green", "WorkingBoots_Yellow", "WorkingBoots_Beige"};
		ref TStringArray glovesArray = {"WorkingGloves_Black", "WorkingGloves_Beige", "WorkingGloves_Brown", "WorkingGloves_Yellow"};
		ref TStringArray maskArray = {"GP5GasMask","","","",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("BandageDressing");
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("SKS");
		addMags(player, "Ammo_762x39", 5);
		ItemBase melee = player.GetInventory().CreateInInventory("FirefighterAxe");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	EntityAI prisonerClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin", "PowderedMilk", "Rice", "BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "SlicedPumpkin", "Potato", "SambucusBerry", "CaninaBerry", "Plum", "Pear", "AgaricusMushroom", "AmanitaMushroom", "MacrolepiotaMushroom", "LactariusMushroom", "PsilocybeMushroom", "AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"PrisonerCap","PrisonerCap"};
		ref TStringArray topArray = {"PrisonUniformJacket","PrisonUniformJacket"};
		ref TStringArray pantsArray = {"PrisonUniformPants","PrisonUniformPants"};
		ref TStringArray shoesArray = {"AthleticShoes_Blue", "AthleticShoes_Black", "AthleticShoes_Brown", "AthleticShoes_Green", "AthleticShoes_Grey", "JoggingShoes_Black", "JoggingShoes_Blue", "JoggingShoes_Red", "JoggingShoes_Violet", "JoggingShoes_White"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","", "BandanaMask_BlackPattern","","","","", "BandanaMask_PolkaPattern","","","","", "BandanaMask_GreenPattern","","","","", "BandanaMask_CamoPattern","","","","", "HockeyMask","","","HockeyMask","","","","", "BalaclavaMask_Black","","","","", "BalaclavaMask_Blackskull","","","","", "BalaclavaMask_Beige","","","","", "BalaclavaMask_Blue","","","","", "BalaclavaMask_Green","","","","", "BalaclavaMask_Pink","","","","", "BalaclavaMask_White","","","",""};
		ref TStringArray lightArray = {"Chemlight_White","Chemlight_Blue","Chemlight_Green","Chemlight_Red","Chemlight_Yellow","Roadflare","Chemlight_White"};
		ref TStringArray meleeArray = {"Pipe","NailedBaseballBat","Pipe","Crowbar","Pipe"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		player.GetInventory().CreateInInventory("StoneKnife");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		EntityAI gun = player.GetInventory().CreateInInventory("SawedoffIzh18");
		addMags(player, "Ammo_762x39", 5);
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI hunterMaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"PigSteakMeat", "DeerSteakMeat", "Rice", "BakedBeansCan_Opened", "SheepSteakMeat", "WolfSteakMeat", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "CowSteakMeat", "Potato", "SambucusBerry", "CaninaBerry", "Plum", "Pear", "BoarSteakMeat", "GoatSteakMeat", "AgaricusMushroom", "AmanitaMushroom", "MacrolepiotaMushroom", "LactariusMushroom", "PsilocybeMushroom", "AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "Canteen", "WaterBottle"};
		ref TStringArray hatArray = {"Ushanka_Black","", "Ushanka_Blue","", "Ushanka_Green","", "RadarCap_Black","", "RadarCap_Blue","", "RadarCap_Brown","", "RadarCap_Green","", "RadarCap_Red","", "ZmijovkaCap_Black","", "ZmijovkaCap_Blue","", "ZmijovkaCap_Brown","", "ZmijovkaCap_Green","", "ZmijovkaCap_Red","", "BoonieHat_Black","", "BoonieHat_Blue","", "BoonieHat_DPM","", "BoonieHat_Dubok","", "BoonieHat_Flecktran","", "BoonieHat_NavyBlue","", "BoonieHat_Olive","", "BoonieHat_Orange","", "BoonieHat_Red","", "BoonieHat_Tan","", "LeatherHat_Natural","", "LeatherHat_Beige","", "LeatherHat_Brown","", "LeatherHat_Black",""};
		ref TStringArray topArray = {"HuntingJacket_Autumn", "HuntingJacket_Brown", "HuntingJacket_Spring", "HuntingJacket_Summer", "HuntingJacket_Winter", "HuntingJacket_Autumn", "HuntingJacket_Brown", "HuntingJacket_Spring", "HuntingJacket_Summer", "HuntingJacket_Winter"};
		ref TStringArray pantsArray = {"HunterPants_Autumn", "HunterPants_Brown", "HunterPants_Spring", "HunterPants_Summer", "HunterPants_Winter"};
		ref TStringArray vestArray  = {"LeatherStorageVest_Natural","","", "LeatherStorageVest_Beige","","", "LeatherStorageVest_Brown","","", "LeatherStorageVest_Black","",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","", "SportGlasses_Black","","","", "SportGlasses_Green","","","", "SportGlasses_Orange","","","", "AviatorGlasses","","","", "ThickFramesGlasses","","","", "ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"HikingBoots_Brown", "HikingBoots_Black", "HikingBootsLow_Black", "HikingBootsLow_Beige", "HikingBootsLow_Grey", "Wellies_Black", "Wellies_Brown", "Wellies_Green", "Wellies_Grey", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Green", "WorkingBoots_Beige"};
		ref TStringArray glovesArray = {"WorkingGloves_Black","","", "WorkingGloves_Beige","","", "WorkingGloves_Brown","",""};
		ref TStringArray backpackArray = {"HuntingBag","","","", "HuntingBag","","","", "HuntingBag","","","", "HuntingBag","","","", "HuntingBag","","","", "LeatherSack_Natural","","","", "LeatherSack_Black","","","", "LeatherSack_Beige","","","", "LeatherSack_Brown","","",""};
		ref TStringArray lightArray = {"Chemlight_White","Chemlight_Blue","Chemlight_Green","Chemlight_White","Chemlight_Red","Chemlight_Yellow","Roadflare","Chemlight_White"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		EntityAI gun = player.GetInventory().CreateInInventory("Mosin9130");
		gun.GetInventory().CreateAttachment("PUScopeOptic");
		addMags(player, "Ammo_762x54", 5);
		ItemBase melee = player.GetInventory().CreateInInventory("HuntingKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	EntityAI hunterFemaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"PigSteakMeat", "DeerSteakMeat", "Rice", "BakedBeansCan_Opened", "SheepSteakMeat", "WolfSteakMeat", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "CowSteakMeat", "Potato", "SambucusBerry", "CaninaBerry", "Plum", "Pear", "BoarSteakMeat", "GoatSteakMeat", "AgaricusMushroom", "AmanitaMushroom", "MacrolepiotaMushroom", "LactariusMushroom", "PsilocybeMushroom", "AuriculariaMushroom"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "Canteen", "WaterBottle"};
		ref TStringArray hatArray = {"Ushanka_Black","","", "Ushanka_Blue","","", "Ushanka_Green","","", "RadarCap_Black","","", "RadarCap_Blue","","", "RadarCap_Brown","","", "RadarCap_Green","","", "RadarCap_Red","","", "ZmijovkaCap_Black","","", "ZmijovkaCap_Blue","","", "ZmijovkaCap_Brown","","", "ZmijovkaCap_Green","","", "ZmijovkaCap_Red","","", "BoonieHat_Black","","", "BoonieHat_Blue","","", "BoonieHat_DPM","","", "BoonieHat_Dubok","","", "BoonieHat_Flecktran","","", "BoonieHat_NavyBlue","","", "BoonieHat_Olive","","", "BoonieHat_Orange","","", "BoonieHat_Red","","", "BoonieHat_Tan","","", "LeatherHat_Natural","","", "LeatherHat_Beige","","", "LeatherHat_Brown","","", "LeatherHat_Black","",""};
		ref TStringArray topArray = {"Raincoat_Orange", "Raincoat_Green", "Raincoat_Yellow", "Raincoat_Pink", "Raincoat_Red", "Raincoat_Blue", "Raincoat_Black", "HuntingJacket_Autumn", "HuntingJacket_Brown", "HuntingJacket_Spring", "HuntingJacket_Summer", "HuntingJacket_Winter", "HuntingJacket_Autumn", "HuntingJacket_Brown", "HuntingJacket_Spring", "HuntingJacket_Summer", "HuntingJacket_Winter"};
		ref TStringArray pantsArray = {"ShortJeans_Black", "ShortJeans_Blue", "ShortJeans_Brown", "ShortJeans_Darkblue", "ShortJeans_Green", "ShortJeans_Red", "Skirt_Blue", "Skirt_Red", "Skirt_White", "Skirt_Yellow"};
		ref TStringArray vestArray  = {"LeatherStorageVest_Natural","","", "LeatherStorageVest_Beige","","", "LeatherStorageVest_Brown","","", "LeatherStorageVest_Black","",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","", "SportGlasses_Black","","","", "SportGlasses_Green","","","", "SportGlasses_Orange","","","", "AviatorGlasses","","","", "ThickFramesGlasses","","","", "ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"HikingBoots_Brown", "HikingBoots_Black", "HikingBootsLow_Black", "HikingBootsLow_Beige", "HikingBootsLow_Grey", "Wellies_Black", "Wellies_Brown", "Wellies_Green", "Wellies_Grey", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Green", "WorkingBoots_Beige"};
		ref TStringArray glovesArray = {"WorkingGloves_Black","","", "WorkingGloves_Beige","","", "WorkingGloves_Brown","",""};
		ref TStringArray backpackArray = {"HuntingBag","","","", "HuntingBag","","","", "HuntingBag","","","", "HuntingBag","","","", "HuntingBag","","","", "LeatherSack_Natural","","","", "LeatherSack_Black","","","", "LeatherSack_Beige","","","", "LeatherSack_Brown","","",""};
		ref TStringArray lightArray = {"Chemlight_White","Chemlight_Blue","Chemlight_Green","Chemlight_White","Chemlight_Red","Chemlight_Yellow","Roadflare","Chemlight_White"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		EntityAI gun = player.GetInventory().CreateInInventory("CZ527");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "Ammo_762x39", 5);
		ItemBase melee = player.GetInventory().CreateInInventory("HuntingKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}

	EntityAI constructionMaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Plum", "Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"ConstructionHelmet_Blue", "ConstructionHelmet_Lime", "ConstructionHelmet_Orange", "ConstructionHelmet_Red", "ConstructionHelmet_White", "ConstructionHelmet_Yellow"};
		ref TStringArray topArray = {"Shirt_BlueCheck", "Shirt_BlueCheckBright", "Shirt_GreenCheck", "Shirt_RedCheck", "Shirt_WhiteCheck", "Shirt_PlaneBlack"};
		ref TStringArray pantsArray = {"Jeans_Black", "Jeans_Blue", "Jeans_Brown", "Jeans_Green", "Jeans_Grey", "Jeans_BlueDark", "CargoPants_Beige", "CargoPants_Black", "CargoPants_Blue", "CargoPants_Grey"};
		ref TStringArray vestArray  = {"ReflexVest",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","","", "ThickFramesGlasses","","", "ThinFramesGlasses","",""};
		ref TStringArray shoesArray = {"Wellies_Black", "Wellies_Brown", "Wellies_Green", "Wellies_Grey", "WorkingBoots_Yellow", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Green", "WorkingBoots_Yellow", "WorkingBoots_Beige", "WorkingBoots_Yellow"};
		ref TStringArray maskArray = {"NioshFaceMask","","",""};
		ref TStringArray glovesArray = {"WorkingGloves_Black","", "WorkingGloves_Beige","", "WorkingGloves_Brown","", "WorkingGloves_Yellow",""};
		ref TStringArray meleeArray = {"Pickaxe","Shovel","SledgeHammer"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("StoneKnife");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("AKS74U");
		addMags(player, "Mag_AK74_30Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_545x39");
		player.GetInventory().CreateInInventory("Ammo_545x39Tracer");
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI constructionFemaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Plum", "Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"ConstructionHelmet_Blue", "ConstructionHelmet_Lime", "ConstructionHelmet_Orange", "ConstructionHelmet_Red", "ConstructionHelmet_White", "ConstructionHelmet_Yellow"};
		ref TStringArray topArray = {"Shirt_BlueCheck", "Shirt_BlueCheckBright", "Shirt_GreenCheck", "Shirt_RedCheck", "Shirt_WhiteCheck", "Shirt_PlaneBlack", "TShirt_Blue", "TShirt_Red", "TShirt_White"};
		ref TStringArray pantsArray = {"ShortJeans_Black", "ShortJeans_Blue", "ShortJeans_Brown", "ShortJeans_Darkblue", "ShortJeans_Green", "ShortJeans_Red", "Skirt_Blue", "Skirt_Red", "Skirt_White", "Skirt_Yellow"};
		ref TStringArray vestArray  = {"ReflexVest",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","","", "ThickFramesGlasses","","", "ThinFramesGlasses","",""};
		ref TStringArray shoesArray = {"Wellies_Black", "Wellies_Brown", "Wellies_Green", "Wellies_Grey", "WorkingBoots_Yellow", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Green", "WorkingBoots_Yellow", "WorkingBoots_Beige", "WorkingBoots_Yellow"};
		ref TStringArray maskArray = {"NioshFaceMask","",""};
		ref TStringArray glovesArray = {"WorkingGloves_Black","", "WorkingGloves_Beige","", "WorkingGloves_Brown","", "WorkingGloves_Yellow",""};
		ref TStringArray meleeArray = {"Pickaxe","Shovel","SledgeHammer"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("StoneKnife");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("Winchester70");
		gun.GetInventory().CreateAttachment("HuntingOptic");
		addMags(player, "Ammo_308Win", 3);
		player.GetInventory().CreateInInventory("Ammo_308WinTracer");
		player.GetInventory().CreateInInventory("Ammo_308WinTracer");
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI officeMaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Plum", "Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "WaterBottle"};
		ref TStringArray hatArray = {"FlatCap_Black","","","","", "FlatCap_Blue","","","","", "FlatCap_Red","","","","", "FlatCap_Brown","","","","", "FlatCap_Grey","","","","", "FlatCap_BrownCheck","","","","", "FlatCap_GreyCheck","","","","", "FlatCap_BlackCheck","","","",""};
		ref TStringArray topArray = {"WoolCoat_Black", "WoolCoat_Red", "WoolCoat_Blue", "WoolCoat_Green", "WoolCoat_Beige", "WoolCoat_RedCheck", "WoolCoat_BlackCheck", "WoolCoat_BlueCheck", "WoolCoat_GreyCheck", "WoolCoat_BrownCheck", "Blouse_Blue", "Blouse_Green", "Blouse_Violet", "Blouse_White"};
		ref TStringArray pantsArray = {"SlacksPants_Beige", "SlacksPants_Black", "SlacksPants_Blue", "SlacksPants_Brown", "SlacksPants_DarkGrey", "SlacksPants_Khaki", "SlacksPants_LightGrey", "SlacksPants_White"};
		ref TStringArray glassesArray = {"ThickFramesGlasses","","","","ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"DressShoes_Beige", "DressShoes_Black", "DressShoes_Brown", "DressShoes_Black", "DressShoes_Brown", "DressShoes_Sunburst", "DressShoes_White"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("Pen_Black");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("Engraved1911");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("TLRLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_1911_7Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_45ACP");
		player.GetInventory().CreateInInventory("Ammo_45ACP");
		player.GetInventory().CreateInInventory("Ammo_45ACP");
		player.GetInventory().CreateInInventory("Ammo_45ACP");
		ItemBase melee = player.GetInventory().CreateInInventory("SteakKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI officeFemaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Plum", "Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "WaterBottle"};
		ref TStringArray hatArray = {"FlatCap_Black","","","","", "FlatCap_Blue","","","","", "FlatCap_Red","","","","", "FlatCap_Brown","","","","", "FlatCap_Grey","","","","", "FlatCap_BrownCheck","","","","", "FlatCap_GreyCheck","","","","", "FlatCap_BlackCheck","","","",""};
		ref TStringArray topArray = {"WoolCoat_Black", "WoolCoat_Red", "WoolCoat_Blue", "WoolCoat_Green", "WoolCoat_Beige", "WoolCoat_RedCheck", "WoolCoat_BlackCheck", "WoolCoat_BlueCheck", "WoolCoat_GreyCheck", "WoolCoat_BrownCheck", "Blouse_Blue", "Blouse_Green", "Blouse_Violet", "Blouse_White"};
		ref TStringArray pantsArray = {"Skirt_Blue", "Skirt_Red", "Skirt_White", "Skirt_Yellow"};
		ref TStringArray glassesArray = {"ThickFramesGlasses","","","","ThinFramesGlasses","","",""};
		ref TStringArray shoesArray = {"DressShoes_Beige", "DressShoes_Black", "DressShoes_Brown", "DressShoes_Black", "DressShoes_Brown", "DressShoes_Sunburst", "DressShoes_White"};
		ref TStringArray lightArray = {"Chemlight_White","Chemlight_Yellow","Chemlight_White"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		player.GetInventory().CreateInInventory("Pen_Blue");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("Mp133Shotgun");
		addMags(player, "Ammo_12gaSlug", 12);
		ItemBase melee = player.GetInventory().CreateInInventory("SteakKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI bikerMaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin", "PowderedMilk", "Rice", "BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "SlicedPumpkin", "Potato", "Plum", "Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"MotoHelmet_Black", "MotoHelmet_Grey", "MotoHelmet_Green", "MotoHelmet_Lime", "MotoHelmet_Blue", "MotoHelmet_Red", "MotoHelmet_White", "DarkMotoHelmet_Black", "DarkMotoHelmet_Grey", "DarkMotoHelmet_Green", "DarkMotoHelmet_Lime", "DarkMotoHelmet_Blue", "DarkMotoHelmet_Red", "DarkMotoHelmet_White", "DirtBikeHelmet_Green", "DirtBikeHelmet_Chernarus", "DirtBikeHelmet_Khaki", "DirtBikeHelmet_Red", "DirtBikeHelmet_Black", "DirtBikeHelmet_Blue"};
		ref TStringArray topArray = {"RidersJacket_Black","RidersJacket_Black"};
		ref TStringArray pantsArray = {"Jeans_Black", "Jeans_Blue", "Jeans_Brown", "Jeans_Green", "Jeans_Grey", "Jeans_BlueDark", "CargoPants_Beige", "CargoPants_Black", "CargoPants_Blue", "CargoPants_Green", "CargoPants_Grey", "TTSKOPants", "HunterPants_Autumn", "HunterPants_Brown", "HunterPants_Spring", "HunterPants_Summer", "HunterPants_Winter", "GorkaPants_Summer", "GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "USMCPants_Desert", "USMCPants_Woodland", "BDUPants"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","", "SportGlasses_Black","", "SportGlasses_Green","", "SportGlasses_Orange","", "AviatorGlasses",""};
		ref TStringArray shoesArray = {"HikingBoots_Brown", "HikingBoots_Black", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"WorkingGloves_Black", "WorkingGloves_Brown", "TacticalGloves_Black", "TacticalGloves_Green", "OMNOGloves_Brown", "OMNOGloves_Gray"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","", "BandanaMask_BlackPattern","", "BandanaMask_PolkaPattern","", "BandanaMask_GreenPattern","", "BandanaMask_CamoPattern","", "HockeyMask","", "BalaclavaMask_Black","", "BalaclavaMask_Blackskull","", "BalaclavaMask_Green",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("StoneKnife");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("AKM");
		gun.GetInventory().CreateAttachment("AK_RailHndgrd");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("UniversalLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_AKM_30Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_762x39");
		player.GetInventory().CreateInInventory("Ammo_762x39");
		ItemBase melee = player.GetInventory().CreateInInventory("BrassKnuckles_Shiny");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI bikerFemaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin", "PowderedMilk", "Rice", "BakedBeansCan_Opened", "PeachesCan_Opened", "SpaghettiCan_Opened", "SardinesCan_Opened", "TunaCan_Opened", "Apple", "Tomato", "GreenBellPepper", "Zucchini", "SlicedPumpkin", "Potato", "Plum", "Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola", "SodaCan_Pipsi", "SodaCan_Spite", "SodaCan_Kvass", "WaterBottle"};
		ref TStringArray hatArray = {"MotoHelmet_Black", "MotoHelmet_Grey", "MotoHelmet_Green", "MotoHelmet_Lime", "MotoHelmet_Blue", "MotoHelmet_Red", "MotoHelmet_White", "DarkMotoHelmet_Black", "DarkMotoHelmet_Grey", "DarkMotoHelmet_Green", "DarkMotoHelmet_Lime", "DarkMotoHelmet_Blue", "DarkMotoHelmet_Red", "DarkMotoHelmet_White", "DirtBikeHelmet_Green", "DirtBikeHelmet_Chernarus", "DirtBikeHelmet_Khaki", "DirtBikeHelmet_Red", "DirtBikeHelmet_Black", "DirtBikeHelmet_Blue"};
		ref TStringArray topArray = {"RidersJacket_Black","RidersJacket_Black"};
		ref TStringArray pantsArray = {"ShortJeans_Black", "ShortJeans_Blue", "ShortJeans_Brown", "ShortJeans_Darkblue", "ShortJeans_Green", "ShortJeans_Red", "Skirt_Blue", "Skirt_Red", "Skirt_White", "Skirt_Yellow"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","", "SportGlasses_Black","", "SportGlasses_Green","", "SportGlasses_Orange","", "AviatorGlasses",""};
		ref TStringArray shoesArray = {"HikingBoots_Brown", "HikingBoots_Black", "WorkingBoots_Grey", "WorkingBoots_Brown", "WorkingBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"WorkingGloves_Black", "WorkingGloves_Brown", "TacticalGloves_Black", "TacticalGloves_Green", "OMNOGloves_Brown", "OMNOGloves_Gray"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","", "BandanaMask_BlackPattern","", "BandanaMask_PolkaPattern","", "BandanaMask_GreenPattern","", "BandanaMask_CamoPattern","", "HockeyMask","", "BalaclavaMask_Black","", "BalaclavaMask_Blackskull","", "BalaclavaMask_Green",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("AK101_Black");
		gun.GetInventory().CreateAttachment("AK_RailHndgrd");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("UniversalLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_AK101_30Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_556x45");
		player.GetInventory().CreateInInventory("Ammo_556x45Tracer");
		ItemBase melee = player.GetInventory().CreateInInventory("Machete");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI nbcClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin","PowderedMilk","Rice","BakedBeansCan_Opened","PeachesCan_Opened","SpaghettiCan_Opened","SardinesCan_Opened","TunaCan_Opened","Apple","Tomato","GreenBellPepper","Zucchini","SlicedPumpkin","Potato","Plum","Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","WaterBottle"};
		ref TStringArray hatArray = {"NBCHoodGray","NBCHoodGray"};
		ref TStringArray topArray = {"NBCJacketGray","NBCJacketGray"};
		ref TStringArray pantsArray = {"NBCPantsGray","NBCPantsGray"};
		ref TStringArray shoesArray = {"NBCBootsGray","NBCBootsGray"};
		ref TStringArray glovesArray = {"NBCGlovesGray","NBCGlovesGray"};
		ref TStringArray maskArray = {"GP5GasMask","GP5GasMask"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("BandageDressing");
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("MP5K");
		gun.GetInventory().CreateAttachment("MP5_RailHndgrd");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("UniversalLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_MP5_30Rnd", 3);
		player.GetInventory().CreateInInventory("Ammo_9x19");
		player.GetInventory().CreateInInventory("Ammo_9x19");
		ItemBase melee = player.GetInventory().CreateInInventory("CombatKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI mechanicClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BakedBeansCan_Opened","SpaghettiCan_Opened","SardinesCan_Opened","TunaCan_Opened","Potato"};
		ref TStringArray drinkArray = {"SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","WaterBottle"};
		ref TStringArray hatArray = {"BaseballCap_Blue","","","","BaseballCap_Beige","","","","BaseballCap_Black","","","","BaseballCap_Olive","","","","BaseballCap_Pink","","","","BaseballCap_Red","","","","BaseballCap_Camo","","","","BaseballCap_CMMG_Black","","","","BaseballCap_CMMG_Pink","","","","BeanieHat_Beige","","","","BeanieHat_Black","","","","BeanieHat_Blue","","","","BeanieHat_Brown","","","","BeanieHat_Green","","","","BeanieHat_Grey","","","","BeanieHat_Pink","","","","BeanieHat_Red","","","","Ushanka_Black","","","","Ushanka_Blue","","","","Ushanka_Green","","","","RadarCap_Black","","","","RadarCap_Blue","","","","RadarCap_Brown","","","","RadarCap_Green","","","","RadarCap_Red","","","","FlatCap_Black","","","","FlatCap_Blue","","","","FlatCap_Red","","","","FlatCap_Brown","","","","FlatCap_Grey","","","","FlatCap_BrownCheck","","","","FlatCap_GreyCheck","","","","FlatCap_BlackCheck"};
		ref TStringArray topArray = {"JumpsuitJacket_Blue","JumpsuitJacket_Gray","JumpsuitJacket_Green","JumpsuitJacket_Red"};
		ref TStringArray pantsArray = {"JumpsuitPants_Blue","JumpsuitPants_Green","JumpsuitPants_Grey","JumpsuitPants_Red"};
		ref TStringArray shoesArray = {"AthleticShoes_Blue","AthleticShoes_Black","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey","WorkingBoots_Grey","WorkingBoots_Brown","WorkingBoots_Green","WorkingBoots_Yellow","WorkingBoots_Beige","JoggingShoes_Black","JoggingShoes_Blue","JoggingShoes_Red","JoggingShoes_Violet","JoggingShoes_White","Sneakers_Black","Sneakers_Gray","Sneakers_Green","Sneakers_Red","Sneakers_White"};
		ref TStringArray glovesArray = {"WorkingGloves_Black","", "WorkingGloves_Beige","", "WorkingGloves_Brown","", "WorkingGloves_Yellow","", "SurgicalGloves_Blue","", "SurgicalGloves_Green",""};
		ref TStringArray maskArray = {"NioshFaceMask","","","","",""};
		ref TStringArray mechanicArray = {"TireRepairKit","EngineOil","CarBattery","BatteryCharger","Wrench","Screwdriver"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(mechanicArray.GetRandomElement());
		player.GetInventory().CreateInInventory("SparkPlug");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(6);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("B95");
		addMags(player, "Ammo_308Win", 3);
		player.GetInventory().CreateInInventory("Ammo_308WinTracer");
		player.GetInventory().CreateInInventory("Ammo_308WinTracer");
		ItemBase melee = player.GetInventory().CreateInInventory("LugWrench");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI mercenaryMaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin","PowderedMilk","Rice","BakedBeansCan_Opened","PeachesCan_Opened","SpaghettiCan_Opened","SardinesCan_Opened","TunaCan_Opened","Apple","Tomato","GreenBellPepper","Zucchini","SlicedPumpkin","Potato","Plum","Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","SodaCan_Kvass","WaterBottle"};
		ref TStringArray hatArray = {"BallisticHelmet_Green", "BallisticHelmet_Black", "BallisticHelmet_UN", "ZSh3PilotHelmet", "ZSh3PilotHelmet_Green", "ZSh3PilotHelmet_Black", "MilitaryBeret_Red", "MilitaryBeret_UN", "MilitaryBeret_NZ", "MilitaryBeret_ChDKZ", "MilitaryBeret_CDF", "OfficerHat", "PilotkaCap", "TankerHelmet", "GorkaHelmet", "GorkaHelmet_Green", "GorkaHelmet_Black", "GorkaHelmetComplete", "GorkaHelmetComplete_Green", "GorkaHelmetComplete_Black", "Ssh68Helmet","","","","","","","","",""};
		ref TStringArray topArray = {"TacticalShirt_Olive", "TacticalShirt_Tan", "M65Jacket_Khaki", "M65Jacket_Tan", "M65Jacket_Olive", "TTsKOJacket_Camo", "GorkaEJacket_Summer", "GorkaEJacket_Flat", "GorkaEJacket_Autumn", "GorkaEJacket_PautRev", "USMCJacket_Desert", "USMCJacket_Woodland", "RidersJacket_Black"};
		ref TStringArray pantsArray = {"TTSKOPants", "GorkaPants_Summer", "GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "USMCPants_Desert", "USMCPants_Woodland", "BDUPants", "Jeans_Black","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey","Jeans_BlueDark","CargoPants_Beige","CargoPants_Black","CargoPants_Blue","CargoPants_Green","CargoPants_Grey"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","",""};
		ref TStringArray shoesArray = {"JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"TacticalGloves_Beige","", "TacticalGloves_Black","", "TacticalGloves_Green","", "OMNOGloves_Brown","", "OMNOGloves_Gray",""};
		ref TStringArray maskArray = {"BandanaMask_CamoPattern","","BalaclavaMask_Green","","BandanaMask_RedPattern","","BandanaMask_BlackPattern","","","BandanaMask_PolkaPattern","","BandanaMask_GreenPattern","","BalaclavaMask_Black","","BalaclavaMask_Blackskull","","BalaclavaMask_Beige","","BalaclavaMask_Blue","","BalaclavaMask_Pink","","BalaclavaMask_White"};
		ref TStringArray backpackArray = {"AssaultBag_Ttsko","", "AssaultBag_Black","", "AssaultBag_Green","", "CoyoteBag_Brown","", "CoyoteBag_Green","","","","","","","","","","","",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("DuctTape");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("AK74");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("UniversalLight");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_AK74_30Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_545x39");
		player.GetInventory().CreateInInventory("Ammo_545x39Tracer");
		ItemBase melee = player.GetInventory().CreateInInventory("HuntingKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI mercenaryFemaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"BoxCerealCrunchin","PowderedMilk","Rice","BakedBeansCan_Opened","PeachesCan_Opened","SpaghettiCan_Opened","SardinesCan_Opened","TunaCan_Opened","Apple","Tomato","GreenBellPepper","Zucchini","SlicedPumpkin","Potato","Plum","Pear"};
		ref TStringArray drinkArray = {"SodaCan_Cola","SodaCan_Pipsi","SodaCan_Spite","SodaCan_Kvass","WaterBottle"};
		ref TStringArray hatArray = {"BallisticHelmet_Green", "BallisticHelmet_Black", "BallisticHelmet_UN", "ZSh3PilotHelmet", "ZSh3PilotHelmet_Green", "ZSh3PilotHelmet_Black", "MilitaryBeret_Red", "MilitaryBeret_UN", "MilitaryBeret_NZ", "MilitaryBeret_ChDKZ", "MilitaryBeret_CDF", "OfficerHat", "PilotkaCap", "TankerHelmet", "GorkaHelmet", "GorkaHelmet_Green", "GorkaHelmet_Black", "GorkaHelmetComplete", "GorkaHelmetComplete_Green", "GorkaHelmetComplete_Black", "Ssh68Helmet","","","","","","","","",""};
		ref TStringArray topArray = {"TacticalShirt_Olive", "TacticalShirt_Tan", "M65Jacket_Khaki", "M65Jacket_Tan", "M65Jacket_Olive", "TTsKOJacket_Camo", "GorkaEJacket_Summer", "GorkaEJacket_Flat", "GorkaEJacket_Autumn", "GorkaEJacket_PautRev", "USMCJacket_Desert", "USMCJacket_Woodland", "RidersJacket_Black"};
		ref TStringArray pantsArray = {"TTSKOPants", "GorkaPants_Summer", "GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "USMCPants_Desert", "USMCPants_Woodland", "BDUPants", "Jeans_Black","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey","Jeans_BlueDark","CargoPants_Beige","CargoPants_Black","CargoPants_Blue","CargoPants_Green","CargoPants_Grey"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","",""};
		ref TStringArray shoesArray = {"JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"TacticalGloves_Beige","", "TacticalGloves_Black","", "TacticalGloves_Green","", "OMNOGloves_Brown","", "OMNOGloves_Gray",""};
		ref TStringArray maskArray = {"BandanaMask_CamoPattern","","BalaclavaMask_Green","","BandanaMask_RedPattern","","BandanaMask_BlackPattern","","","BandanaMask_PolkaPattern","","BandanaMask_GreenPattern","","BalaclavaMask_Black","","BalaclavaMask_Blackskull","","BalaclavaMask_Beige","","BalaclavaMask_Blue","","BalaclavaMask_Pink","","BalaclavaMask_White"};
		ref TStringArray backpackArray = {"AssaultBag_Ttsko","", "AssaultBag_Black","", "AssaultBag_Green","", "CoyoteBag_Brown","", "CoyoteBag_Green","","","","","","","","","","","",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("DuctTape");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("FAL");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("M68Optic");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_FAL_20Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_308Win");
		player.GetInventory().CreateInInventory("Ammo_308Win");
		player.GetInventory().CreateInInventory("Ammo_308WinTracer");
		ItemBase melee = player.GetInventory().CreateInInventory("HuntingKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI sniperMaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"TacticalBaconCan_Opened", "TacticalBaconCan_Opened"};
		ref TStringArray drinkArray = {"Canteen", "Canteen"};
		ref TStringArray hatArray = {"GhillieHood_Tan", "GhillieHood_Woodland", "GhillieHood_Mossy", ""};
		ref TStringArray topArray = {"TacticalShirt_Olive", "TacticalShirt_Tan", "M65Jacket_Khaki", "M65Jacket_Tan", "M65Jacket_Olive", "TTsKOJacket_Camo", "GorkaEJacket_Summer", "GorkaEJacket_Flat", "GorkaEJacket_Autumn", "GorkaEJacket_PautRev", "USMCJacket_Desert", "USMCJacket_Woodland"};
		ref TStringArray pantsArray = {"TTSKOPants", "GorkaPants_Summer", "GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "USMCPants_Desert", "USMCPants_Woodland", "BDUPants"};
		ref TStringArray vestArray  = {"SmershVest","", "BallisticVest","", "UKAssVest_Black","", "UKAssVest_Camo","", "UKAssVest_Khaki","", "UKAssVest_Olive","", "HighCapacityVest_Black","", "HighCapacityVest_Olive",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","",""};
		ref TStringArray shoesArray = {"JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"TacticalGloves_Beige","", "TacticalGloves_Black","", "TacticalGloves_Green","", "OMNOGloves_Brown","", "OMNOGloves_Gray",""};
		ref TStringArray maskArray = {"BandanaMask_CamoPattern","","","","", "BalaclavaMask_Green","","","","", "GP5GasMask","","","",""};
		ref TStringArray backpackArray = {"GhillieTop_Woodland","", "GhillieSuit_Woodland","", "GhillieBushrag_Tan","", "GhillieTop_Tan","", "GhillieSuit_Tan","", "GhillieTop_Mossy","", "GhillieSuit_Mossy",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("Compass");
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("VSS");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("PSO11Optic");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_VSS_10Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_9x39");
		player.GetInventory().CreateInInventory("Ammo_9x39");
		player.GetInventory().CreateInInventory("Ammo_9x39AP");
		ItemBase melee = player.GetInventory().CreateInInventory("CombatKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI sniperFemaleClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"TacticalBaconCan_Opened", "TacticalBaconCan_Opened"};
		ref TStringArray drinkArray = {"Canteen", "Canteen"};
		ref TStringArray hatArray = {"BallisticHelmet_Green", "BallisticHelmet_Black", "BallisticHelmet_UN", "ZSh3PilotHelmet", "ZSh3PilotHelmet_Green", "ZSh3PilotHelmet_Black", "MilitaryBeret_Red", "MilitaryBeret_UN", "MilitaryBeret_NZ", "MilitaryBeret_ChDKZ", "MilitaryBeret_CDF", "OfficerHat", "PilotkaCap", "TankerHelmet", "GorkaHelmet", "GorkaHelmet_Green", "GorkaHelmet_Black", "GorkaHelmetComplete", "GorkaHelmetComplete_Green", "GorkaHelmetComplete_Black", "GhillieHood_Tan", "GhillieHood_Woodland", "GhillieHood_Mossy", "Ssh68Helmet"};
		ref TStringArray topArray = {"TacticalShirt_Olive", "TacticalShirt_Tan", "M65Jacket_Khaki", "M65Jacket_Tan", "M65Jacket_Olive", "TTsKOJacket_Camo", "GorkaEJacket_Summer", "GorkaEJacket_Flat", "GorkaEJacket_Autumn", "GorkaEJacket_PautRev", "USMCJacket_Desert", "USMCJacket_Woodland", "MiniDress_GreenChecker"};
		ref TStringArray pantsArray = {"TTSKOPants", "GorkaPants_Summer", "GorkaPants_Autumn", "GorkaPants_Flat", "GorkaPants_PautRev", "USMCPants_Desert", "USMCPants_Woodland", "BDUPants", "ShortJeans_Black", "ShortJeans_Blue", "ShortJeans_Brown", "ShortJeans_Darkblue", "ShortJeans_Green", "ShortJeans_Red", "Skirt_Blue", "Skirt_Red", "Skirt_White", "Skirt_Yellow"};
		ref TStringArray vestArray  = {"SmershVest","", "BallisticVest","", "UKAssVest_Black","", "UKAssVest_Camo","", "UKAssVest_Khaki","", "UKAssVest_Olive","", "HighCapacityVest_Black","", "HighCapacityVest_Olive",""};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","", "SportGlasses_Black","","", "SportGlasses_Green","","", "SportGlasses_Orange","","", "AviatorGlasses","",""};
		ref TStringArray shoesArray = {"JungleBoots_Beige", "JungleBoots_Black", "JungleBoots_Brown", "JungleBoots_Green", "JungleBoots_Olive", "MilitaryBoots_Beige", "MilitaryBoots_Black", "MilitaryBoots_Bluerock", "MilitaryBoots_Brown", "MilitaryBoots_Redpunk", "CombatBoots_Beige", "CombatBoots_Black", "CombatBoots_Brown", "CombatBoots_Green", "CombatBoots_Grey"};
		ref TStringArray glovesArray = {"TacticalGloves_Beige","", "TacticalGloves_Black","", "TacticalGloves_Green","", "OMNOGloves_Brown","", "OMNOGloves_Gray",""};
		ref TStringArray maskArray = {"BandanaMask_CamoPattern","","","","", "BalaclavaMask_Green","","","","", "GP5GasMask","","","",""};
		ref TStringArray backpackArray = {"GhillieTop_Woodland","", "GhillieSuit_Woodland","", "GhillieBushrag_Tan","", "GhillieTop_Tan","", "GhillieSuit_Tan","", "GhillieTop_Mossy","", "GhillieSuit_Mossy","", "AssaultBag_Ttsko","", "AssaultBag_Black","", "AssaultBag_Green","", "CoyoteBag_Brown","", "CoyoteBag_Green",""};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glovesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(backpackArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory("BandageDressing");
		player.GetInventory().CreateInInventory("Compass");
		ItemBase light = player.GetInventory().CreateInInventory("Flashlight");
		light.GetInventory().CreateAttachment("Battery9V");
		EntityAI gun = player.GetInventory().CreateInInventory("SVD");
		ItemBase gunlight = gun.GetInventory().CreateAttachment("PSO1Optic");
		gunlight.GetInventory().CreateAttachment("Battery9V");
		addMags(player, "Mag_SVD_10Rnd", 2);
		player.GetInventory().CreateInInventory("Ammo_762x54");
		player.GetInventory().CreateInInventory("Ammo_762x54");
		player.GetInventory().CreateInInventory("Ammo_762x54Tracer");
		ItemBase melee = player.GetInventory().CreateInInventory("CombatKnife");
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI cowboyClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"CowSteakMeat","PowderedMilk","Rice","BakedBeansCan_Opened","Potato"};
		ref TStringArray drinkArray = {"SodaCan_Kvass","SodaCan_Kvass"};
		ref TStringArray hatArray = {"CowboyHat_Brown","CowboyHat_black","CowboyHat_darkBrown","CowboyHat_green"};
		ref TStringArray topArray = {"Shirt_BlueCheck","Shirt_BlueCheckBright","Shirt_GreenCheck","Shirt_RedCheck","Shirt_WhiteCheck","Shirt_PlaneBlack"};
		ref TStringArray pantsArray = {"Jeans_Blue","Jeans_BlueDark"};
		ref TStringArray vestArray  = {"LeatherStorageVest_Natural","", "LeatherStorageVest_Beige","", "LeatherStorageVest_Brown","", "LeatherStorageVest_Black","","ChestHolster","ChestHolster","ChestHolster","ChestHolster"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","","SportGlasses_Black","","","","SportGlasses_Green","","","","SportGlasses_Orange","","","","AviatorGlasses","","","",""};
		ref TStringArray shoesArray = {"Wellies_Black","Wellies_Brown","Wellies_Green","Wellies_Grey","WorkingBoots_Grey","WorkingBoots_Brown","WorkingBoots_Green","WorkingBoots_Beige"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","","","BandanaMask_BlackPattern","","","","","","BandanaMask_PolkaPattern","","","","","","BandanaMask_GreenPattern","","","","","",""};
		ref TStringArray lightArray = {"Roadflare","Roadflare"};
		ref TStringArray meleeArray = {"BaseballBat","BaseballBat"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		player.GetInventory().CreateInInventory("HuntingKnife");
		player.GetInventory().CreateInInventory("Rope");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		EntityAI gun = player.GetInventory().CreateInInventory("Repeater");
		addMags(player, "Ammo_357", 5);
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	EntityAI cowgirlClass(PlayerBase player)
	{
		ref TStringArray foodArray = {"CowSteakMeat","PowderedMilk","Rice","BakedBeansCan_Opened","Tomato","GreenBellPepper","SlicedPumpkin","Potato"};
		ref TStringArray drinkArray = {"SodaCan_Kvass","SodaCan_Kvass"};
		ref TStringArray hatArray = {"CowboyHat_Brown","CowboyHat_black","CowboyHat_darkBrown","CowboyHat_green"};
		ref TStringArray topArray = {"Shirt_BlueCheck","Shirt_BlueCheckBright","Shirt_GreenCheck","Shirt_RedCheck","Shirt_WhiteCheck","Shirt_PlaneBlack"};
		ref TStringArray pantsArray = {"ShortJeans_Black", "ShortJeans_Blue", "ShortJeans_Brown", "ShortJeans_Darkblue", "ShortJeans_Green", "ShortJeans_Red", "Skirt_Blue", "Skirt_Red", "Skirt_White", "Skirt_Yellow"};
		ref TStringArray vestArray  = {"LeatherStorageVest_Natural","","","", "LeatherStorageVest_Beige","","","", "LeatherStorageVest_Brown","","","", "LeatherStorageVest_Black","","","","ChestHolster","ChestHolster","ChestHolster","ChestHolster"};
		ref TStringArray glassesArray = {"SportGlasses_Blue","","","","SportGlasses_Black","","","","SportGlasses_Green","","","","SportGlasses_Orange","","","","AviatorGlasses","","","",""};
		ref TStringArray shoesArray = {"Wellies_Black","Wellies_Brown","Wellies_Green","Wellies_Grey","WorkingBoots_Grey","WorkingBoots_Brown","WorkingBoots_Green","WorkingBoots_Beige"};
		ref TStringArray maskArray = {"BandanaMask_RedPattern","","","","","","BandanaMask_BlackPattern","","","","","","BandanaMask_PolkaPattern","","","","","","BandanaMask_GreenPattern","","","","","",""};
		ref TStringArray lightArray = {"Roadflare","Roadflare"};
		ref TStringArray meleeArray = {"BaseballBat","BaseballBat"};

		player.GetInventory().CreateInInventory(hatArray.GetRandomElement());
		player.GetInventory().CreateInInventory(topArray.GetRandomElement());
		player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		player.GetInventory().CreateInInventory(vestArray.GetRandomElement());
		player.GetInventory().CreateInInventory(glassesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		player.GetInventory().CreateInInventory(maskArray.GetRandomElement());
		player.GetInventory().CreateInInventory(foodArray.GetRandomElement());
		player.GetInventory().CreateInInventory(drinkArray.GetRandomElement());
		player.GetInventory().CreateInInventory(lightArray.GetRandomElement());
		player.GetInventory().CreateInInventory("HuntingKnife");
		player.GetInventory().CreateInInventory("Rope");
		ItemBase rags = player.GetInventory().CreateInInventory("Rag");
		rags.SetQuantity(4);
		EntityAI gun = player.GetInventory().CreateInInventory("Repeater");
		addMags(player, "Ammo_357", 5);
		ItemBase melee = player.GetInventory().CreateInInventory(meleeArray.GetRandomElement());
		
		player.SetQuickBarEntityShortcut(gun, 0, true);
		player.SetQuickBarEntityShortcut(melee, 1, true);
		return gun;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		
		if(player.IsMale())
		{
			EntityAI male;
			switch (Math.RandomInt(0, 30)) 
			{
				case 0: male = randomMaleClass(player); break;
				case 1: male = doctorClass(player); break;
				case 2: male = nurseMaleClass(player); break;
				case 3: male = policemanClass(player); break;
				case 4: male = soldierClass(player); break;
				case 5: male = firefighterClass(player); break;
				case 6: male = prisonerClass(player); break;
				case 7: male = hunterMaleClass(player); break;
				case 8: male = constructionMaleClass(player); break;
				case 9: male = officeMaleClass(player); break;
				case 10: male = bikerMaleClass(player); break;
				case 11: male = nbcClass(player); break;
				case 12: male = mercenaryMaleClass(player); break;
				case 13: male = mechanicClass(player); break;
				case 14: male = cowboyClass(player); break;
				case 15: male = prisonerClass(player); break;
				case 16: male = sniperMaleClass(player); break;
				case 17: male = randomMaleClass(player); break;
				case 18: male = randomMaleClass(player); break;
				case 19: male = randomMaleClass(player); break;
				case 20: male = randomMaleClass(player); break;
				case 21: male = randomMaleClass(player); break;
				case 22: male = randomMaleClass(player); break;
				case 23: male = officeMaleClass(player); break;
				case 24: male = cowboyClass(player); break;
				case 25: male = hunterMaleClass(player); break;
				case 26: male = nurseMaleClass(player); break;
				case 27: male = prisonerClass(player); break;
				case 28: male = prisonerClass(player); break;
				case 29: male = prisonerClass(player); break;
			}
		}
		
		else
		{
			EntityAI female;
			switch (Math.RandomInt(0, 30)) 
			{
				case 0: female = randomFemaleClass(player); break;
				case 1: female = randomFemale2Class(player); break;
				case 2: female = nurseClass(player); break;
				case 3: female = policewomanClass(player); break;
				case 4: female = soldierClass(player); break;
				case 5: female = firefighterClass(player); break;
				case 6: female = prisonerClass(player); break;
				case 7: female = hunterFemaleClass(player); break;
				case 8: female = constructionFemaleClass(player); break;
				case 9: female = officeFemaleClass(player); break;
				case 10: female = bikerFemaleClass(player); break;
				case 11: female = nbcClass(player); break;
				case 12: female = scientistClass(player); break;
				case 13: female = mercenaryFemaleClass(player); break;
				case 14: female = prisonerClass(player); break;
				case 15: female = prisonerClass(player); break;
				case 16: female = nurseClass(player); break;
				case 17: female = cowgirlClass(player); break;
				case 18: female = sniperFemaleClass(player); break;
				case 19: female = mechanicClass(player); break;
				case 20: female = randomFemaleClass(player); break;
				case 21: female = randomFemaleClass(player); break;
				case 22: female = randomFemaleClass(player); break;
				case 23: female = randomFemaleClass(player); break;
				case 24: female = randomFemaleClass(player); break;
				case 25: female = randomFemale2Class(player); break;
				case 26: female = randomFemale2Class(player); break;
				case 27: female = randomFemale2Class(player); break;
				case 28: female = randomFemale2Class(player); break;
				case 29: female = randomFemale2Class(player); break;
			}
		}
	}
	//MODDED LOADOUTS - END-------------------------------------
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}