class GVAR(GUI_Control_Logistics): GVAR(GUI_Control_Base) {
	idc 				= IDC_Tablet_Logistics;
	GRID_FRAME

	class Controls {
		class GVAR(GUI_Logistics_Title_Type): GVAR(GUI_Title_Base) {
			x 					= QUOTE(GRID_OFFSET_COL1);
			y 					= QUOTE(CALC_Y(1));
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			text 				= "Type";
		};
		class GVAR(GUI_Logistics_Combo_Type): GVAR(GUI_Combo_Base) {
			idc 				= IDC_Tablet_Logistics_Combo_Type;
			x 					= QUOTE(GRID_OFFSET_COL1);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(2));
		};

		class GVAR(GUI_Logistics_Title_Preset): GVAR(GUI_Title_Base) {
			x 					= QUOTE(GRID_OFFSET_COL1);
			y 					= QUOTE(CALC_Y(4));
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			text 				= "Preset";
		};
		class GVAR(GUI_Logistics_Combo_Preset): GVAR(GUI_Combo_Base) {
			idc 				= IDC_Tablet_Logistics_Combo_Preset;
			x 					= QUOTE(GRID_OFFSET_COL1);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(5));
		};
		class GVAR(GUI_Logistics_Title_Container): GVAR(GUI_Title_Base) {
			x 					= QUOTE(GRID_OFFSET_COL1);
			y 					= QUOTE(CALC_Y(7));
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			text 				= "Container";
		};
		class GVAR(GUI_Logistics_Combo_Container): GVAR(GUI_Combo_Base) {
			idc 				= IDC_Tablet_Logistics_Combo_Container;
			x 					= QUOTE(GRID_OFFSET_COL1);
			w 					= QUOTE(GRID_BUTTON_WIDE_W);
			y 					= QUOTE(CALC_Y(8));
		};

		class GVAR(GUI_Logistics_PreviewBackground) {
			x 					= QUOTE(GRID_OFFSET_COL3);
			y 					= QUOTE(CALC_Y(1));
			w 					= QUOTE(GRID_BUTTON_DOUBLE_W);
			h 					= QUOTE(CALC_H(6));
			colorBackground[] 	= COLOR_BACKGROUND;
			idc 				= -1;
			style 				= ST_CENTER;
			colorText[] 		= COLOR_TEXT;
			type 				= CT_STATIC;
			font 				= "PuristaLight";
			sizeEx 				= QUOTE(GUI_TEXT_SIZE_SMALL);
			text 				= "";
		};
		class GVAR(GUI_Logistics_Preview): GVAR(GUI_List_Base) {
			idc 				= IDC_Tablet_Logistics_Preview;
			x 					= QUOTE(GRID_OFFSET_COL3);
			y 					= QUOTE(CALC_Y(1));
			w 					= QUOTE(GRID_BUTTON_DOUBLE_W);
			h 					= QUOTE(CALC_H(6));
			disableOverflow 	= 1;
            columns[] 			= {0.05, 0.15, 0.85};
	};



		// Back Button
		class GVAR(GUI_ADMIN_Button_BACK): GVAR(GUI_Button_Base) {
			x 							= QUOTE(GRID_OFFSET_COL4);
			y 							= QUOTE(CALC_Y(15));
			text 						= "Back";
			colorBackground[] 			= COLOR_BUTTON_CLOSE;
			colorBackgroundActive[]		= COLOR_BUTTON_CLOSE;
			colorBackgroundDisabled[]	= COLOR_BUTTON_CLOSE;
			action 						= QUOTE(call FUNC(openTabletMain));
		};

        class GVAR(GUI_Button_EditInventory): GVAR(GUI_Button_Base) {
			x 							= QUOTE(GRID_OFFSET_COL4);
			y 							= QUOTE(CALC_Y(13));
			text 						= "Edit";
			colorBackground[] 			= COLOR_BUTTON_LOAD;
			colorBackgroundActive[] 	= COLOR_BUTTON_LOAD;
			colorFocused[] 				= COLOR_BUTTON_LOAD;
			action 						= QUOTE(call FUNC(logisticsConfigure));
			toolTip 					= "Edit Inventory";
		};
    };
};