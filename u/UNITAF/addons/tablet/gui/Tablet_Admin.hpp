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