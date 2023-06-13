// fallback image since Contact DLC still has .ebo files, which can't be unpacked (and is required to pack this file)
#define PROP_IMG \a3\editorpreviews_f\Data\CfgVehicles\Default\Prop.jpg

#define CONTAINER_EMPTY_BASE(CLASSNAME,NAME,MASS,CARGO,LOAD,MODEL,PREVIEW,SELECTIONS,TEXTURES) \
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
		ace_cargo_size = CARGO; \
		mass = MASS; \
		slingLoadMaxCargoMass = LOAD; \
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

		ace_cargo_canLoad = 1;
		ace_Cargo_hasCargo = 1;

		ace_dragging_canDrag = 1;
		ace_dragging_dragPosition[] = {0, 1.5, 0};
		ace_dragging_dragDirection = 0;

		ace_dragging_canCarry = 1;
		ace_dragging_carryPosition[] = {0, 1.5, 0};
		ace_dragging_carryDirection = 0;

		class VehicleTransport {
			class Cargo {
				parachuteClass			= "B_Parachute_02_F";
				parachuteHeightLimit	= 40;
				canBeTransported		= 1;
				dimensions[]			= {"BBox_1_1_pos", "BBox_1_2_pos"};
			};
		};
		slingLoadCargoMemoryPoints[] = { "SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};

		class TransportMagazines {};
		class TransportWeapons {};
		class TransportItems {};
		class TransportBackpacks {};
	};

	// TINY - 150
	//CONTAINER_EMPTY_BASE(DroneCase_150_White,Drone Case (White),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_I_UAV_06_CO.jpg,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\I_UAV_06_CO.paa")})
		CONTAINER_EMPTY_BASE(DroneCase_150_White,Drone Case (White),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\I_UAV_06_CO.paa")})
	//CONTAINER_EMPTY_BASE(DroneCase_150_White_Medical,Drone Case (White) [Medical],5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_I_UAV_06_medical_CO.jpg,{ARR_2("Camo", "Medical")},{ARR_2("A3\Air_F_Orange\UAV_06\Data\I_UAV_06_medical_CO.paa", "A3\Air_F_Orange\UAV_06\Data\I_UAV_06_medical_CO.paa")})
		CONTAINER_EMPTY_BASE(DroneCase_150_White_Medical,Drone Case (White) [Medical],5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{ARR_2("Camo", "Medical")},{ARR_2("A3\Air_F_Orange\UAV_06\Data\I_UAV_06_medical_CO.paa", "A3\Air_F_Orange\UAV_06\Data\I_UAV_06_medical_CO.paa")})
	//CONTAINER_EMPTY_BASE(DroneCase_150_LightGreen,Drone Case (Light Green),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_O_UAV_06_CO.jpg,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\O_UAV_06_CO.paa")})
		CONTAINER_EMPTY_BASE(DroneCase_150_LightGreen,Drone Case (Light Green),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\O_UAV_06_CO.paa")})
	//CONTAINER_EMPTY_BASE(DroneCase_150_LightGreen_Medical,Drone Case (Light Green) [Medical],5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_O_UAV_06_medical_CO.jpg,{ARR_2("Camo", "Medical")},{ARR_2("A3\Air_F_Orange\UAV_06\Data\O_UAV_06_medical_CO.paa", "A3\Air_F_Orange\UAV_06\Data\O_UAV_06_medical_CO.paa")})
		CONTAINER_EMPTY_BASE(DroneCase_150_LightGreen_Medical,Drone Case (Light Green) [Medical],5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{ARR_2("Camo", "Medical")},{ARR_2("A3\Air_F_Orange\UAV_06\Data\O_UAV_06_medical_CO.paa", "A3\Air_F_Orange\UAV_06\Data\O_UAV_06_medical_CO.paa")})
	//CONTAINER_EMPTY_BASE(DroneCase_150_DarkGrey,Drone Case (Dark Grey),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_I_E_UAV_06_F.jpg,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Enoch\UAV_06\Data\I_E_UAV_06_CO.paa")})
	//CONTAINER_EMPTY_BASE(DroneCase_150_DarkGrey_Medical,Drone Case (Dark Grey) [Medical],5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_I_E_UAV_06_medical_F.jpg,{ARR_2("Camo", "Medical")},{ARR_2("A3\Air_F_Enoch\UAV_06\Data\I_E_UAV_06_CO.paa", "A3\Air_F_Enoch\UAV_06\Data\I_E_UAV_06_CO.paa")})
	//CONTAINER_EMPTY_BASE(DroneCase_150_Olive,Drone Case (Olive),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_B_UAV_06_F.jpg,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\B_UAV_06_CO.paa")})
		CONTAINER_EMPTY_BASE(DroneCase_150_Olive,Drone Case (Olive),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\B_UAV_06_CO.paa")})
	CONTAINER_EMPTY_BASE(DroneCase_150_Olive_Medical,Drone Case (Olive) [Medical],5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\B_UAV_06_medical_F.jpg,{ARR_2("Camo", "Medical")},{ARR_2("A3\Air_F_Orange\UAV_06\Data\B_UAV_06_medical_CO.paa", "A3\Air_F_Orange\UAV_06\Data\B_UAV_06_medical_CO.paa")})
	CONTAINER_EMPTY_BASE(DroneCase_150_Black,Drone Case (Black),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Box_C_UAV_06_F.jpg,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\C_UAV_06_CO.paa")})
	//CONTAINER_EMPTY_BASE(DroneCase_150_Yellow_Medical,Drone Case (Yellow) [Medical],5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_C_UAV_06_medical_F.jpg,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\C_UAV_06_medical_CO.paa")})
		CONTAINER_EMPTY_BASE(DroneCase_150_Yellow_Medical,Drone Case (Yellow) [Medical],5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\C_UAV_06_medical_CO.paa")})
	//CONTAINER_EMPTY_BASE(DroneCase_150_Red_Medical,Drone Case (Red) [Medical],5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_C_IDAP_UAV_06_medical_F.jpg,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\C_IDAP_UAV_06_medical_CO.paa")})
		CONTAINER_EMPTY_BASE(DroneCase_150_Red_Medical,Drone Case (Red) [Medical],5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\C_IDAP_UAV_06_medical_CO.paa")})
	//CONTAINER_EMPTY_BASE(DroneCase_150_Swifd,Drone Case (Swifd),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_C_UAV_06_Swifd_F.jpg,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\UAV_06_swifd_CO.paa")})
		CONTAINER_EMPTY_BASE(DroneCase_150_Swifd,Drone Case (Swifd),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\UAV_06_swifd_CO.paa")})
	//CONTAINER_EMPTY_BASE(DroneCase_150_IDAP,Drone Case (IDAP),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_C_IDAP_UAV_06_F.jpg,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\C_IDAP_UAV_06_CO.paa")})
		CONTAINER_EMPTY_BASE(DroneCase_150_IDAP,Drone Case (IDAP),5,0,150,\A3\Air_F_Orange\UAV_06\Box_UAV_06_F.p3d,PROP_IMG,{ARR_2("Camo", "Medical")},{ARR_1("A3\Air_F_Orange\UAV_06\Data\C_IDAP_UAV_06_CO.paa")})

	// TINY - 300
	CONTAINER_EMPTY_BASE(MetalCase_300,Metal Case (Small),10,0,300,\A3\Structures_F_Heli\Items\Luggage\MetalCase_01_small_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_MetalCase_01_small_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(PlasticCase_300_Sand,Plastic Case Small (Sand),10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_PlasticCase_01_small_F.jpg,{},{})
	//CONTAINER_EMPTY_BASE(PlasticCase_300_Sand_CBRN,Plastic Case Small (Sand) [CBRN],10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_CBRN_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
		CONTAINER_EMPTY_BASE(PlasticCase_300_Sand_CBRN,Plastic Case Small (Sand) [CBRN],10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
	//CONTAINER_EMPTY_BASE(PlasticCase_300_Black,Plastic Case Small (Black),10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_black_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa")})
		CONTAINER_EMPTY_BASE(PlasticCase_300_Black,Plastic Case Small (Black),10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa")})
	//CONTAINER_EMPTY_BASE(PlasticCase_300_Black_CBRN,Plastic Case Small (Black) [CBRN],10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_black_CBRN_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
		CONTAINER_EMPTY_BASE(PlasticCase_300_Black_CBRN,Plastic Case Small (Black) [CBRN],10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
	//CONTAINER_EMPTY_BASE(PlasticCase_300_Olive,Plastic Case Small (Olive),10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_olive_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa")})
		CONTAINER_EMPTY_BASE(PlasticCase_300_Olive,Plastic Case Small (Olive),10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa")})
	//CONTAINER_EMPTY_BASE(PlasticCase_300_Olive_CBRN,Plastic Case Small (Olive) [CBRN],10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_small_olive_CBRN_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
		CONTAINER_EMPTY_BASE(PlasticCase_300_Olive_CBRN,Plastic Case Small (Olive) [CBRN],10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
	CONTAINER_EMPTY_BASE(PlasticCase_300_White,Plastic Case Small (White),10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_small_gray_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa")})
	CONTAINER_EMPTY_BASE(PlasticCase_300_White_IPAD,Plastic Case Small (White) [IDAP],10,0,300,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_small_idap_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_idap_CO.paa")})

	// SMALL - 500
	CONTAINER_EMPTY_BASE(MetalCase_500,Metal Case Medium,15,0,500,\A3\Structures_F_Heli\Items\Luggage\MetalCase_01_medium_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_MetalCase_01_medium_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(PlasticCase_500_Sand,Plastic Case Medium (Sand),15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_PlasticCase_01_medium_F.jpg,{},{})
	//CONTAINER_EMPTY_BASE(PlasticCase_500_Sand_CBRN,Plastic Case Medium (Sand) [CBRN],15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_CBRN_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
		CONTAINER_EMPTY_BASE(PlasticCase_500_Sand_CBRN,Plastic Case Medium (Sand) [CBRN],15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
	//CONTAINER_EMPTY_BASE(PlasticCase_500_Black,Plastic Case Medium (Black),15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_black_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa")})
		CONTAINER_EMPTY_BASE(PlasticCase_500_Black,Plastic Case Medium (Black),15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa")})
	//CONTAINER_EMPTY_BASE(PlasticCase_500_Black_CBRN,Plastic Case Medium (Black) [CBRN],15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_black_CBRN_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
		CONTAINER_EMPTY_BASE(PlasticCase_500_Black_CBRN,Plastic Case Medium (Black) [CBRN],15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
	//CONTAINER_EMPTY_BASE(PlasticCase_500_Olive,Plastic Case Medium (Olive),15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_olive_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa")})
		CONTAINER_EMPTY_BASE(PlasticCase_500_Olive,Plastic Case Medium (Olive),15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa")})
	//CONTAINER_EMPTY_BASE(PlasticCase_500_Olive_CBRN,Plastic Case Medium (Olive) [CBRN],15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_medium_olive_CBRN_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
		CONTAINER_EMPTY_BASE(PlasticCase_500_Olive_CBRN,Plastic Case Medium (Olive) [CBRN],15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
	CONTAINER_EMPTY_BASE(PlasticCase_500_White,Plastic Case Medium (White),15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_medium_gray_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa")})
	CONTAINER_EMPTY_BASE(PlasticCase_500_White_IPAD,Plastic Case Medium (White) [IDAP],15,0,500,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_medium_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_medium_idap_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_idap_CO.paa")})

	// SMALL - 1000
	CONTAINER_EMPTY_BASE(MetalCase_1000,Metal Case Large,25,0,1000,\A3\Structures_F_Heli\Items\Luggage\MetalCase_01_large_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_MetalCase_01_large_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(PlasticCase_1000_Sand,Plastic Case Large (Sand),25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_PlasticCase_01_large_F.jpg,{},{})
	//CONTAINER_EMPTY_BASE(PlasticCase_1000_Sand_CBRN,Plastic Case Large (Sand) [CBRN],25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_CBRN_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
		CONTAINER_EMPTY_BASE(PlasticCase_1000_Sand_CBRN,Plastic Case Large (Sand) [CBRN],25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Structures_F_Heli\Items\Luggage\Data\PlasticCase_01_CO", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
	//CONTAINER_EMPTY_BASE(PlasticCase_1000_Black,Plastic Case Large (Black),25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_black_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa")})
		CONTAINER_EMPTY_BASE(PlasticCase_1000_Black,Plastic Case Large (Black),25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa")})
	//CONTAINER_EMPTY_BASE(PlasticCase_1000_Black_CBRN,Plastic Case Large (Black) [CBRN],25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_black_CBRN_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
		CONTAINER_EMPTY_BASE(PlasticCase_1000_Black_CBRN,Plastic Case Large (Black) [CBRN],25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_black_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
	//CONTAINER_EMPTY_BASE(PlasticCase_1000_Olive,Plastic Case Large (Olive),25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_olive_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa")})
		CONTAINER_EMPTY_BASE(PlasticCase_1000_Olive,Plastic Case Large (Olive),25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa")})
	//CONTAINER_EMPTY_BASE(PlasticCase_1000_Olive_CBRN,Plastic Case Large (Olive) [CBRN],25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Land_PlasticCase_01_large_olive_CBRN_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
		CONTAINER_EMPTY_BASE(PlasticCase_1000_Olive_CBRN,Plastic Case Large (Olive) [CBRN],25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,PROP_IMG,{ARR_2("Camo", "Camo2")},{ARR_2("a3\Props_F_Enoch\Military\Supplies\Data\PlasticCase_01_olive_CO.paa", "a3\Props_F_Enoch\Military\Supplies\data\PlasticCase_01_Logo_01_CA")})
	CONTAINER_EMPTY_BASE(PlasticCase_1000_White,Plastic Case Large (White),25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_large_gray_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa")})
	CONTAINER_EMPTY_BASE(PlasticCase_1000_White_IPAD,Plastic Case Large (White) [IDAP],25,0,1000,\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_large_F.p3d,\A3\EditorPreviews_F_Orange\Data\CfgVehicles\Land_PlasticCase_01_large_idap_F.jpg,{ARR_2("Camo", "Camo2")},{ARR_1("a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_idap_CO.paa")})

	// Basic Ammo - 1000
	CONTAINER_EMPTY_BASE(AmmoBox_1000_White,Ammo Box (White),25,0,1000,\A3\weapons_F\AmmoBoxes\AmmoBox_F,\A3\EditorPreviews_F\Data\CfgVehicles\Box_IND_Ammo_F.jpg,{ARR_2("Camo_Signs", "Camo")},{ARR_2("A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_HAF_CO.paa")})
	CONTAINER_EMPTY_BASE(AmmoBox_1000_Green,Ammo Box (Green),25,0,1000,\A3\weapons_F\AmmoBoxes\AmmoBox_F,\A3\EditorPreviews_F\Data\CfgVehicles\Box_EAST_Ammo_F.jpg,{ARR_2("Camo_Signs", "Camo")},{ARR_2("A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_OPFOR_CO.paa")})
	CONTAINER_EMPTY_BASE(AmmoBox_1000_Olive,Ammo Box (Olive),25,0,1000,\A3\weapons_F\AmmoBoxes\AmmoBox_F,\A3\EditorPreviews_F\Data\CfgVehicles\Box_NATO_Ammo_F.jpg,{ARR_2("Camo_Signs", "Camo")},{ARR_2("A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa")})
	CONTAINER_EMPTY_BASE(AmmoBox_1000_Brown,Ammo Box (Brown),25,0,1000,\A3\weapons_F\AmmoBoxes\AmmoBox_F,\A3\EditorPreviews_F_Exp\Data\CfgVehicles\Box_T_East_Ammo_F.jpg,{ARR_2("Camo_Signs", "Camo")},{ARR_2("A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "\A3\Supplies_F_Exp\Ammoboxes\Data\Box_T_East_Wps_F_co.paa")})
	//CONTAINER_EMPTY_BASE(AmmoBox_1000_Black,Ammo Box (Black),25,0,1000,\A3\weapons_F\AmmoBoxes\AmmoBox_F,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_EAF_Ammo_F.jpg,{ARR_2("Camo_Signs", "Camo")},{ARR_2("A3\Supplies_F_Enoch\Ammoboxes\data\AmmoBox_signs_EAF_CA.paa", "A3\Supplies_F_Enoch\Ammoboxes\data\AmmoBox_EAF_CO.paa")})
	
	// Basic Weapons - 1500
	CONTAINER_EMPTY_BASE(WeaponBox_1500_White,Weapons Box (White),30,0,1500,\A3\weapons_F\AmmoBoxes\WpnsBox_F,\A3\EditorPreviews_F\Data\CfgVehicles\Box_IND_Wps_F.jpg,{ARR_2("Camo_Signs", "Camo")},{ARR_2("A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_HAF_CO.paa")})
	CONTAINER_EMPTY_BASE(WeaponBox_1500_Green,Weapons Box (Green),30,0,1500,\A3\weapons_F\AmmoBoxes\WpnsBox_F,\A3\EditorPreviews_F\Data\CfgVehicles\Box_East_Wps_F.jpg,{ARR_2("Camo_Signs", "Camo")},{ARR_2("A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_OPFOR_CO.paa")})
	CONTAINER_EMPTY_BASE(WeaponBox_1500_Olive,Weapons Box (Olive),30,0,1500,\A3\weapons_F\AmmoBoxes\WpnsBox_F,\A3\EditorPreviews_F\Data\CfgVehicles\Box_NATO_Wps_F.jpg,{ARR_2("Camo_Signs", "Camo")},{ARR_2("A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "\A3\Supplies_F_Exp\Ammoboxes\Data\Box_T_NATO_Wps_F_co.paa")})
	CONTAINER_EMPTY_BASE(WeaponBox_1500_Brown,Weapons Box (Brown),30,0,1500,\A3\weapons_F\AmmoBoxes\WpnsBox_F,\A3\EditorPreviews_F_Exp\Data\CfgVehicles\Box_T_East_Wps_F.jpg,{ARR_2("Camo_Signs", "Camo")},{ARR_2("A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "\A3\Supplies_F_Exp\Ammoboxes\Data\Box_T_East_Wps_F_co.paa")})
	//CONTAINER_EMPTY_BASE(AWeaponBox_1500_Black,Weapons Box (Black),30,0,1500,\A3\weapons_F\AmmoBoxes\WpnsBox_F,\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\Box_EAF_Ammo_F.jpg,{ARR_2("Camo_Signs", "Camo")},{ARR_2("A3\Supplies_F_Enoch\Ammoboxes\data\AmmoBox_signs_EAF_CA.paa", "A3\Supplies_F_Enoch\Ammoboxes\data\AmmoBox_EAF_CO.paa")})


	// Small Container 10000
	CONTAINER_EMPTY_BASE(Container_Small_Blue,Supply Container Small (Blue),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_blue_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_blue_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_BrickRed,Supply Container Small (Brick Red),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_brick_red_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_brick_red_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_Cyan,Supply Container Small (Cyan),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_cyan_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_cyan_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_Grey,Supply Container Small (Grey),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_grey_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_grey_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_LightBlue,Supply Container Small (Light Blue),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_light_blue_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_light_blue_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_LightGreen,Supply Container Small (Light Green),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_light_green_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_light_green_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_MilitaryGreen,Supply Container Small (Military Green),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_military_green_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_military_green_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_Orange,Supply Container Small (Orange),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_orange_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_orange_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_Red,Supply Container Small (Red),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_red_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_red_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_Sand,Supply Container Small (Sand),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_sand_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_sand_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_White,Supply Container Small (White),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_white_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_white_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Small_Yellow,Supply Container Small (Yellow),2500,30,10000,\A3\Structures_F_Heli\Ind\Cargo\Cargo10_yellow_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo10_yellow_F.jpg,{},{})
	
	// Medium Container 20000
	CONTAINER_EMPTY_BASE(Container_Medium_Grey,Supply Container Medium (Grey),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_grey_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_grey_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_Blue,Supply Container Medium (Blue),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_blue_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_blue_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_BrickRed,Supply Container Medium (Brick Red),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_brick_red_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_brick_red_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_Cyan,Supply Container Medium (Cyan),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_cyan_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_cyan_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_LightBlue,Supply Container Medium (Light Blue),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_light_blue_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_light_blue_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_LightGreen,Supply Container Medium (Light Green),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_light_green_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_light_green_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_MilitaryGreen,Supply Container Medium (Military Green),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_military_green_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_military_green_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_Orange,Supply Container Medium (Orange),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_orange_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_orange_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_Red,Supply Container Medium (Red),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_red_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_red_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_Sand,Supply Container Medium (Sand),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_sand_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_sand_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_White,Supply Container Medium (White),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_white_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_white_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Medium_Yellow,Supply Container Medium (Yellow),5000,60,20000,\A3\Structures_F\Ind\Cargo\Cargo20_yellow_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo20_yellow_F.jpg,{},{})

	// Large Container 40000
	CONTAINER_EMPTY_BASE(Container_Large_Blue,Supply Container Large (Blue),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_blue_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_blue_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_BrickRed,Supply Container Large (Brick Red),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_brick_red_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_brick_red_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_Cyan,Supply Container Large (Cyan),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_cyan_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_cyan_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_Grey,Supply Container Large (Grey),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_grey_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_grey_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_LightBlue,Supply Container Large Light (Blue),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_light_blue_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_light_blue_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_LightGreen,Supply Container Large (Light Green),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_light_green_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_light_green_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_MilitaryGreen,Supply Container Large (Military Green),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_military_green_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_military_green_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_Orange,Supply Container Large (Orange),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_orange_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_orange_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_Red,Supply Container Large (Red),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_red_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_red_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_Sand,Supply Container Large (Sand),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_sand_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_sand_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_White,Supply Container Large (White),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_white_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_white_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Large_Yellow,Supply Container Large (Yellow),10000,120,40000,\A3\Structures_F\Ind\Cargo\Cargo40_yellow_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\Land_Cargo40_yellow_F.jpg,{},{})

	// HURON
	CONTAINER_EMPTY_BASE(Container_Sling_Ammo,Huron Ammo Container,2500,10,25000,\A3\Supplies_F_Heli\Slingload\Slingload_01_Ammo_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Ammo_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Sling_Cargo,Huron Cargo Container,2500,30,25000,\A3\Supplies_F_Heli\Slingload\Slingload_01_Cargo_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Cargo_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Sling_Fuel,Huron Fuel Container,2500,10,25000,\A3\Supplies_F_Heli\Slingload\Slingload_01_Fuel_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Fuel_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Sling_Medevac,Huron Medevac Container,2500,10,25000,\A3\Supplies_F_Heli\Slingload\Slingload_01_Medevac_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Medevac_F.jpg,{},{})
	CONTAINER_EMPTY_BASE(Container_Sling_Repair,Huron Repair Container,2500,20,25000,\A3\Supplies_F_Heli\Slingload\Slingload_01_Repair_F.p3d,\A3\EditorPreviews_F\Data\CfgVehicles\B_Slingload_01_Repair_F.jpg,{},{})
};