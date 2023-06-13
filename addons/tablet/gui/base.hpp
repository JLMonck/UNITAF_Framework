class GVAR(Tablet_Side_Button_Base) {
	type 						= CT_BUTTON;
	style 						= ST_PICTURE;
	text 						= "";
	
	borderSize					= 0;

	colorText[]					= {0,0,0,0};
	colorDisabled[]				= {0,0,0,0};
	colorFocused[]				= {0,0,0,0};
	colorShadow[] 				= {0,0,0,0};

	colorBackground[] 			= {0,0,0,0};
	colorBackgroundActive[]		= {0,0,0,0};
	colorBackgroundDisabled[]	= {0,0,0,0};

	colorBorder[]				= {0,0,0,0};

	soundEnter[] 				= {"",0.1,1};
	soundPush[] 				= {"",0.1,1};
	soundClick[] 				= {"",0.1,1};
	soundEscape[] 				= {"",0.1,1};

	x 							= QUOTE(CALC_X(36.3));	// 34 + 2.3 ?
	y 							= QUOTE(CALC_Y(5));
	w 							= QUOTE(CALC_W(1));
	h 							= QUOTE(CALC_H(1.2));

	font 						= "PuristaLight";
	sizeEx 						= QUOTE(GUI_TEXT_SIZE_MEDIUM);

	offsetPressedX				= 0;
	offsetPressedY				= 0;
	offsetX 					= 0;
	offsetY 					= 0;
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
	class Controls {};
};

class GVAR(GUI_Button_Base) {
	type						= CT_BUTTON;
	idc 						= -1;
	w 							= QUOTE(GRID_BUTTON_W);
	h 							= QUOTE(GRID_BUTTON_H);
	style 						= QUOTE(ST_CENTER + ST_SINGLE);
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
	sizeEx 						= QUOTE(GUI_TEXT_SIZE_MEDIUM);

	soundClick[]				= { "\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1.0 };
	soundEnter[] 				= { "\A3\ui_f\data\sound\RscButton\soundEnter", 0.09, 1.0 };
	soundEscape[] 				= { "\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1.0 };
	soundPush[] 				= { "\A3\ui_f\data\sound\RscButton\soundPush", 0.09, 1.0 };

	action 						= "";
};
class GVAR(GUI_Title_Base) {
	type 						= CT_STATIC;
	idc 						= -1;
	w 							= QUOTE(GRID_BUTTON_W);
	h 							= QUOTE(CALC_H(1));
	style 						= QUOTE(ST_LEFT + ST_UPPERCASE);
	text 						= "???";
	colorBackground[] 			= {0,0,0,0};
	colorText[] 				= COLOR_TEXT;
	font 						= "PuristaMedium";
	sizeEx 						= QUOTE(GUI_TEXT_SIZE_SMALL);
};
class GVAR(GUI_Text_Base) {
	type 						= CT_STRUCTURED_TEXT;
	idc 						= -1;
	w 							= QUOTE(GRID_BUTTON_W);
	h 							= QUOTE(CALC_H(1));
	style						= ST_LEFT;
	text 						= "unknown";
	size 						= QUOTE(GUI_TEXT_SIZE_SMALL);
	access 						= 0;
	colorBackground[] 			= {0,0,0,0};
	colorText[] 				= COLOR_SUBTEXT;
	font 						= "PuristaLight";
	class Attributes {
		font 						= "PuristaLight";
		color 						= "#3a7085";
		align 						= "left";
		size 						= 1;
	};
};
class GVAR(GUI_List_Base) {
	//type 						= CT_LISTBOX;
	type 						= CT_LISTNBOX;
	idc 						= -1;
	w 							= QUOTE(GRID_BUTTON_W);
	h 							= QUOTE(CALC_H(4));
	style 						= QUOTE(ST_LEFT + LB_TEXTURES);
	colorBackground[] 			= COLOR_BACKGROUND;
	colorDisabled[] 			= COLOR_BUTTON_DISABLED;
	colorSelect[] 				= {0,0,0,0};
	colorText[] 				= COLOR_SUBTEXT;
	maxHistoryDelay 			= 0;
	font 						= "PuristaLight";
	rowHeight 					= QUOTE(GUI_TEXT_SIZE_MEDIUM);
	sizeEx 						= QUOTE(GUI_TEXT_SIZE_SMALL);
	soundSelect[] 				= { "\A3\ui_f\data\sound\RscListbox\soundSelect", 0.09, 1.0 };
	columns[] 					= {0.2, 0.6, 0.2};
	idcLeft 					= -1; 
  	idcRight 					= -1;
	drawSideArrows				= 0;
	class ListScrollBar {
		//color[] 					= COLOR_TEXT;
		thumb 						= "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull 					= "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty 					= "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border 						= "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
	colorPicture[] 				= {1,1,1,1};
	colorPictureSelected[] 		= {1,1,1,1};
	colorPictureDisabled[] 		= {1,1,1,1};
};
class GVAR(GUI_Button_Table_Freq): GVAR(GUI_Button_Base) {
	x 							= 0;
	y  							= 0;
	w 							= QUOTE(CALC_W(2));
	h 							= QUOTE(CALC_H(1));
	sizeEx 						= QUOTE(GUI_GRID_H * 0.8);
	colorBackground[] 			= COLOR_SUBTEXT;
	toolTip						= "Set this frequency to Ch. 3";
};

class GVAR(GUI_Combo_Base) {
	deletable					= 0;
	fade						= 0;
	access 						= 0;
	type 						= CT_COMBO;
	colorSelect[] 				= {0,0,0,1};
	colorText[] 				= {1,1,1,1};
	colorBackground[] 			= {0,0,0,1};
	colorScrollbar[] 			= {1,0,0,1};
	colorDisabled[] 			= {1,1,1,0.25};
	colorPicture[] 				= {1,1,1,1};
	colorPictureSelected[] 		= {1,1,1,1};
	colorPictureDisabled[] 		= {1,1,1,0.25};
	colorPictureRight[] 		= {1,1,1,1};
	colorPictureRightSelected[] = {1,1,1,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	colorTextRight[] 			= {1,1,1,1};
	colorSelectRight[] 			= {0,0,0,1};
	colorSelect2Right[] 		= {0,0,0,1};
	tooltipColorText[] 			= {1,1,1,1};
	tooltipColorBox[] 			= {1,1,1,1};
	tooltipColorShade[] 		= {0,0,0,0.65};
	soundSelect[] 				= {};
	soundExpand[] 				= {};
	soundCollapse[] 			= {};
	maxHistoryDelay 			= 1;
	class ComboScrollBar {
		color[] 					= COLOR_SUBTEXT;
	};
	style 						= QUOTE(ST_MULTI + ST_NO_RECT);
	font 						= "RobotoCondensed";
	sizeEx 						= QUOTE(GUI_TEXT_SIZE_SMALL);
	shadow 						= 0;
	x 							= 0;
	y 							= 0;
	w 							= QUOTE(GRID_BUTTON_W);
	h 							= QUOTE(GRID_BUTTON_H);
	colorSelectBackground[] 	= {1,1,1,0.7};
	arrowEmpty 					= "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
	arrowFull 					= "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
	wholeHeight 				= QUOTE(GRID_BUTTON_H * 5);
	colorActive[] 				= {1,0,0,1};
};