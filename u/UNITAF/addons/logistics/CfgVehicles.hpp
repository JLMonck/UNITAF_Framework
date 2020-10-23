// fallback image since Contact DLC still has .ebo files, which can't be unpacked (and is required to pack this file)
#define PROP_IMG \a3\editorpreviews_f\Data\CfgVehicles\Default\Prop.jpg

#define CONTAINER_EMPTY_BASE(CLASSNAME,NAME,LOAD,MODEL,PREVIEW,SELECTIONS,TEXTURES) \
	class GVAR(CLASSNAME): GVAR(Container_Base) { \
		scope = 2; \
		scopeCurator = 2; \
		displayName = QUOTE(NAME); \
		maximumLoad = LOAD; \
		model = QUOTE(MODEL); \
		hiddenselections[] = SELECTIONS; \
		hiddenselectionsTextures[] = TEXTURES; \
		editorPreview = QUOTE(PREVIEW); \
		dlc = QUOTE(PREFIX); \
	};

class CfgVehicles {
	class ReammoBox_F;
	class GVAR(Container_Base): ReammoBox_F {
		author = "$STR_unitaf_main_Author";
		_generalMacro = QUOTE(GVAR(Container_Base));

		// works for editor
		editorCategory = QUOTE(EdCat_UNITAF_Logistics);
		editorSubcategory = QUOTE(EdSubcat_UNITAF_Logistics_Empty);

		scope = 1;
		side = 8;
		editorForceEmpty = 1;

		class TransportMagazines {};
		class TransportWeapons {};
		class TransportItems {};
		class TransportBackpacks {};
	};

	// TINY - 150
	//CONTAINER_EMPTY_BASE(DroneCase_150_White,Drone Case (White),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_I_UAV_06_CO.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\I_UAV_06_CO.paa"})
		CONTAINER_EMPTY_BASE(DroneCase_150_White,Drone Case (White),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\I_UAV_06_CO.paa"})
	//CONTAINER_EMPTY_BASE(DroneCase_150_White_Medical,Drone Case (White) [Medical],150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_I_UAV_06_medical_CO.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\I_UAV_06_medical_CO.paa", "A3\Air_F_Orange\UAV_06\Data\I_UAV_06_medical_CO.paa"})
		CONTAINER_EMPTY_BASE(DroneCase_150_White_Medical,Drone Case (White) [Medical],150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\I_UAV_06_medical_CO.paa", "A3\Air_F_Orange\UAV_06\Data\I_UAV_06_medical_CO.paa"})
	//CONTAINER_EMPTY_BASE(DroneCase_150_LightGreen,Drone Case (Light Green),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_O_UAV_06_CO.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\O_UAV_06_CO.paa"})
		CONTAINER_EMPTY_BASE(DroneCase_150_LightGreen,Drone Case (Light Green),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\O_UAV_06_CO.paa"})
	//CONTAINER_EMPTY_BASE(DroneCase_150_LightGreen_Medical,Drone Case (Light Green) [Medical],150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_O_UAV_06_medical_CO.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\O_UAV_06_medical_CO.paa", "A3\Air_F_Orange\UAV_06\Data\O_UAV_06_medical_CO.paa"})
		CONTAINER_EMPTY_BASE(DroneCase_150_LightGreen_Medical,Drone Case (Light Green) [Medical],150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\O_UAV_06_medical_CO.paa", "A3\Air_F_Orange\UAV_06\Data\O_UAV_06_medical_CO.paa"})
	//CONTAINER_EMPTY_BASE(DroneCase_150_DarkGrey,Drone Case (Dark Grey),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_I_E_UAV_06_F.jpg,{"Camo", "Medical"},{"A3\Air_F_Enoch\UAV_06\Data\I_E_UAV_06_CO.paa"})
	//CONTAINER_EMPTY_BASE(DroneCase_150_DarkGrey_Medical,Drone Case (Dark Grey) [Medical],150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_I_E_UAV_06_medical_F.jpg,{"Camo", "Medical"},{"A3\Air_F_Enoch\UAV_06\Data\I_E_UAV_06_CO.paa", "A3\Air_F_Enoch\UAV_06\Data\I_E_UAV_06_CO.paa"})
	//CONTAINER_EMPTY_BASE(DroneCase_150_Olive,Drone Case (Olive),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_B_UAV_06_F.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\B_UAV_06_CO.paa"})
		CONTAINER_EMPTY_BASE(DroneCase_150_Olive,Drone Case (Olive),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\B_UAV_06_CO.paa"})
	CONTAINER_EMPTY_BASE(DroneCase_150_Olive_Medical,Drone Case (Olive) [Medical],150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\B_UAV_06_medical_F.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\B_UAV_06_medical_CO.paa", "A3\Air_F_Orange\UAV_06\Data\B_UAV_06_medical_CO.paa"})
	CONTAINER_EMPTY_BASE(DroneCase_150_Black,Drone Case (Black),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Box_C_UAV_06_F.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\C_UAV_06_CO.paa"})
	//CONTAINER_EMPTY_BASE(DroneCase_150_Yellow_Medical,Drone Case (Yellow) [Medical],150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_C_UAV_06_medical_F.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\C_UAV_06_medical_CO.paa"})
		CONTAINER_EMPTY_BASE(DroneCase_150_Yellow_Medical,Drone Case (Yellow) [Medical],150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\C_UAV_06_medical_CO.paa"})
	//CONTAINER_EMPTY_BASE(DroneCase_150_Red_Medical,Drone Case (Red) [Medical],150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_C_IDAP_UAV_06_medical_F.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\C_IDAP_UAV_06_medical_CO.paa"})
		CONTAINER_EMPTY_BASE(DroneCase_150_Red_Medical,Drone Case (Red) [Medical],150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\C_IDAP_UAV_06_medical_CO.paa"})
	//CONTAINER_EMPTY_BASE(DroneCase_150_Swifd,Drone Case (Swifd),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_C_UAV_06_Swifd_F.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\UAV_06_swifd_CO.paa"})
		CONTAINER_EMPTY_BASE(DroneCase_150_Swifd,Drone Case (Swifd),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\UAV_06_swifd_CO.paa"})
	//CONTAINER_EMPTY_BASE(DroneCase_150_IDAP,Drone Case (IDAP),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_C_IDAP_UAV_06_F.jpg,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\C_IDAP_UAV_06_CO.paa"})
		CONTAINER_EMPTY_BASE(DroneCase_150_IDAP,Drone Case (IDAP),150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{"Camo", "Medical"},{"A3\Air_F_Orange\UAV_06\Data\C_IDAP_UAV_06_CO.paa"})

	// TINY - 300
	CONTAINER_EMPTY_BASE(MetalCase_300,Metal Case (Small),300,\A3\Structures_F_Heli\Items\Luggage\MetalCase_01_small_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_MetalCase_01_small_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(PlasticCase_300_Sand,Plastic Case Small (Sand),300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_PlasticCase_01_small_F.jpg,{},{})
	//CONTAINER_EMPTY_BASE(PlasticCase_300_Sand_CBRN,Plastic Case Small (Sand) [CBRN],300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_CBRN_F.jpg,{"Camo", "Camo2"},{"a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
		CONTAINER_EMPTY_BASE(PlasticCase_300_Sand_CBRN,Plastic Case Small (Sand) [CBRN],300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
	//CONTAINER_EMPTY_BASE(PlasticCase_300_Black,Plastic Case Small (Black),300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_black_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa"})
		CONTAINER_EMPTY_BASE(PlasticCase_300_Black,Plastic Case Small (Black),300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa"})
	//CONTAINER_EMPTY_BASE(PlasticCase_300_Black_CBRN,Plastic Case Small (Black) [CBRN],300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_black_CBRN_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
		CONTAINER_EMPTY_BASE(PlasticCase_300_Black_CBRN,Plastic Case Small (Black) [CBRN],300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
	//CONTAINER_EMPTY_BASE(PlasticCase_300_Olive,Plastic Case Small (Olive),300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_olive_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa"})
		CONTAINER_EMPTY_BASE(PlasticCase_300_Olive,Plastic Case Small (Olive),300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa"})
	//CONTAINER_EMPTY_BASE(PlasticCase_300_Olive_CBRN,Plastic Case Small (Olive) [CBRN],300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_olive_CBRN_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
		CONTAINER_EMPTY_BASE(PlasticCase_300_Olive_CBRN,Plastic Case Small (Olive) [CBRN],300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
	CONTAINER_EMPTY_BASE(PlasticCase_300_White,Plastic Case Small (White),300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_small_gray_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa"})
	CONTAINER_EMPTY_BASE(PlasticCase_300_White_IPAD,Plastic Case Small (White) [IDAP],300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_small_idap_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_idap_CO.paa"})

	// SMALL - 500
	CONTAINER_EMPTY_BASE(MetalCase_500,Metal Case Medium,500,\A3\Structures_F_Heli\Items\Luggage\MetalCase_01_medium_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_MetalCase_01_medium_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(PlasticCase_500_Sand,Plastic Case Medium (Sand),500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_PlasticCase_01_medium_F.jpg,{},{})
	//CONTAINER_EMPTY_BASE(PlasticCase_500_Sand_CBRN,Plastic Case Medium (Sand) [CBRN],500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_CBRN_F.jpg,{"Camo", "Camo2"},{"a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
		CONTAINER_EMPTY_BASE(PlasticCase_500_Sand_CBRN,Plastic Case Medium (Sand) [CBRN],500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
	//CONTAINER_EMPTY_BASE(PlasticCase_500_Black,Plastic Case Medium (Black),500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_black_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa"})
		CONTAINER_EMPTY_BASE(PlasticCase_500_Black,Plastic Case Medium (Black),500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa"})
	//CONTAINER_EMPTY_BASE(PlasticCase_500_Black_CBRN,Plastic Case Medium (Black) [CBRN],500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_black_CBRN_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
		CONTAINER_EMPTY_BASE(PlasticCase_500_Black_CBRN,Plastic Case Medium (Black) [CBRN],500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
	//CONTAINER_EMPTY_BASE(PlasticCase_500_Olive,Plastic Case Medium (Olive),500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_olive_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa"})
		CONTAINER_EMPTY_BASE(PlasticCase_500_Olive,Plastic Case Medium (Olive),500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa"})
	//CONTAINER_EMPTY_BASE(PlasticCase_500_Olive_CBRN,Plastic Case Medium (Olive) [CBRN],500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_olive_CBRN_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
		CONTAINER_EMPTY_BASE(PlasticCase_500_Olive_CBRN,Plastic Case Medium (Olive) [CBRN],500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
	CONTAINER_EMPTY_BASE(PlasticCase_500_White,Plastic Case Medium (White),500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_medium_gray_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa"})
	CONTAINER_EMPTY_BASE(PlasticCase_500_White_IPAD,Plastic Case Medium (White) [IDAP],500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_medium_idap_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_idap_CO.paa"})

	// SMALL - 1000
	CONTAINER_EMPTY_BASE(MetalCase_1000,Metal Case Large,1000,\A3\Structures_F_Heli\Items\Luggage\MetalCase_01_large_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_MetalCase_01_large_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(PlasticCase_1000_Sand,Plastic Case Large (Sand),1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_PlasticCase_01_large_F.jpg,{},{})
	//CONTAINER_EMPTY_BASE(PlasticCase_1000_Sand_CBRN,Plastic Case Large (Sand) [CBRN],1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_CBRN_F.jpg,{"Camo", "Camo2"},{"a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
		CONTAINER_EMPTY_BASE(PlasticCase_1000_Sand_CBRN,Plastic Case Large (Sand) [CBRN],1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
	//CONTAINER_EMPTY_BASE(PlasticCase_1000_Black,Plastic Case Large (Black),1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_black_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa"})
		CONTAINER_EMPTY_BASE(PlasticCase_1000_Black,Plastic Case Large (Black),1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa"})
	//CONTAINER_EMPTY_BASE(PlasticCase_1000_Black_CBRN,Plastic Case Large (Black) [CBRN],1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_black_CBRN_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
		CONTAINER_EMPTY_BASE(PlasticCase_1000_Black_CBRN,Plastic Case Large (Black) [CBRN],1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
	//CONTAINER_EMPTY_BASE(PlasticCase_1000_Olive,Plastic Case Large (Olive),1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_olive_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa"})
		CONTAINER_EMPTY_BASE(PlasticCase_1000_Olive,Plastic Case Large (Olive),1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa"})
	//CONTAINER_EMPTY_BASE(PlasticCase_1000_Olive_CBRN,Plastic Case Large (Olive) [CBRN],1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_olive_CBRN_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
		CONTAINER_EMPTY_BASE(PlasticCase_1000_Olive_CBRN,Plastic Case Large (Olive) [CBRN],1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,PROP_IMG,{"Camo", "Camo2"},{"a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA"})
	CONTAINER_EMPTY_BASE(PlasticCase_1000_White,Plastic Case Large (White),1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_large_gray_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa"})
	CONTAINER_EMPTY_BASE(PlasticCase_1000_White_IPAD,Plastic Case Large (White) [IDAP],1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_large_idap_F.jpg,{"Camo", "Camo2"},{"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_idap_CO.paa"})

/*
	// Basic Ammo
	CONTAINER_EMPTY_BASE(AmmoBox_800_White,Ammo Box (White),800,\A3\weapons_F\AmmoBoxes\AmmoBox_F,\A3\EditorPreviews_F\Data\CfgVehicles\Box_IND_Ammo_F.jpg,{"Camo_Signs", "Camo"},{"A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_HAF_CO.paa"})
	CONTAINER_EMPTY_BASE(AmmoBox_800_Green,Ammo Box (Green),800,\A3\weapons_F\AmmoBoxes\AmmoBox_F,\A3\EditorPreviews_F\Data\CfgVehicles\Box_EAST_Ammo_F.jpg,{"Camo_Signs", "Camo"},{"A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_OPFOR_CO.paa"})
	CONTAINER_EMPTY_BASE(AmmoBox_800_Olive,Ammo Box (Olive),800,\A3\weapons_F\AmmoBoxes\AmmoBox_F,\A3\EditorPreviews_F\Data\CfgVehicles\AmmoBox_CO.jpg,{"Camo_Signs", "Camo"},{"A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"})
	CONTAINER_EMPTY_BASE(AmmoBox_800_Brown,Ammo Box (Brown),800,\A3\weapons_F\AmmoBoxes\AmmoBox_F,\A3\EditorPreviews_F_Exp\Data\CfgVehicles\Box_T_East_Ammo_F.jpg,{"Camo_Signs", "Camo"},{"A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "\A3\Supplies_F_Exp\Ammoboxes\Data\Box_T_East_Wps_F_co.paa"})
	//CONTAINER_EMPTY_BASE(AmmoBox_800_Black,Ammo Box (Black),800,\A3\weapons_F\AmmoBoxes\AmmoBox_F,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_EAF_Ammo_F.jpg,{"Camo_Signs", "Camo"},{"A3\Supplies_F_Enoch\Ammoboxes\data\AmmoBox_signs_EAF_CA.paa", "A3\Supplies_F_Enoch\Ammoboxes\data\AmmoBox_EAF_CO.paa"})
	
	// Basic Weapons
	CONTAINER_EMPTY_BASE(WeaponBox_800_White,Weapons Box (White),800,\A3\weapons_F\AmmoBoxes\WpnsBox_F,\A3\EditorPreviews_F_Exp\Data\CfgVehicles\Box_IND_Wps_F.jpg,{"Camo_Signs", "Camo"},{"A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_HAF_CO.paa"})
	CONTAINER_EMPTY_BASE(WeaponBox_800_Green,Weapons Box (Green),800,\A3\weapons_F\AmmoBoxes\WpnsBox_F,\A3\EditorPreviews_F_Exp\Data\CfgVehicles\Box_East_Wps_F.jpg,{"Camo_Signs", "Camo"},{"A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_OPFOR_CO.paa"})
	CONTAINER_EMPTY_BASE(WeaponBox_800_Olive,Weapons Box (Olive),800,\A3\weapons_F\AmmoBoxes\WpnsBox_F,\A3\EditorPreviews_F_Exp\Data\CfgVehicles\Box_T_NATO_Wps_F.jpg,{"Camo_Signs", "Camo"},{"A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "\A3\Supplies_F_Exp\Ammoboxes\Data\Box_T_NATO_Wps_F_co.paa"})
	CONTAINER_EMPTY_BASE(WeaponBox_800_Brown,Weapons Box (Brown),800,\A3\weapons_F\AmmoBoxes\WpnsBox_F,\A3\EditorPreviews_F_Exp\Data\CfgVehicles\Box_T_East_Wps_F.jpg,{"Camo_Signs", "Camo"},{"A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "\A3\Supplies_F_Exp\Ammoboxes\Data\Box_T_East_Wps_F_co.paa"})
	//CONTAINER_EMPTY_BASE(AWeaponBox_800_Black,Weapons Box (Black),800,\A3\weapons_F\AmmoBoxes\WpnsBox_F,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_EAF_Ammo_F.jpg,{"Camo_Signs", "Camo"},{"A3\Supplies_F_Enoch\Ammoboxes\data\AmmoBox_signs_EAF_CA.paa", "A3\Supplies_F_Enoch\Ammoboxes\data\AmmoBox_EAF_CO.paa"})
*/
};