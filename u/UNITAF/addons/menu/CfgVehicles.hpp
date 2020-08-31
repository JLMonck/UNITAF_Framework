class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class GVAR(open_gui) {
				displayName = "Open UNITAF Menu";
				condition = "true";
				exceptions[] =  {"isNotDragging", "isNotSwimming", "notOnMap", "isNotOnLadder"};
				statement = QUOTE(_this call FUNC(openGUI));
				icon = "\u\UNITAF\addons\menu\ui\unitaf_icon.paa";
				showDisabled = 0;
			};
		};
	};
};