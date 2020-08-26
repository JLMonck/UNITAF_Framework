class Truck_F;
class Van_02_base_F: Truck_F {
	class TextureSources;
};
class Van_02_vehicle_base_F: Van_02_base_F {
	class TextureSources: TextureSources {
		class UNITAFBlack {
			displayName = "[UNITAF] Black";
			author = "UNITAF";
			textures[] = {"\u\unitaf\addons\reskin\assets\vehicles\training\van.paa","\a3\soft_f_orange\van_02\data\van_wheel_transport_co.paa","\a3\soft_f_orange\van_02\data\van_glass_transport_CA.paa","\a3\Soft_F_Orange\Van_02\Data\van_body_Black_CO.paa"};
			materials[] = {"\a3\Soft_F_Orange\Van_02\Data\van_body.rvmat","\A3\Soft_F_Orange\Van_02\Data\van_wheel_transport.rvmat","","\a3\Data_f\Lights\Car_Beacon_Orange_emit.rvmat"};
			factions[] = {"Faction_UNITAF"};
		};
		class UNITAFKhaki {
			displayName = "[UNITAF] Khaki";
			author = "UNITAF";
			textures[] = {"\u\unitaf\addons\reskin\assets\vehicles\training\van-khaki4.paa","\a3\soft_f_orange\van_02\data\van_wheel_transport_co.paa","\a3\soft_f_orange\van_02\data\van_glass_transport_CA.paa","\a3\Soft_F_Orange\Van_02\Data\van_body_Black_CO.paa"};
			materials[] = {"\a3\Soft_F_Orange\Van_02\Data\van_body.rvmat","\A3\Soft_F_Orange\Van_02\Data\van_wheel_transport.rvmat","","\a3\Data_f\Lights\Car_Beacon_Orange_emit.rvmat"};
			factions[] = {"Faction_UNITAF"};
		};
	};
};

class GVAR(Training_Van_Black): Van_02_vehicle_base_F {
	side = 1;
	scope = 2;
	scopeCurator = 2;
	faction = "Faction_UNITAF";
	editorSubcategory = "EdSubcat_UNITAF_Training";
	displayName = "[UNITAF] Van Training Transport (Black)";
	author = "UNITAF";
	hiddenSelections[] = {"camo1", "camo2", "camo3", "emergency_lights"};
	hiddenSelectionsTextures[] = {"\u\unitaf\addons\reskin\assets\vehicles\training\van.paa","\a3\soft_f_orange\van_02\data\van_wheel_transport_co.paa","\a3\soft_f_orange\van_02\data\van_glass_transport_CA.paa","\a3\Soft_F_Orange\Van_02\Data\van_body_Black_CO.paa"};
	hiddenSelectionMaterials[] = {"\a3\Soft_F_Orange\Van_02\Data\van_body.rvmat","\A3\Soft_F_Orange\Van_02\Data\van_wheel_transport.rvmat","","\a3\Data_f\Lights\Car_Beacon_Orange_emit.rvmat"};
	textureList[] = { "UNITAFBlack", 1 };
	animationList[] = {
		"beacon_front_hide", 1,
		"beacon_rear_hide", 1,
		"LED_lights_hide", 1,
		"reflective_tape_hide", 1,
		"side_protective_frame_hide", 0,
		"front_protective_frame_hide", 0,
		"ladder_hide", 1,
		"spare_tyre_holder_hide", 1,
		"spare_tyre_hide", 1,
		"roof_rack_hide", 1,
		"sidesteps_hide", 1,
		"rearsteps_hide", 1
	};
};
class GVAR(Training_Van_Khaki): Van_02_vehicle_base_F {
	side = 1;
	scope = 2;
	scopeCurator = 2;
	faction = "Faction_UNITAF";
	editorSubcategory = "EdSubcat_UNITAF_Training";
	displayName = "[UNITAF] Van Training Transport (Khaki)";
	author = "UNITAF";
	hiddenSelections[] = {"camo1", "camo2", "camo3", "emergency_lights"};
	hiddenSelectionsTextures[] = {"\u\unitaf\addons\reskin\assets\vehicles\training\van-khaki4.paa","\a3\soft_f_orange\van_02\data\van_wheel_transport_co.paa","\a3\soft_f_orange\van_02\data\van_glass_transport_CA.paa","\a3\Soft_F_Orange\Van_02\Data\van_body_Black_CO.paa"};
	hiddenSelectionMaterials[] = {"\a3\Soft_F_Orange\Van_02\Data\van_body.rvmat","\A3\Soft_F_Orange\Van_02\Data\van_wheel_transport.rvmat","","\a3\Data_f\Lights\Car_Beacon_Orange_emit.rvmat"};
	textureList[] = { "UNITAFKhaki", 1 };
	animationList[] = {
		"beacon_front_hide", 1,
		"beacon_rear_hide", 1,
		"LED_lights_hide", 1,
		"reflective_tape_hide", 1,
		"side_protective_frame_hide", 0,
		"front_protective_frame_hide", 0,
		"ladder_hide", 1,
		"spare_tyre_holder_hide", 1,
		"spare_tyre_hide", 1,
		"roof_rack_hide", 1,
		"sidesteps_hide", 1,
		"rearsteps_hide", 1
	};
};

class Offroad_01_military_comms_base_F;
//class B_GEN_Offroad_01_comms_F: Offroad_01_military_comms_base_F {};

class GVAR(Training_Offroad_Black): Offroad_01_military_comms_base_F {
	side = 1;
	scope = 2;
	scopeCurator = 2;
	faction = "Faction_UNITAF";
	editorSubcategory = "EdSubcat_UNITAF_Training";
	displayName = "[UNITAF] Offroad Instructor (black)";
	author = "UNITAF";
	hiddenSelections[] = {"Camo", "Camo2", "Camo3"};
	hiddenSelectionsTextures[] = {"\u\unitaf\addons\reskin\assets\vehicles\training\offroad.paa","\u\unitaf\addons\reskin\assets\vehicles\training\offroad.paa"};
	animationList[] = {
		"hidePolice", 1,
		"HideServices", 1,
		"HideConstruction", 1,
		"HideCover", 1,
		"HideRoofRack", 1,
		"HideLoudSpeakers", 1,
		"HideAntennas", 1,
		"HideBeacon", 1,
		"HideSpotlight", 1,
		"HideCoverTailGate", 1,
		"HideDoor3", 1,
		"HideBumper1", 1,
		"HideBumper2", 0
	};
};
class GVAR(Training_Offroad_Khaki): Offroad_01_military_comms_base_F {
	side = 1;
	scope = 2;
	scopeCurator = 2;
	faction = "Faction_UNITAF";
	editorSubcategory = "EdSubcat_UNITAF_Training";
	displayName = "[UNITAF] Offroad Instructor (Khaki)";
	author = "UNITAF";
	hiddenSelections[] = {"Camo", "Camo2", "Camo3"};
	hiddenSelectionsTextures[] = {"\u\unitaf\addons\reskin\assets\vehicles\training\offroad-khaki4.paa","\u\unitaf\addons\reskin\assets\vehicles\training\offroad-khaki4.paa"};
	animationList[] = {
		"hidePolice", 1,
		"HideServices", 1,
		"HideConstruction", 1,
		"HideCover", 1,
		"HideRoofRack", 1,
		"HideLoudSpeakers", 1,
		"HideAntennas", 1,
		"HideBeacon", 1,
		"HideSpotlight", 1,
		"HideCoverTailGate", 1,
		"HideDoor3", 1,
		"HideBumper1", 1,
		"HideBumper2", 0
	};
};

class GVAR(Training_Offroad_KhakiCI): Offroad_01_military_comms_base_F {
	side = 1;
	scope = 2;
	scopeCurator = 2;
	faction = "Faction_UNITAF";
	editorSubcategory = "EdSubcat_UNITAF_Training";
	displayName = "[UNITAF] Offroad Chief Instructor (Khaki)";
	author = "UNITAF";
	hiddenSelections[] = {"Camo", "Camo2", "Camo3"};
	hiddenSelectionsTextures[] = {"\u\unitaf\addons\reskin\assets\vehicles\training\offroad-khaki4CI.paa","\u\unitaf\addons\reskin\assets\vehicles\training\offroad-khaki4CI.paa"};
	animationList[] = {
		"hidePolice", 1,
		"HideServices", 1,
		"HideConstruction", 1,
		"HideCover", 1,
		"HideRoofRack", 1,
		"HideLoudSpeakers", 1,
		"HideAntennas", 1,
		"HideBeacon", 0,
		"HideSpotlight", 1,
		"HideCoverTailGate", 1,
		"HideDoor3", 1,
		"HideBumper1", 1,
		"HideBumper2", 0
	};
};
