#define CONTAINER_EMPTY(CLASSNAME,NAME,LOAD,MODEL,PREVIEW) \
	class GVAR(CLASSNAME): ReammoBox_F { \
		scope = 2; \
		scopeCurator = 2; \
		editorCategory = QUOTE(EdCat_UNITAF); \
		editorSubcategory = QUOTE(EdSubcat_UNITAF_Logistics); \
		displayName = QUOTE(NAME); \
		maximumLoad = LOAD; \
		model = QUOTE(MODEL); \
		editorPreview = QUOTE(PREVIEW); \
		class TransportMagazines {}; \
		class TransportWeapons {}; \
		class TransportItems {}; \
		class TransportBackpacks {}; \
	};

class CfgVehicles {
	class ReammoBox_F;

/*
	// Small Containers
	class Land_Cargo20_white_F;
		// editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_white_F.jpg";
		// model = "\A3\Structures_F\Ind\Cargo\Cargo20_white_F.p3d";
	class Land_Cargo20_sand_F;
	class Land_Cargo20_military_green_F;
	class Land_Cargo20_grey_F;

	// Medium Containers
	class Land_Cargo10_white_F;
	class Land_Cargo10_sand_F;
	class Land_Cargo10_military_green_F;
	class Land_Cargo10_grey_F;

	// Huron Slingload
	class B_Slingload_01_Cargo_F;
	class B_Slingload_01_Ammo_F;
	class B_Slingload_01_Medevac_F;
	class B_Slingload_01_Repair_F;
	class B_Slingload_01_Fuel_F;

	// Cargo Boxes
	class CargoNet_01_box_F;
	class B_CargoNet_01_ammo_F;
	class CargoNet_01_barrels_F;

	class Box_NATO_AmmoVeh_F;
	class B_supplyCrate_F;
	class C_IDAP_supplyCrate_F;
	class Land_WoodenBox_02_F;
	class Land_FoodSacks_01_cargo_brown_F;
	class Land_Pallet_MilBoxes_F;
	class Land_waterBottle_01_stack_F;

	class Box_FIA_Ammo_F;
	class Box_FIA_Support_F;
	class Box_FIA_Wps_F;

	// Small Crates
	class Box_NATO_Ammo_F;
	class Box_NATO_Wps_F;
	class Box_NATO_Equip_F;
	class Box_NATO_AmmoOrd_F;
	class Box_NATO_Grenades_F;
	class Box_NATO_WpsLaunch_F;
	class Box_NATO_Wps_Special_F;
	class Box_NATO_Support_F;
	class Box_NATO_Uniforms_F;
*/

// Varient #	Hull Configuration					Weapon System	Pax Cap		Camoflauge
// 47/190		Medical								-				0			Medical
// 47/199		Supply, AT light					-				0			-
// 47/200		Supply, Platoon						-				0			-
// 47/201		Supply, AT Medium					-				0			-
// 47/202		Supply, AT Heavy					-				0			-
// 47/203		Supply, Humanitairian , Food		-				0			-
// 47/204		Supply, Construction , FOB			-				0			-
// 47/205		Supply, Humanitarian , Utility		-				0			-
// 47/206		Supply, Construction , COP			-				0			-

/*
DEFAULT LOADOUT SINGLE UNIT
	1 Earplug
	1 Personal Aid Kit (PAK)
	2 Cable Ties
	2 Morphine
	2 Splint
	4 Tourniquet
	15 Elastic Bandage
	8 Primary Mags (of which 4 are tracer)
	2-4 Secondary Mags
	4 White Smoke Grenades
	2 Fragmentation Grenades

PLATOON SIZE: 30
SQUAD SIZE: 14
FIRETEAM SIZE: 6
*/
	CONTAINER_EMPTY(Container_Medium_White,Supply Container Medium White (empty),35000,\A3\Structures_F\Ind\Cargo\Cargo20_white_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_white_F.jpg)
	CONTAINER_EMPTY(Container_Medium_Sand,Supply Container Medium Sand (empty),35000,\A3\Structures_F\Ind\Cargo\Cargo20_sand_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_sand_F.jpg)
	CONTAINER_EMPTY(Container_Medium_Military_Green,Supply Container Medium Military Green (empty),35000,\A3\Structures_F\Ind\Cargo\Cargo20_military_green_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_military_green_F.jpg)
	CONTAINER_EMPTY(Container_Medium_Grey,Supply Container Medium Grey (empty),35000,\A3\Structures_F\Ind\Cargo\Cargo20_grey_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_grey_F.jpg)

	CONTAINER_EMPTY(Container_Small_White,Supply Container Small White (empty),35000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_white_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_white_F.jpg)
	CONTAINER_EMPTY(Container_Small_Sand,Supply Container Small Sand (empty),35000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_sand_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_sand_F.jpg)
	CONTAINER_EMPTY(Container_Small_Military_Green,Supply Container Small Military Green (empty),35000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_military_green_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_military_green_F.jpg)
	CONTAINER_EMPTY(Container_Small_Grey,Supply Container Small Grey (empty),35000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_grey_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_grey_F.jpg)

	CONTAINER_EMPTY(Container_Sling_Ammo,Huron Ammo Container (empty),25000,\A3\Supplies_F_Heli\Slingload\Slingload_01_Ammo_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Ammo_F.jpg)
	CONTAINER_EMPTY(Container_Sling_Cargo,Huron Cargo Container (empty),25000,\A3\Supplies_F_Heli\Slingload\Slingload_01_Cargo_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Cargo_F.jpg)
	CONTAINER_EMPTY(Container_Sling_Fuel,Huron Fuel Container (empty),25000,\A3\Supplies_F_Heli\Slingload\Slingload_01_Fuel_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Fuel_F.jpg)
	CONTAINER_EMPTY(Container_Sling_Medevac,Huron Medevac Container (empty),25000,\A3\Supplies_F_Heli\Slingload\Slingload_01_Medevac_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Medevac_F.jpg)
	CONTAINER_EMPTY(Container_Sling_Repair,Huron Repair Container (empty),25000,\A3\Supplies_F_Heli\Slingload\Slingload_01_Repair_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Repair_F.jpg)

//	CONTAINER_EMPTY(CLASSNAME,NAME,LOAD,MODEL,PREVIEW)

	class GVAR(Container_Medium_Supply_Platoon): ReammoBox_F {
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_white_F.jpg";
		model = "\A3\Structures_F\Ind\Cargo\Cargo20_white_F.p3d";
		
		scope = 2;
		scopeCurator = 2;
		displayName = "Supply Container Medium - Platoon";
		editorCategory = QUOTE(EdCat_UNITAF);
		editorSubcategory = QUOTE(EdSubcat_UNITAF_Logistics);
		class EventHandlers {
			init = QUOTE((_this select 0) allowdamage false);
		};
		maximumLoad = 35000;

		class TransportMagazines {
			MACRO_ADDMAGAZINE(rhs_mag_30Rnd_556x45_M855A1_PMAG,120);				// 30rnd M855A1 PMAG
			MACRO_ADDMAGAZINE(rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red,120);		// 30rnd M855A1 PMAG Tracer (Red)
			MACRO_ADDMAGAZINE(rhsusf_mag_17Rnd_9x19_FMJ,60);						// 17rnd 9mm FMJ
			MACRO_ADDMAGAZINE(1Rnd_HE_Grenade_shell,20);							// M203 1rnd HE Grenade
		};
		class TransportWeapons {
			MACRO_ADDWEAPON(rhs_weap_m27iar,30);							// M27
			MACRO_ADDWEAPON(rhsusf_weap_glock17g4,30);						// Glock 17 Gen4
			MACRO_ADDWEAPON(rhs_weap_m249_pip,2);							// M249
			MACRO_ADDWEAPON(rhs_weap_m4a1_m203,5);							// M4A1-M203
		};
		class TransportItems {
			MACRO_ADDITEM(ACE_CableTie,60);									// Cable Tie
			MACRO_ADDITEM(ACE_EarPlugs,30);									// Ear Plugs
			MACRO_ADDITEM(ACE_elasticBandage,450);							// Elastic Bandage
			MACRO_ADDITEM(ACE_morphine,60);									// Morphine
			MACRO_ADDITEM(ACE_tourniquet,120);								// Tourniquet
			MACRO_ADDITEM(ACE_splint,60);									// Splint
			MACRO_ADDITEM(ACE_personalAidKit,30);							// PAK
			MACRO_ADDITEM(SmokeShell,120);									// Smoke Grenade (White)
			MACRO_ADDITEM(SmokeShellOrange,15);								// Smoke Grenade (Orange)
			MACRO_ADDITEM(SmokeShellBlue,15);								// Smoke Grenade (Blue)
			MACRO_ADDITEM(SmokeShellRed,15);								// Smoke Grenade (Red)
			MACRO_ADDITEM(SmokeShellGreen,15);								// Smoke Grenade (Green)
			MACRO_ADDITEM(SmokeShellPurple,15);								// Smoke Grenade (Green)
			MACRO_ADDITEM(HandGrenade,120);									// Hand Grenade
			MACRO_ADDITEM(ACE_EntrenchingTool,30);							// Entrenching Tool
			MACRO_ADDITEM(ACE_DefusalKit,2);								// Defusal Kit
			MACRO_ADDITEM(MineDetector,2);									// Mine Detector
			MACRO_ADDITEM(ToolKit,2);										// Toolkit
			MACRO_ADDITEM(TFAR_anprc152,30);								// Radio (AN/PRC-152)
			MACRO_ADDITEM(ItemcTabHCam,5);									// Helmet Cam
			MACRO_ADDITEM(ItemcTab,3);										// Tablet
			MACRO_ADDITEM(ItemMap,30);										// Map
			MACRO_ADDITEM(ItemGPS,30);										// GPS
			MACRO_ADDITEM(ACE_Vector,5);									// Vector 21
			MACRO_ADDITEM(Binocular,30);									// Binocular
			MACRO_ADDITEM(ACE_Banana,30);									// Banana (because why not)
		};
		class TransportBackpacks {
			MACRO_ADDBACKPACK(rhsusf_assault_eagleaiii_coy,30);
		};
	};

};