class GVAR(GUI_Control_ORBAT): GVAR(GUI_Control_Base) {
	idc 				= IDC_Tablet_ORBAT;
	GRID_FRAME

	class Controls {
		class GVAR(GUI_ORBAT_TABLE) {
			idc 					= IDC_Tablet_ORBAT_Table;
			type 					= CT_CONTROLS_TABLE;
			style 					= 0;
			x 						= 0;
			y 						= 0;
			w 						= QUOTE(GRID_FRAME_W);
			h 						= QUOTE(GRID_FRAME_H);

 			firstIDC 				= IDC_Tablet_ORBAT_Table_First;
			lastIDC 				= IDC_Tablet_ORBAT_Table_Last;

			lineSpacing 			= QUOTE(GUI_GRID_H * 0.1);
    		rowHeight 				= QUOTE(GUI_GRID_H * 1);
    		headerHeight 			= QUOTE(GUI_GRID_H * 1.2);

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
					columnW 				= QUOTE(CALC_W(28));
					controlOffsetY			= 0;
					controlH 				= QUOTE(GUI_GRID_H * 1.2);
				};
				// Callsign
				class Column1 {
					controlBaseClassPath[] 	= {"RscText"};
					columnX 				= 0;
					columnW 				= QUOTE(CALC_W(24));
					controlOffsetY			= 0;
				};
				// Team Radio Freq
				class Column2 {
					controlBaseClassPath[] 	= {QGVAR(GUI_Button_Table_Freq)};
					columnX 				= QUOTE(CALC_X(24));
					columnW 				= QUOTE(CALC_W(4));
					controlOffsetY			= 0;
				};
			};

			// Template for selectable rows
    		class RowTemplate {
				class RowBackground {
					controlBaseClassPath[]	= {"RscText"};
					columnX 				= QUOTE(CALC_X(1));
					columnW 				= QUOTE(CALC_W(28));
					controlOffsetY			= 0;
				};
				// Team Color
				class Column1 {
					controlBaseClassPath[] 	= {"RscText"};
					columnX 				= QUOTE(CALC_X(1));
					columnW 				= QUOTE(CALC_W(2));
					controlOffsetY			= 0;
				};
				// Rank Image
				class Column2 {
					controlBaseClassPath[] 	= {"RscPictureKeepAspect"};
					columnX 				= QUOTE(CALC_X(3));
					columnW 				= QUOTE(CALC_W(4));
					controlOffsetY			= 0;
				};
				// Name
				class Column3 {
					controlBaseClassPath[] 	= {"RscText"};
					columnX 				= QUOTE(CALC_X(7));
					columnW 				= QUOTE(CALC_W(11));
					controlOffsetY			= 0;
				};
				// Role
				class Column4 {
					controlBaseClassPath[] 	= {"RscText"};
					columnX 				= QUOTE(CALC_X(18));
					columnW 				= QUOTE(CALC_W(11));
					controlOffsetY			= 0;
				};
			};
		};
	};
};
