class GVAR(GUI_Control_ORBAT): GVAR(GUI_Control_Base) {
	idc 				= IDC_CONTROL_ORBAT;
	y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 7);
	h 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 14);

	class Controls {
		class GVAR(GUI_ORBAT_TABLE) {
			type 					= CT_CONTROLS_TABLE;
			idc 					= IDC_ORBAT_TABLE;
			x 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			y 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0);
			w 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 23);
			h 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 13.8);
			style 					= 0;

 			firstIDC 				= IDC_ORBAT_TABLE_FIRST;
			lastIDC 				= IDC_ORBAT_TABLE_LAST;

			lineSpacing 			= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.1);
    		rowHeight 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
    		headerHeight 			= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2);

			//-- added to prevent errors, need to see what it does --//
			// Colours which are used for animation (i.e. change of colour) of the selected line.
    		selectedRowColorFrom[]  = {0.7, 0.85, 1, 0.25};
    		selectedRowColorTo[]    = {0.7, 0.85, 1, 0.5};
    		// Length of the animation cycle in seconds.
    		selectedRowAnimLength = 1.2;
			//-- added to prevent errors, need to see what it does --//

			class ScrollBar {
				colorActive[] 				= COLOR_SUBTEXT;
				colorDisabled[] 			= COLOR_TEXT_DISABLED;
				color[] 					= COLOR_SUBTEXT;
				thumb 						= "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowFull 					= "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				arrowEmpty 					= "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				border 						= "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				shadow 						= 0;
			};
			class VScrollbar: ScrollBar {
				width 		= 0.021;
			};
			class HScrollbar: ScrollBar {
				height 		= 0.028;
			};

			// Template for headers (unlike rows, cannot be selected)
			class HeaderTemplate {
				class HeaderBackground {
					controlBaseClassPath[]	= {"RscText"};
					columnX 				= 0;
					columnW 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 22);
					controlOffsetY			= 0;
					controlH 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2);
				};
				// Callsign
				class Column1 {
					controlBaseClassPath[] 	= {"RscText"};
					columnX 				= 0;
					columnW 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 18);
					controlOffsetY			= 0;
				};
				// Team Radio Freq
				class Column2 {
					controlBaseClassPath[] 	= {QGVAR(GUI_Button_Table_Freq)};
					columnX 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 18);
					columnW 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 4);
					controlOffsetY			= 0;
				};
			};

			// Template for selectable rows
    		class RowTemplate {
				class RowBackground {
					controlBaseClassPath[]	= {"RscText"};
					columnX 				= 0;
					columnW 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 22);
					controlOffsetY			= 0;
				};
				// Team Color
				class Column1 {
					controlBaseClassPath[] 	= {"RscText"};
					columnX 				= 0;
					columnW 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.5);
					controlOffsetY			= 0;
				};
				// Rank Image
				class Column2 {
					controlBaseClassPath[] 	= {"RscPictureKeepAspect"};
					columnX 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.5);
					columnW 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2.5);
					controlOffsetY			= 0;
				};
				// Name
				class Column3 {
					controlBaseClassPath[] 	= {"RscText"};
					columnX 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 3);
					columnW 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 9.5);
					controlOffsetY			= 0;
				};
				// Role
				class Column4 {
					controlBaseClassPath[] 	= {"RscText"};
					columnX 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 12.5);
					columnW 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 9.5);
					controlOffsetY			= 0;
				};
			};
		};
	};
};