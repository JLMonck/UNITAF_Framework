class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class extend_antenna {
				displayName = "Open UNITAF Manager";
				condition = QUOTE(call FUNC(canOpenGUI));
				exceptions[] =  {"isNotDragging", "isNotSwimming", "notOnMap", "isNotOnLadder"};
				statement = QUOTE(_this call FUNC(openGUI));
				icon = "\u\UNITAF\addons\menu\ui\unitaf_icon.paa";
				showDisabled = 0;
			};
		};
	};
};