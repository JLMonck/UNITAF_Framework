#include "base.hpp"

class RscMapControl;

class GVAR(Tablet) {
	idd = IDC_Tablet;
	access = 0;
	onLoad = QUOTE(_this call FUNC(tabletOnLoad));
	onUnload = QUOTE(call FUNC(tabletOnUnload));

	class ControlsBackground {
		class GVAR(Tablet_Background) {
			type				= CT_STATIC;
			idc 				= -1;

			x 					= CALC_X(-5);
			y 					= CALC_Y(-5);
			w 					= CALC_W(50);
			h 					= CALC_H(35);

			style 				= ST_PICTURE + ST_KEEP_ASPECT_RATIO;
			text 				= "\u\UNITAF\addons\tablet\ui\unitab2.paa";
			colorBackground[] 	= {0,0,0,1};
			colorText[] 		= {1,1,1,1};
			font 				= "PuristaLight";
			sizeEx 				= GUI_TEXT_SIZE_MEDIUM;
		};
	};

	class Controls {
		class GVAR(Button_P1): GVAR(Tablet_Side_Button_Base) {
			idc 				= IDC_Tablet_Button_P1;
			y 					= CALC_Y(4.9);
			action 				= QUOTE(call FUNC(openTabletMain));
		};
		class GVAR(Button_P2): GVAR(Tablet_Side_Button_Base) {
			idc 				= IDC_Tablet_Button_P2;
			y 					= CALC_Y(7.1);
			//action 				= "";
		};
		class GVAR(Button_Windows): GVAR(Tablet_Side_Button_Base) {
			idc 				= IDC_Tablet_Button_Windows;
			y 					= CALC_Y(9.25);
			//action 				= QUOTE(call FUNC(openTabletMap));
		};
		class GVAR(Button_Plus): GVAR(Tablet_Side_Button_Base) {
			idc 				= IDC_Tablet_Button_Plus;
			y 					= CALC_Y(11.5);
			//action 				= "";
		};
		class GVAR(Button_Minus): GVAR(Tablet_Side_Button_Base) {
			idc 				= IDC_Tablet_Button_Minus;
			y 					= CALC_Y(13.7);
			//action 				= "";
		};
		class GVAR(Button_Power): GVAR(Tablet_Side_Button_Base) {
			//idc 				= IDC_Tablet_Button_Power;
			idc 				= IDC_CLOSE;
			y 					= CALC_Y(15.8);
			action 				= QUOTE(closeDialog 2);
		};

		#include "Tablet_Welcome.hpp"
		#include "Tablet_Map.hpp"
		#include "Tablet_Main.hpp"
		#include "Tablet_Admin.hpp"
		#include "Tablet_Orbat.hpp"
	};
};