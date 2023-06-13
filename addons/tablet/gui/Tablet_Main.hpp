class GVAR(GUI_Control_Main): GVAR(GUI_Control_Base) {
	idc 				= IDC_Tablet_Main;
	GRID_FRAME

	class Controls {
		// ORBAT Items
		class GVAR(GUI_Title_Callsign): GVAR(GUI_Title_Base) {
			x 					= QUOTE(GRID_OFFSET_COL3);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(1));
			text 				= "Callsign";
		};
		class GVAR(GUI_Text_Callsign): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Main_Callsign;
			x 					= QUOTE(GRID_OFFSET_COL3);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(2));
			colorBackground[] 	= {0,0,0,0.5};
		};

		class GVAR(GUI_Title_Report): GVAR(GUI_Title_Base) {
			x 					= QUOTE(GRID_OFFSET_COL3);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(3));
			text 				= "Report To";
		};
		class GVAR(GUI_Text_Report): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Main_Report;
			x 					= QUOTE(GRID_OFFSET_COL3);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(4));
			colorBackground[] 	= {0,0,0,0.5};
		};

		class GVAR(GUI_Title_Role): GVAR(GUI_Title_Base) {
			x 					= QUOTE(GRID_OFFSET_COL3);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(5));
			text 				= "Role";
		};
		class GVAR(GUI_Text_Role): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Main_Role;
			x 					= QUOTE(GRID_OFFSET_COL3);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(6));
			colorBackground[] 	= {0,0,0,0.5};
		};

		class GVAR(GUI_Title_Color): GVAR(GUI_Title_Base) {
			x 					= QUOTE(GRID_OFFSET_COL3);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(7));
			text 				= "Buddy Color";
		};
		class GVAR(GUI_Text_Color): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Main_Color;
			x 					= QUOTE(GRID_OFFSET_COL3);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(8));
			colorBackground[] 	= {0,0,0,0.5};
		};

		class GVAR(GUI_Title_Team): GVAR(GUI_Title_Base) {
			x 					= QUOTE(GRID_OFFSET_COL3);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(9));
			text 				= "Current Team";
		};
		class GVAR(GUI_List_Team): GVAR(GUI_List_Base) {
			idc 				= IDC_Tablet_Main_Team;
			x 					= QUOTE(GRID_OFFSET_COL3);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(10));
			colorBackground[] 	= {0,0,0,0.5};
		};
		
		// MISSION BUTTONS
		/*
		class GVAR(GUI_Button_ORBAT): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_ORBAT;
			x 							= GRID_OFFSET_COL1;
			y 							= CALC_Y(1);
			text 						= "Read ORBAT";
			action 						= QUOTE(call FUNC(openTabletORBAT));
			toolTip 					= "Quickly check the ORBAT";
		};
		class GVAR(GUI_Button_OPORD): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_OPORD;
			x 							= GRID_OFFSET_COL1;
			y 							= CALC_Y(4);
			text 						= "Read OPORD";
			action 						= QUOTE(call FUNC(openTabletOPORD));
			toolTip 					= "Quickly check the OPORD";
		};
		*/

		// Bottom Buttons
		class GVAR(GUI_Button_LoadORBAT): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_LoadORBAT;
			x 							= QUOTE(GRID_OFFSET_COL4);
			y 							= QUOTE(CALC_Y(15));
			text 						= "Load ORBAT";
			colorBackground[] 			= COLOR_BUTTON_LOAD;
			colorBackgroundActive[] 	= COLOR_BUTTON_LOAD;
			colorFocused[] 				= COLOR_BUTTON_LOAD;
			action 						= QUOTE([player] call EFUNC(client,getORBAT));
			toolTip 					= "Get your personal information from the ORBAT; like loadout, callsign and radio frequencies";
		};
		class GVAR(GUI_Button_Admin): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_Admin;
			x 							= QUOTE(GRID_OFFSET_COL3);
			y 							= QUOTE(CALC_Y(15));
			text 						= "Admin";
			colorBackground[] 			= COLOR_BUTTON_ADMIN;
			colorBackgroundActive[] 	= COLOR_BUTTON_ADMIN;
			colorFocused[] 				= COLOR_BUTTON_ADMIN;
			action 						= QUOTE(call FUNC(openTabletAdmin));
			toolTip 					= "Functions only accessable for Admins";
		};
		class GVAR(GUI_Button_Logistics): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_Logistics;
			x 							= QUOTE(GRID_OFFSET_COL2);
			y 							= QUOTE(CALC_Y(15));
			text 						= "Logistics";
			colorBackground[] 			= COLOR_BUTTON_ADMIN;
			colorBackgroundActive[] 	= COLOR_BUTTON_ADMIN;
			colorFocused[] 				= COLOR_BUTTON_ADMIN;
			//action 						= QUOTE(['init'] call FUNC(openTabletLogistics));
			//toolTip 					= "Functions only accessable for Admins";
		};

		// REPORTER CAMERA BUTTON
		class GVAR(GUI_Button_REPORTER): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_Reporter;
			x 							= QUOTE(GRID_OFFSET_COL1);
			y 							= QUOTE(CALC_Y(15));
			text 						= "Reporter";
			action 						= QUOTE(call FUNC(openReporter));
			toolTip 					= "Open Reporter mode (Splendid Camera)";
			colorBackground[] 			= COLOR_BUTTON_REPORTER;
			colorBackgroundActive[] 	= COLOR_BUTTON_REPORTER;
			colorFocused[] 				= COLOR_BUTTON_REPORTER;
		};

		// OOPS BUTTONS
		class GVAR(GUI_Button_GetRadio): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_GetRadio;
			x 							= QUOTE(GRID_OFFSET_COL2);
			y 							= QUOTE(CALC_Y(1));
			text 						= "Get SW Radio";
			action 						= QUOTE([player] call EFUNC(client,getRadio));
			toolTip 					= "Forgot your radio? Grab one here";
		};
		class GVAR(GUI_Button_GetNVG): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_GetNVG;
			x 							= QUOTE(GRID_OFFSET_COL2);
			y 							= QUOTE(CALC_Y(4));
			text 						= "Get NVG's";
			action 						= QUOTE([player] call EFUNC(client,getNVG));
			toolTip 					= "Forgot some NVG's? Grab one here";
		};
		class GVAR(GUI_Button_GetEarplugs): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_GetEarplugs;
			x 							= QUOTE(GRID_OFFSET_COL2);
			y 							= QUOTE(CALC_Y(7));
			text 						= "Get Earplugs";
			action 						= QUOTE([player] call EFUNC(client,getEarplugs));
			toolTip 					= "Forgot some earplugs? Grab one here";
		};
		class GVAR(GUI_Button_GetGPS): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_GetGPS;
			x 							= QUOTE(GRID_OFFSET_COL2);
			y 							= QUOTE(CALC_Y(10));
			text 						= "Get GPS";
			action 						= QUOTE([player] call EFUNC(client,getGPS));
			toolTip 					= "Forgot to bring a GPS? Grab one here";
		};
	};
};