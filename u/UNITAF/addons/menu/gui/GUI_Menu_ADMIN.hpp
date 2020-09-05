class GVAR(GUI_Control_ADMIN): GVAR(GUI_Control_Base) {
	idc 				= IDC_CONTROL_ADMIN;

	class Controls {
		class GVAR(GUI_ADMIN_Button_releadORBAT): GVAR(GUI_Button_Base) {
			idc 						= IDC_ADMIN_BUTTON_releadORBAT;
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 7);
			text 						= "Reload ORBAT";
			action 						= QUOTE(call FUNC(reloadORBAT));
			toolTip 					= "Reload ORBAT from website";
		};
		class GVAR(GUI_ADMIN_Button_ENDEX): GVAR(GUI_Button_Base) {
			idc 						= IDC_ADMIN_BUTTON_ENDEX;
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 10);
			text 						= "ENDEX";
			action 						= QUOTE(call FUNC(callENDEX));
			toolTip 					= "Disable all AI, heal all players, and show ENDEX screen";
		};
		class GVAR(GUI_ADMIN_Button_ZEUS): GVAR(GUI_Button_Base) {
			idc 						= IDC_ADMIN_BUTTON_ZEUS;
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 13);
			text 						= "Get ZEUS";
			action 						= QUOTE([player] call FUNC(getZeus));
			toolTip 					= "In case of emergencies, get ZEUS access";
		};
	};
};