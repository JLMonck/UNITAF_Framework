class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class GVAR(open_gui) {
				displayName = "Open UNITAF Tablet";
				condition = "true";
				exceptions[] =  {"isNotDragging", "isNotSwimming", "notOnMap", "isNotOnLadder"};
				statement = QUOTE(_this call FUNC(openTablet));
				icon = "\u\UNITAF\addons\tablet\ui\unitaf_icon.paa";
				showDisabled = 0;
			};
		};
	};
};