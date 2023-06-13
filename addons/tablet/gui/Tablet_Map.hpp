class GVAR(GUI_Control_Map): GVAR(GUI_Control_Base) {
	idc 				= IDC_Tablet_Map;
	GRID_FRAME

	class ControlsBackground {
/*
		class GVAR(Map): RscMapControl {
			idc 				= IDC_Tablet_Map_Control;
			type 				= CT_MAP_MAIN;
			style 				= ST_PICTURE;
			
			GRID_FRAME
		};
		* /
		class GVAR(MapFlat): RscMapControl {
			idc 				= IDC_Tablet_MapFlat_Control;
			type 				= CT_MAP_MAIN;
			style 				= ST_PICTURE;

			x 					= 0;		//CALC_X(10.1);
			y 					= 0; 		//CALC_Y(3.8);
			w 					= GRID_FRAME_W;
			h 					= GRID_FRAME_H; 		//CALC_H(17.6);

			maxSatelliteAlpha	= 0;
			alphaFadeStartScale	= 0;
			alphaFadeEndScale	= 0;

/*
			onMouseButtonDown = "";
			onMouseButtonUp = "";
			onMouseButtonClick = "";
			onMouseButtonDblClick = "";
			onMouseMoving = "";
			onMouseHolding = "";

			onSetFocus = "";
			onKillFocus = "";
			onMouseEnter = "";
			onMouseExit = "";
*/
			//onMouseMoving = "cTabCursorOnMap = _this select 3; cTabMapCursorPos = _this select 0 ctrlMapScreenToWorld [_this select 1, _this select 2];";
			//onMouseMoving = QUOTE(_this call FUNC(tabletMap_onMouseMoving));
		//};
	};

	class Controls {
		class GVAR(MapInfo_Background) {
			idc 				= -1;
			type				= CT_STATIC;
			style 				= ST_BACKGROUND;
			colorBackground[] 	= {0,0,0,1};
			colorText[] 		= {1,1,1,1};
			font 				= "TahomaB";
			sizeEx 				= QUOTE(GUI_TEXT_SIZE_MEDIUM);
  			text 				= "";

			x 					= 0;
			y 					= 0;
			w 					= QUOTE(CALC_W(4));
			h 					= QUOTE(GRID_FRAME_H);
		};
		class GVAR(MapInfo_Current): GVAR(GUI_Text_Base) {
			idc 				= -1;
			
			x 					= 0;
			y 					= 0;
			w 					= QUOTE(CALC_W(4));
			h 					= QUOTE(CALC_H(1));

			sizeEx				= QUOTE(GUI_TEXT_SIZE_SMALL);
			text 				= "Current Pos:";
			colorBackground[]	= {0,0,0,0};
			colorText[]			= {1,1,1,1};
		};
		class GVAR(MapInfo_time): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Time;
			y 					= QUOTE(0 + CALC_Y(1));
			text 				= "";
		};
		class GVAR(MapInfo_dirDegree): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Degree;
			y 					= QUOTE(0 + CALC_Y(2));
			text 				= "";
		};
		class GVAR(MapInfo_grid): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Grid;
			y 					= QUOTE(0 + CALC_Y(3));
			text 				= "";
		};
		class GVAR(MapInfo_dirOctant): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Octant;
			y 					= QUOTE(0 + CALC_Y(4));
			text 				= "";
		};
		class GVAR(MapInfo_elevation): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Elevation;
			y 					= QUOTE(0 + CALC_Y(5));
			text 				= "";
		};

		class GVAR(MapInfo_Pointer): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Elevation;
			y 					= QUOTE(0 + CALC_Y(7));
			text 				= "Pointer Pos:";
		};
		class GVAR(MapInfo_hookGrid): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_HookGrid;
			y 					= QUOTE(0 + CALC_Y(8));
			text 				= "";
		};
		class GVAR(MapInfo_hookElevation): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_hookElevation;
			y 					= QUOTE(0 + CALC_Y(9));
			text 				= "";
		};
		class GVAR(MapInfo_hookDst): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_HookDst;
			y 					= QUOTE(0 + CALC_Y(10));
			text 				= "";
		};
		class GVAR(MapInfo_hookDir): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_HookDir;
			y 					= QUOTE(0 + CALC_Y(11));
			text 				= "";
		};
	};
};