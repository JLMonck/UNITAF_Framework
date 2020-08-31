
//#include "script_component.hpp"	// DON'T INCLUDE, ALREADY PART OF config.cpp
#include "defines.inc"

class GVAR(GUI_Button_Base) {
	type = 1;
	w = safeZoneW * 0.10468522;
	h = safeZoneH * 0.05598959;
	style = ST_CENTER + ST_SINGLE;
	text = "Button";
	borderSize = 0;
	
	colorBackground[] = COLOR_BUTTON;
	colorBackgroundActive[] = COLOR_BUTTON;
	colorFocused[] = COLOR_BUTTON;
	colorBackgroundDisabled[] = COLOR_BUTTON_DISABLED;

	colorBorder[] = {0,0,0,0};
	colorText[] = COLOR_TEXT;
	colorDisabled[] = COLOR_TEXT;
	colorShadow[] = {0,0,0,0};
	
	font = "PuristaMedium";
	
	offsetPressedX = 0;
	offsetPressedY = 0;
	offsetX = 0;
	offsetY = 0;
	sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);

	soundEnter[] = {"",0.1,1};
	soundPush[] = {"",0.1,1};
	soundClick[] = {"",0.1,1};
	soundEscape[] = {"",0.1,1};

	action = "";
	default = false;
};

class GVAR(GUI) {
	idd = IDC_Menu;
	access = 0;
	onLoad = QUOTE(_this call FUNC(menuOnLoad));
	
	class ControlsBackground {
		class GVAR(GUI_Background) {
			type = CT_STATIC;
			idc = -1;
			x = safeZoneX + safeZoneW * 0.23792094;
			y = safeZoneY + safeZoneH * 0.14973959;
			w = safeZoneW * 0.52415813;
			h = safeZoneH * 0.69921875;
			style = ST_SHADOW;
			text = "";
			colorBackground[] = COLOR_BACKGROUND;
			colorText[] = COLOR_TEXT;
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
		};
		class GVAR(GUI_Title) {
			type = CT_STATIC;
			idc = -1;
			x = 0;
			y = 0;
			w = 1;
			h = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
			style = ST_CENTER;
			text = "UNITAF Menu";
			colorBackground[] = {0,0,0,0};
			colorText[] = COLOR_TEXT;
			font = "PuristaSemiBold";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
		};
	};

	class Controls {
		class GVAR(GUI_Button_Close): GVAR(GUI_Button_Base) {
			idc = IDC_CANCEL;
			x = safeZoneX + safeZoneW * 0.63616399;
			y = safeZoneY + safeZoneH * 0.76822917;
			text = "Close";
			colorBackground[] = COLOR_BUTTON_CLOSE;
			colorBackgroundActive[] = COLOR_BUTTON_CLOSE;
			colorFocused[] = COLOR_BUTTON_CLOSE;
		};
		class GVAR(GUI_Button_LoadORBAT): GVAR(GUI_Button_Base) {
			idc = IDC_LoadORBAT;
			x = safeZoneX + safeZoneW * 0.63616399;
			y = safeZoneY + safeZoneH * 0.61979167;
			text = "Load ORBAT Data";
			colorBackground[] = COLOR_BUTTON_LOAD;
			colorBackgroundActive[] = COLOR_BUTTON_LOAD;
			colorFocused[] = COLOR_BUTTON_LOAD;
			action = QUOTE([player] call EFUNC(client,getORBAT));
		};

		class GVAR(GUI_Button_GetRadio): GVAR(GUI_Button_Base) {
			idc = -1;
			x = safeZoneX + safeZoneW * 0.26281113;
			y = safeZoneY + safeZoneH * 0.69401042;
			text = "Get SW Radio";
			action = QUOTE([player] call EFUNC(client,getRadio));
		};
		class GVAR(GUI_Button_GetNVG): GVAR(GUI_Button_Base) {
			idc = -1;
			x = safeZoneX + safeZoneW * 0.26281113;
			y = safeZoneY + safeZoneH * 0.76822917;
			text = "Get NVG's";
			action = QUOTE([player] call EFUNC(client,getNVG));
		};
		class GVAR(GUI_Button_GetEarplugs): GVAR(GUI_Button_Base) {
			idc = -1;
			x = safeZoneX + safeZoneW * 0.26281113;
			y = safeZoneY + safeZoneH * 0.61979167;
			text = "Get Earplugs";
			action = QUOTE([player] call EFUNC(client,getEarplugs));
		};
	};
};
