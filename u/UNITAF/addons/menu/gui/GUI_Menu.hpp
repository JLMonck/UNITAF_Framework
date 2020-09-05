
//#include "script_component.hpp"	// DON'T INCLUDE, ALREADY PART OF config.cpp

class GVAR(GUI_Button_Base) {
	type						= CT_BUTTON;
	idc 						= -1;
	w 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 5);
	h 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
	style 						= ST_CENTER + ST_SINGLE;
	text 						= "";
	borderSize 					= 0;
	default 					= 0;
	
	colorBackground[] 			= COLOR_BUTTON;
	colorBackgroundActive[] 	= COLOR_BUTTON;
	colorFocused[] 				= COLOR_BUTTON;
	colorBackgroundDisabled[] 	= COLOR_BUTTON_DISABLED;

	colorBorder[] 				= {0,0,0,0};
	colorText[] 				= COLOR_TEXT;
	colorDisabled[] 			= COLOR_TEXT;
	colorShadow[] 				= {0,0,0,0};
	
	font 						= "PuristaMedium";
	
	offsetPressedX 				= 0;
	offsetPressedY 				= 0;
	offsetX 					= 0;
	offsetY 					= 0;
	sizeEx 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);

	soundClick[]				= { "\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1.0 };
	soundEnter[] 				= { "\A3\ui_f\data\sound\RscButton\soundEnter", 0.09, 1.0 };
	soundEscape[] 				= { "\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1.0 };
	soundPush[] 				= { "\A3\ui_f\data\sound\RscButton\soundPush", 0.09, 1.0 };

	action 						= "";
};
class GVAR(GUI_Title_Base) {
	type 						= CT_STATIC;
	idc 						= -1;
	w 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 5);
	h 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
	style 						= ST_LEFT + ST_UPPERCASE;
	text 						= "???";
	colorBackground[] 			= {0,0,0,0};
	colorText[] 				= COLOR_TEXT;
	font 						= "PuristaMedium";
	sizeEx 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8);
};
class GVAR(GUI_Text_Base) {
	type 						= CT_STRUCTURED_TEXT;
	idc 						= -1;
	w 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 5);
	h 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
	style						= ST_LEFT;
	text 						= "unknown";
	size 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.75);
	access 						= 0;
	colorBackground[] 			= {0,0,0,0};
	colorText[] 				= COLOR_SUBTEXT;
	font 						= "PuristaLight";
	class Attributes {
		font 						= "PuristaLight";
		color 						= "#3a7085";
		align 						= left;
		size 						= 1;
	};
};
class GVAR(GUI_List_Base) {
	//type 						= CT_LISTBOX;
	type 						= CT_LISTNBOX;
	idc 						= -1;
	w 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 5);
	h 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 5);
	style 						= ST_LEFT + LB_TEXTURES;
	colorBackground[] 			= COLOR_BACKGROUND;
	colorDisabled[] 			= COLOR_BUTTON_DISABLED;
	colorSelect[] 				= {0,0,0,0};
	colorText[] 				= COLOR_SUBTEXT;
	maxHistoryDelay 			= 0;
	font 						= "PuristaLight";
	rowHeight 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.1);
	sizeEx 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8);
	soundSelect[] 				= { "\A3\ui_f\data\sound\RscListbox\soundSelect", 0.09, 1.0 };
	columns[] 					= {0.2, 0.6, 0.2};
	idcLeft 					= -1; 
  	idcRight 					= -1;
	drawSideArrows				= 0;
	class ListScrollBar {
		color[] 					= COLOR_SUBTEXT;
		thumb 						= "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull 					= "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty 					= "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border 						= "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
};

class GVAR(GUI_Control_Base) {
	type = CT_CONTROLS_GROUP;
	idc = -1;
	style = ST_MULTI;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	shadow = 0;

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
		width = 0.021;
	};
	class HScrollbar: ScrollBar {
		height = 0.028;
	};
};

class GVAR(GUI_Button_Table_Freq): GVAR(GUI_Button_Base) {
	x 							= 0;
	y  							= 0;
	w 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
	h 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
	sizeEx 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8);
	colorBackground[] 			= COLOR_SUBTEXT;
	toolTip						= "Set this frequency to Ch. 3";
};

class GVAR(GUI) {
	idd = IDC_Menu;
	access = 0;
	onLoad = QUOTE(_this call FUNC(menuOnLoad));
	onUnload = QUOTE(call FUNC(menuOnUnload));
	
	class ControlsBackground {
		class GVAR(GUI_Background) {
			type				= CT_STATIC;
			idc 				= -1;
			x 					= 0;
			y 					= 0;
			w 					= 1;
			h 					= 1;
			style 				= ST_BACKGROUND;
			text 				= "";
			colorBackground[] 	= COLOR_BACKGROUND;
			colorText[] 		= COLOR_TEXT;
			font 				= "PuristaLight";
			sizeEx 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
		};
		class GVAR(GUI_Title) {
			type 				= CT_STATIC;
			idc 				= -1;
			x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			w 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 10);
			h 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 5);
			style 				= ST_PICTURE + ST_KEEP_ASPECT_RATIO;
			text 				= PATHTOF(ui\UTFN.paa);
			colorBackground[] 	= {0,0,0,0};
			colorText[] 		= COLOR_TEXT;
			font 				= "PuristaSemiBold";
			sizeEx 				= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
		};
	};

	class Controls {
		// CLOSE Button
		class GVAR(GUI_Button_Close): GVAR(GUI_Button_Base) {
			idc 						= IDC_CLOSE;
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 22);
			text 						= "Close";
			colorBackground[] 			= COLOR_BUTTON_CLOSE;
			colorBackgroundActive[]		= COLOR_BUTTON_CLOSE;
			colorFocused[] 				= COLOR_BUTTON_CLOSE;
			action 						= QUOTE(closeDialog 2);
		};
		// BACK Button
		class GVAR(GUI_Button_Back): GVAR(GUI_Button_Base) {
			idc 						= IDC_BACK;
			x 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 19);
			y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 22);
			// y 							= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			text 						= "Back";
			colorBackground[] 			= COLOR_BUTTON_CLOSE;
			colorBackgroundActive[]		= COLOR_BUTTON_CLOSE;
			colorFocused[] 				= COLOR_BUTTON_CLOSE;
			action 						= QUOTE(call FUNC(menuBack));
		};
		
		#include "GUI_Menu_Main.hpp"

		#include "GUI_Menu_OPORD.hpp"

		#include "GUI_Menu_ORBAT.hpp"

		#include "GUI_Menu_ADMIN.hpp"
	};
};