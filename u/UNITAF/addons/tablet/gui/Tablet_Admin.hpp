class GVAR(GUI_Control_ADMIN): GVAR(GUI_Control_Base) {
	idc 				= IDC_Tablet_Admin;
	GRID_FRAME

	class Controls {
		class GVAR(GUI_ADMIN_Button_releadORBAT): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Admin_Button_releadORBAT;
			x 							= GRID_OFFSET_COL1;
			y 							= CALC_Y(1);
			text 						= "Reload ORBAT";
			action 						= QUOTE(call FUNC(reloadORBAT));
			toolTip 					= "Reload ORBAT from website";
		};
		class GVAR(GUI_ADMIN_Button_ENDEX): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Admin_Button_ENDEX;
			x 							= GRID_OFFSET_COL1;
			y 							= CALC_Y(4);
			text 						= "ENDEX";
			action 						= QUOTE(call FUNC(callENDEX));
			toolTip 					= "Disable all AI, heal all players, and show ENDEX screen";
		};

		class GVAR(GUI_ADMIN_Button_ZEUS): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Admin_Button_Zeus;
			x 							= GRID_OFFSET_COL1;
			y 							= CALC_Y(7);
			text 						= "Get ZEUS";
			action 						= QUOTE([player] call FUNC(getZeus));
			toolTip 					= "In case of emergencies, get ZEUS access";
		};
		class GVAR(GUI_ADMIN_Button_ARSENAL): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Admin_Button_Arsenal;
			x 							= GRID_OFFSET_COL1;
			y 							= CALC_Y(10);
			text 						= "Open Arsenal";
			action 						= QUOTE([player] call FUNC(openArsenal));
			toolTip 					= "In case of emergencies, open Full Arsenal";
		};

		// Local FPS
		class GVAR(GUI_ADMIN_FPS_Local): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Admin_FPS_local;
			x 					= GRID_OFFSET_COL3;
			w 					= GRID_BUTTON_WIDE_W;
			y 					= CALC_Y(1);
			colorBackground[] 	= {0,0,0,0.5};
			text 				= "";
		};
		// Server FPS / Groups / Units
		class GVAR(GUI_ADMIN_FPS_Server): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Admin_FPS_Server;
			x 					= GRID_OFFSET_COL3;
			w 					= GRID_BUTTON_WIDE_W;
			y 					= CALC_Y(2);
			colorBackground[] 	= {0,0,0,0.5};
			text 				= "";
		};
		// HC FPS / Groups / Units
		class GVAR(GUI_ADMIN_FPS_HC1): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Admin_FPS_HC1;
			x 					= GRID_OFFSET_COL3;
			w 					= GRID_BUTTON_WIDE_W;
			y 					= CALC_Y(3);
			colorBackground[] 	= {0,0,0,0.5};
			text 				= "";
		};
		class GVAR(GUI_ADMIN_FPS_HC2): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Admin_FPS_HC2;
			x 					= GRID_OFFSET_COL3;
			w 					= GRID_BUTTON_WIDE_W;
			y 					= CALC_Y(4);
			colorBackground[] 	= {0,0,0,0.5};
			text 				= "";
		};
		class GVAR(GUI_ADMIN_FPS_HC3): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Admin_FPS_HC3;
			x 					= GRID_OFFSET_COL3;
			w 					= GRID_BUTTON_WIDE_W;
			y 					= CALC_Y(5);
			colorBackground[] 	= {0,0,0,0.5};
			text 				= "";
		};
		class GVAR(GUI_ADMIN_FPS_HC4): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Admin_FPS_HC4;
			x 					= GRID_OFFSET_COL3;
			w 					= GRID_BUTTON_WIDE_W;
			y 					= CALC_Y(6);
			colorBackground[] 	= {0,0,0,0.5};
			text 				= "";
		};
		class GVAR(GUI_ADMIN_FPS_HC5): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Admin_FPS_HC5;
			x 					= GRID_OFFSET_COL3;
			w 					= GRID_BUTTON_WIDE_W;
			y 					= CALC_Y(7);
			colorBackground[] 	= {0,0,0,0.5};
			text 				= "";
		};
		class GVAR(GUI_ADMIN_FPS_HC6): GVAR(GUI_Text_Base) {
			idc 				= IDC_Tablet_Admin_FPS_HC6;
			x 					= GRID_OFFSET_COL3;
			w 					= GRID_BUTTON_WIDE_W;
			y 					= CALC_Y(8);
			colorBackground[] 	= {0,0,0,0.5};
			text 				= "";
		};

		// Back Button
		class GVAR(GUI_ADMIN_Button_BACK): GVAR(GUI_Button_Base) {
			idc 						= IDC_Tablet_Main_Button_ORBAT;
			x 							= GRID_OFFSET_COL4;
			y 							= CALC_Y(15);
			text 						= "Back";
			colorBackground[] 			= COLOR_BUTTON_CLOSE;
			colorBackgroundActive[]		= COLOR_BUTTON_CLOSE;
			colorBackgroundDisabled[]	= COLOR_BUTTON_CLOSE;
			action 						= QUOTE(call FUNC(openTabletMain));
		};
	};
};