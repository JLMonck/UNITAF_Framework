class GVAR(GUI_Control_Main): GVAR(GUI_Control_Base) {
	idc 				= IDC_CONTROL_MAIN;

	class Controls {
		// ORBAT Items
		class GVAR(GUI_Title_Callsign): GVAR(GUI_Title_Base) {
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			text 				= "Callsign";
		};
		class GVAR(GUI_Text_Callsign): GVAR(GUI_Text_Base) {
			idc 				= IDC_Callsign;
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
		};

		class GVAR(GUI_Title_Report): GVAR(GUI_Title_Base) {
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 3);
			text 				= "Report To";
		};
		class GVAR(GUI_Text_Report): GVAR(GUI_Text_Base) {
			idc 				= IDC_Report;
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 4);
		};

		class GVAR(GUI_Title_Role): GVAR(GUI_Title_Base) {
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 5);
			text 				= "Role";
		};
		class GVAR(GUI_Text_Role): GVAR(GUI_Text_Base) {
			idc 				= IDC_Role;
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 6);
		};

		class GVAR(GUI_Title_Color): GVAR(GUI_Title_Base) {
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 7);
			text 				= "Buddy Color";
		};
		class GVAR(GUI_Text_Color): GVAR(GUI_Text_Base) {
			idc 				= IDC_Color;
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 8);
		};

		class GVAR(GUI_Title_Team): GVAR(GUI_Title_Base) {
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 9);
			text 				= "Current Team";
		};
		class GVAR(GUI_List_Team): GVAR(GUI_List_Base) {
			idc 				= IDC_Team;
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 10);
		};

		// Bottom Buttons
		class GVAR(GUI_Button_LoadORBAT): GVAR(GUI_Button_Base) {
			idc 						= IDC_BUTTON_LoadORBAT;
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			text 						= "Load ORBAT";
			colorBackground[] 			= COLOR_BUTTON_LOAD;
			colorBackgroundActive[] 	= COLOR_BUTTON_LOAD;
			colorFocused[] 				= COLOR_BUTTON_LOAD;
			action 						= QUOTE([player] call EFUNC(client,getORBAT));
			toolTip 					= "Get your personal information from the ORBAT; like loadout, callsign and radio frequencies";
		};
		class GVAR(GUI_Button_Admin): GVAR(GUI_Button_Base) {
			idc 						= IDC_BUTTON_Admin;
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 13);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			text 						= "Admin";
			colorBackground[] 			= COLOR_BUTTON_ADMIN;
			colorBackgroundActive[] 	= COLOR_BUTTON_ADMIN;
			colorFocused[] 				= COLOR_BUTTON_ADMIN;
			action 						= QUOTE(call FUNC(openADMIN));
			toolTip 					= "Functions only accessable for Admins";
		};

		// MISSION BUTTONS
		class GVAR(GUI_Button_ORBAT): GVAR(GUI_Button_Base) {
			idc 						= IDC_BUTTON_ORBAT;
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 7);
			text 						= "Read ORBAT";
			action 						= QUOTE(call FUNC(openORBAT));
			toolTip 					= "Quickly check the ORBAT";
		};
		class GVAR(GUI_Button_OPORD): GVAR(GUI_Button_Base) {
			idc 						= IDC_BUTTON_OPORD;
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 10);
			text 						= "Read OPORD";
			action 						= QUOTE(call FUNC(openOPORD));
			toolTip 					= "Quickly check the OPORD";
		};

		// OOPS BUTTONS
		class GVAR(GUI_Button_GetRadio): GVAR(GUI_Button_Base) {
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 7);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 7);
			text 						= "Get SW Radio";
			action 						= QUOTE([player] call EFUNC(client,getRadio));
			toolTip 					= "Forgot your radio? Grab one here";
		};
		class GVAR(GUI_Button_GetNVG): GVAR(GUI_Button_Base) {
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 7);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 10);
			text 						= "Get NVG's";
			action 						= QUOTE([player] call EFUNC(client,getNVG));
			toolTip 					= "Forgot some NVG's? Grab one here";
		};
		class GVAR(GUI_Button_GetEarplugs): GVAR(GUI_Button_Base) {
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 7);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 13);
			text 						= "Get Earplugs";
			action 						= QUOTE([player] call EFUNC(client,getEarplugs));
			toolTip 					= "Forgot some earplugs? Grab one here";
		};
	};
};